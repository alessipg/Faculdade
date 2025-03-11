%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
%}

%union {
    struct ast *a;
    double number;
}

%token <number> NUMBER
%token EOL

%type <a> exp factor term;

%%
calclist:
    | calclist exp EOL {
        printf(" = %4.4g\n", eval($2)); /*avalia e imprime a AST*/
        freeTree($2);
        printf("> ");
    }
    | calclist EOL { printf("> "); }
    ;

exp: factor
    | exp '+' factor { $$ = newAST('+',$1,$3); }
    | exp '-' factor { $$ = newAST('-',$1,$3); }
    ;

factor: term
    | factor '*' term { $$ = newAST('*',$1,$3); }
    | factor '/' term { $$ = newAST('/', $1, $3); }
    ;

term: NUMBER { $$ = newNum($1); }
    | '(' exp ')' { $$ = $2; }
    ;
%%