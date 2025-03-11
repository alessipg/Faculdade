#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"

ast *newAST(int nodetype, ast *l, ast *r){
    ast *a = malloc(sizeof(ast));
    if (!a) {
        yyerror("Sem espaco");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

ast *newNum(double number){
    numval *a = malloc(sizeof(numval));
    if (!a) {
        yyerror("Sem espaco");
        exit(0);
    }
    a->nodetype = 'K';
    a->number = number;
    return (ast *)a;
}

double eval(ast *a){
    double v;
    switch (a->nodetype) {
        case 'K': v = ((numval *)a)->number; break;
        case '+': v = eval(a->l) + eval(a->r); break;
        case '-': v = eval(a->l) - eval(a->r); break;
        case '*': v = eval(a->l) * eval(a->r); break;
        case '/': v = eval(a->l) / eval(a->r); break;
        default: yyerror("erro interno: bad node %c\n", a->nodetype);
    }
    return v;
}
void freeTree(ast *a){
    switch(a->nodetype){
        case '+':
        case '-':
        case '*':
        case '/':
            freeTree(a->l);
            freeTree(a->r);
        case 'K':
           free(a);
           break;
        default: printf("erro interno: bad node %c\n", a->nodetype);
    }
}

void yyerror(char *s, ...) {
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "Erro na linha %d: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main(){
    printf("> ");
    return yyparse();
}