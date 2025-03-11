%{

%}

DIGITO [0-9]
ORAL   "."

%%
{DIGITO}    { printf("Digito: %s\n", yytext); }
{ORAL}    { printf("Eita: %s\n", yytext); }

.           { printf("Nao reconhecido: %s\n", yytext); }
%%

int main(int nArgs, char *szArgs[]) {
    yylex();
    return 0;
}