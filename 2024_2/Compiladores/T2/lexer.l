%option noyywrap nodefault yylineno
%{
#include "conversor.h"
#include "parser.tab.h" // Cabeçalho gerado pelo Bison
#include <string.h>     // Para strdup
#include <stdlib.h>
#include <stdio.h> 
%}

%%

"\"agentCode\""         { return AGENTCODE; }
"\"beliefs\""           { return BELIEFS; }
"\"goal\""              { return GOAL; }
"\"plans\""             { return PLANS; }
"\"trigger\""           { return TRIGGER; }
"\"ctx\""               { return CTX; }
"\"body\""              { return BODY; }
"\"name\""              { return NAME; }

"{"                     { return '{'; }
"}"                     { return '}'; }
"["                     { return '['; }
"]"                     { return ']'; }
":"                     { return ':'; }
","                     { return ','; }

\"A_([^\"]*)\"     { yylval.s = strndup(yytext + 3, yyleng - 4); printf("Token: P_ACTION (%s)\n", yylval.s); return P_ACTION; }
\"B_([^\"]*)\"     { yylval.s = strndup(yytext + 3, yyleng - 4); printf("Token: P_BELIEF (%s)\n", yylval.s); return P_BELIEF; }
\"G_([^\"]*)\"     { yylval.s = strndup(yytext + 3, yyleng - 4); printf("Token: P_GOAL (%s)\n", yylval.s); return P_GOAL; }
\"[^\"]*\"              { yylval.s = strndup(yytext + 1, yyleng - 2); printf("Token: STRING (%s)\n", yylval.s); return STRING; }
[ \t]+                  ; 
\n                      ;
.                       { printf("Unexpected character: %c\n", yytext[0]); return yytext[0]; }


%%
