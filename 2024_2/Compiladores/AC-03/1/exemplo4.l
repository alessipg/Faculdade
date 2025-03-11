%{
    /*Escaneamento e reconhecimento de tags*/
    
    int linhas = 0, qtdTags = 0;

%}

TAG         \<(.)*\>
WHITESPACE  [\ \t]
LINHA       [\n]
lett1       [a-z]+
lett2       [A-Z]+
word        [A-Z][a-z]+

%%

{lett1}         { printf("min: %s\n", yytext); }
{lett2}         { printf("mai: %s\n", yytext); }
{word}          { printf("word: %s\n", yytext); }
{TAG}           { qtdTags++; printf("Tag: %s\n", yytext); }
{LINHA}         { linhas++; }
{WHITESPACE}    ;
.               ;

%%

int main (int nArgs, char* szArgs[]){
    yylex();
    printf("\nTotal de linhas processadas: %d\n", linhas);
    printf("\nQuantidade de tags reconhecidas: %d\n", qtdTags);
    return 0;
}