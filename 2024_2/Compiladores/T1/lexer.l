%option noyywrap nodefault yylineno
%{
    #include "basicLang.h"
    #include "parser.tab.h"    
%}

EXP ([Ee][+-]?[0-9]+)

%%
"+" |
"-" |
"*" |
"/" |
"=" |
"," |
";" |
"(" |
")"     { return yytext[0]; }

">"     { yylval.fn = 1; return CMP; }
"<"     { yylval.fn = 2; return CMP; }
"<>"    { yylval.fn = 3; return CMP; }
"=="    { yylval.fn = 4; return CMP; }
">="    { yylval.fn = 5; return CMP; }
"<="    { yylval.fn = 6; return CMP; }

"&&"    { yylval.fn = 'A'; return LOGOP; }
"||"    { yylval.fn = 'O'; return LOGOP; }

"if"    { return IF; }
"then"  { return THEN; }
"else"  { return ELSE; }
"while" { return WHILE; }
"do"    { return DO; }
"for"   { return FOR; }
"let"   { return LET; }

"sqrt"  { yylval.fn = B_sqrt; return FUNC; }
"exp"   { yylval.fn = B_exp; return FUNC; }
"log"   { yylval.fn = B_log; return FUNC; }
"print" { yylval.fn = B_print; return FUNC; }

[a-zA-Z][a-zA-Z0-9]*    { yylval.s = lookup(yytext); return NAME; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}?        { yylval.d = atof(yytext); return NUMBER; }

"//".*
[ \t]

\\\n    { printf("c> "); }

\n      { return EOL; }

.       { yyerror("Caracter desconhecido %c\n", *yytext); }
%%