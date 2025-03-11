%{
#include <stdio.h>
%}

keywords        ("auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while")
identificator   [a-zA-Z_][a-zA-Z0-9_]*

%%

{keywords}          { printf("Palavra reservada: %s\n", yytext); }
{identificator}     { printf("identificator: %s\n", yytext); }
.                   { printf("outro: %s\n", yytext); } 

%%

int main(int nArgs, char *szArgs[]) {
    yylex();
    return 0;
}
