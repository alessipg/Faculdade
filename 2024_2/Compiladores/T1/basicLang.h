#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

/*interface lexer*/
extern int yylineno;
void yyerror(char *s, ...);
extern FILE *yyin;

/*tabela de simbolos*/
typedef struct symbol
{
    char *name;
    double value;
    struct ast *func;
    struct symList *syms;
} symbol;

/*tabela de simbolos com tamanho fixo*/
#define NHASH 9997
extern symbol symTab[NHASH];

symbol *lookup(char *);

/*lista de simbolos para lista de argumentos*/
typedef struct symList
{
    symbol *sym;
    struct symList *next;
} symList;

struct symList *newSymList(symbol *sym, symList *next);
void freeSymList(symList *sl);

/****************************************************************
 *tipos de nos
 * + - * /
 * 0-7 op comparacao
 * L expressao ou lista de comandos
 * I comando IF
 * W comando while
 * R comando FOR
 * N symbol de ref
 * = atribuicao
 * S lista de simbolos
 * F chamada de funcao pre-definida
 * C chamada de funcao def. por usuario
 * A and
 * O or
 ***************************************************************/

enum bifs /*funcoes pre definidas*/
{
    B_sqrt = 1,
    B_exp,
    B_log,
    B_print
};

/*nos na AST*/
typedef struct ast
{
    int nodetype;
    struct ast *l;
    struct ast *r;
} ast;

typedef struct fnCall /*pre-definida*/
{
    int nodetype; /*tipo F*/
    struct ast *l;
    enum bifs functype;
} fnCall;

typedef struct ufnCall /*usuario*/
{
    int nodetype; /*tipo C*/
    struct ast *l;
    symbol *s;
} ufnCall;

typedef struct flow
{
    int nodetype; /*tipo I, W ou R*/
    struct ast *cond; /*condicao*/
    struct ast *tl;     /*ramo then ou lista do*/
    struct ast *el;    /*ramo opcional else*/
    ast *posCmd; /*comando apos iteracao para for*/
} flow;

typedef struct numVal
{
    int nodetype;   /*tipo K*/
    double number;
} numVal;

typedef struct symRef
{
    int nodetype;   /*tipo N*/
    symbol *s;
} symRef;

typedef struct symAssign
{
    int nodetype;   /*tipo =*/
    symbol *s;
    ast *v;         /*valor a ser atribuido*/
} symAssign;

/*construção da AST*/
ast *newAst(int nodetype, ast *l, ast *r);
ast *newCmp(int cmptype, ast *l, ast *r);
ast *newFunc(int functype, ast *l);
ast *newCall(symbol *s, ast *l);
ast *newRef(symbol *s);
ast *newAssign(symbol *s, ast *v);
ast *newNum(double number);
ast *newFlow(int nodetype, ast *cond, ast *tl, ast *tr, ast *posCond);
ast *newLogOp(int logicalType, ast *l, ast *r);
/*definicao de uma funcao*/
void doDef(symbol *name, symList *syms, ast *stmts);

/*avaliacao da AST*/
double eval(ast *);

/*destruir AST*/
void freeTree(ast *);
