%{
    /*Reconhecimento de contagem de novas linhas, caracteres
    e tabulações*/
    int linhas = 0, caracteres = 0, tabs = 0;
%}

NOVALINHA   [\n]+
TAB         [\t]

%%

{NOVALINHA}     { ++linhas; ++caracteres; }
{TAB}           { ++tabs; }
.               { ++caracteres; }

%%

int main ( int nArgs, char *szArgs[]){
    yylex();
    printf("Numero de linhas: %d\n", linhas);
    printf("Numero de tabulacoes: %d\n", tabs);
    printf("Numero de caracteres: %d\n", caracteres);
    return 0;
}