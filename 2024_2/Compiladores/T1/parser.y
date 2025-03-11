%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "basicLang.h"
%}

%union{
    ast *a;
    double d;
    symbol *s;
    symList *sl;
    int fn;
}

%token <d> NUMBER
%token <s> NAME
%token <fn> FUNC
%token EOL

%token IF THEN ELSE WHILE DO LET FOR LOGOP

%right '='
%left <fn> LOGOP 
%nonassoc <fn> CMP
%left '+' '-'
%left '*' '/'

%type <a> exp stmt list explist
%type <sl> symlist

%start calclist

%%
stmt: IF exp THEN list  { $$ = newFlow('I', $2, $4, NULL, NULL); }
    | IF exp THEN list ELSE list  { $$ = newFlow('I', $2, $4, $6, NULL); }
    | WHILE exp DO list  { $$ = newFlow('W', $2, $4, NULL, NULL); }
    | FOR '('exp';'exp';'exp')' list { $$ = newFlow('R', $5, $9, $3, $7); }
    | exp
    ;

list:               { $$ = NULL;}
    | stmt ';' list { if ($3 == NULL)
            $$ = $1;
        else
            $$ = newAst('L',$1, $3); }
    ;

exp: exp LOGOP exp { $$ = newLogOp($2, $1, $3); }
    | exp CMP exp    { $$ = newCmp($2,$1,$3); }
    | exp '+' exp   { $$ = newAst('+',$1, $3); }
    | exp '-' exp   { $$ = newAst('-',$1, $3); }
    | exp '*' exp   { $$ = newAst('*',$1, $3); }
    | exp '/' exp   { $$ = newAst('/', $1, $3); }
    | '(' exp ')'   { $$ = $2; }
    | NUMBER        { $$ = newNum($1); }
    | NAME          { $$ = newRef($1); }
    | NAME '=' exp  { $$ = newAssign($1, $3); }
    | FUNC '(' explist ')' { $$ = newFunc($1, $3); }
    | NAME '(' explist ')' { $$ = newCall($1, $3); }
    ;

explist: exp
    | exp ',' explist  { $$ = newAst('L', $1, $3); }
    ;

symlist: NAME { $$ = newSymList($1, NULL); }
    | NAME ',' symlist { $$ = newSymList($1, $3); }
    ;

calclist:
    | calclist stmt EOL {
        printf(" = %4.4g\n> ", eval($2));
        freeTree($2);
    }
    | calclist LET NAME '(' symlist ')' '=' list EOL {
        doDef($3, $5, $8);
        printf("Defined %s\n>", $3->name); }
    | calclist error EOL { yyerrok; printf("> "); }
%%
