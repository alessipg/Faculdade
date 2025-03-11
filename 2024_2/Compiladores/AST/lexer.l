%option noyywrap nodefault yylineno
%{
    #include "ast.h"
    #include "parser.tab.h"
%}

EXP ([Ee][+-]?[0-9]+)

%%
"+" |
"-" |
"*" |
"/" |
"(" |
")" { return yytext[0]; }
[0-9]+"."[0-9]*{EXP}?   |
"."?[0-9]+{EXP}?    { yylval.number = atof(yytext); return NUMBER; }

\n  { return EOL; }
"//".*
[ \t] { /*ignora espaco em branco*/ }
.   { yyerror("Caracter nao reconhecido: %c\n", *yytext); }
%%