/*interface com o lexer*/
extern int yylineno;
void yyerror (char *s, ...);
/*nos AST*/
typedef struct ast{
    int nodetype;
    struct ast *l;
    struct ast *r;
}ast;

typedef struct numval{
    int nodetype;
    double number;
}numval;

ast *newAST(int nodetype, ast *l, ast *r);
ast *newNum(double number);

double eval(ast *);

void freeTree(ast *);