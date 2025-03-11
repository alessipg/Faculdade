%{
#include<stdio.h>
%}

%token NUMBER
%token ADD SUB MUL DIV
%token OP CP
%token EOL

%%

calclist: /*palavra vazia*/
    | calclist exp EOL { printf(" = %d\n", $2);}
    ;

exp: factor /* default $$ = $1 */
    | exp ADD factor { $$ = $1 + $3; }
    | exp SUB factor { $$ = $1 - $3; }
    ;

factor: term 
    | factor MUL term { $$ = $1 * $3; }
    | factor DIV term { $$ = $1 / $3; }
    ;

term: NUMBER
    | OP exp CP { $$ = $2; }

%%
int main(int argc, char **argv){
    yyparse();
}

int yyerror(char *s){
    fprintf(stderr, "error: %s\n", s);
    return -1;
}
