%{
#include "calculadora.tab.h"
%}
%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"("     { return OP; }
")"     { return CP; }
"//".*  /*ignora*/
\n      { return EOL; }
[ \t]   { /*ignora espaco em branco*/ }
.       { printf("Nao reconhecido: %c\n", *yytext); }
%%