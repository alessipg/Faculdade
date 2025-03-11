%{
#include <stdio.h>
int qtdLinhas = 0;
%}

keywords        ("auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while")
identificator   [a-zA-Z_][a-zA-Z0-9_]*
hexa            0x[a-fA-F0-9]+
oct             0[0-7]+
dec             [0-9]+
constrealnum    {dec}|"."{dec}|{dec}"."{dec}*|{dec}?e[+-]?{dec}([lL]|[fF])?
unsignedint     {dec}[uU]
longint         {dec}[lL]
conststring     \"([^"\\]|\\.)*\"
escape          \\([abfnrtv\\?'"]|[0-7]{1,3}|x[a-fA-F0-9]+)
separators      [\(\)\[\]\{\};,".":]
operators       ("+"|"-"|"*"|"/"|"%"|"++"|"--"|"="|"+="|"-="|"*="|"/="|"%="|"=="|"!="|"<"|"<="|">"|">="|"&&"|"|"|"!"|"&"|"|"|"^"|"<<"|">>"|"?"|":"|","|";")
space           " "
novalinha       [\n]                 
include         "#include "\"([^"]*)\"|"#include "\<([^>]*)\>
define          "#define "[ \t]*([_a-zA-Z][_a-zA-Z0-9]*)[ \t]+(.*)
comentario      "//".*
comentariobloco "/*"([^*]|\*+[^*/])*\*+"/"
%%

{include}           { printf("include: %s\n", yytext); }
{keywords}          { printf("Palavra reservada: %s\n", yytext); }
{identificator}     { printf("identificator: %s\n", yytext); }
{hexa}              { printf("hexa: %s\n", yytext); }
{oct}               { printf("octal: %s\n", yytext); }
{dec}               { printf("decimal: %s\n", yytext); }
{constrealnum}      { printf("numero real: %s\n", yytext); }
{unsignedint}       { printf("unsigned int: %s\n", yytext); }
{longint}           { printf("long int: %s\n", yytext); }
{conststring}       { printf("string: %s\n", yytext); }
{escape}            { printf("escape: %s\n", yytext); }
{separators}        { printf("separadores: %s\n", yytext); }
{operators}         { printf("operadores: %s\n", yytext); }
{define}            { printf("define: %s\n", yytext); }
{space}             { printf("espaco\n"); }
{comentario}        { printf("comentario: %s\n", yytext); } 
{comentariobloco}   { printf("comentario em bloco: %s\n", yytext); } 
{novalinha}         { qtdLinhas++; }
.                   { printf("outro: %s\n", yytext); } 

%%

int main(int nArgs, char *szArgs[]) {
    if(nArgs>1){
        if(!(yyin = fopen(szArgs[1], "r"))){
            perror(szArgs[1]);
            return(1);
        }
    }
    yylex();
    printf("linhas processadas: %d\n",qtdLinhas);
    return 0;
}
