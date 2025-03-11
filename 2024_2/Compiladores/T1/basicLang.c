#include "basicLang.h"
symbol symTab[NHASH];

static unsigned symHash(char *sym)
{
    unsigned int hash = 0;
    unsigned c;
    while (c = *sym++)
        hash = hash * 9 ^ c;
    return hash;
}

symbol *lookup(char *sym)
{
    symbol *sp = &symTab[symHash(sym) % NHASH];
    int scount = NHASH;
    while (--scount >= 0)
    {
        if (sp->name && !strcasecmp(sp->name, sym))
            return sp;
        if (!sp->name)
        {
            sp->name = strdup(sym);
            sp->value = 0;
            sp->func = NULL;
            sp->syms = NULL;
            return sp;
        }

        if (++sp >= symTab + NHASH)
            sp = symTab;
    }
    yyerror("overflow na tabela de simbolos\n");
    abort();
}

ast *newAst(int nodetype, ast *l, ast *r)
{
    ast *a = malloc(sizeof(ast));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

ast *newNum(double d)
{
    numVal *a = malloc(sizeof(numVal));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = 'K';
    a->number = d;
    return (ast *)a;
}

ast *newCmp(int cmpType, ast *l, ast *r)
{
    ast *a = malloc(sizeof(ast));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = '0' + cmpType;
    a->l = l;
    a->r = r;
    return a;
}

ast *newLogOp(int logicalType, ast *l, ast *r)
{
    ast *a = malloc(sizeof(ast));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = logicalType;
    a->l = l;
    a->r = r;
    return a;
}
ast *newFunc(int funcType, ast *l)
{
    fnCall *a = malloc(sizeof(fnCall));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = 'F';
    a->l = l;
    a->functype = funcType;
    return (ast *)a;
}

ast *newCall(symbol *s, ast *l)
{
    ufnCall *a = malloc(sizeof(ufnCall));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = 'C';
    a->l = l;
    a->s = s;
    return (ast *)a;
}

ast *newRef(symbol *s)
{
    symRef *a = malloc(sizeof(symRef));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = 'N';
    a->s = s;
    return (ast *)a;
}

ast *newAssign(symbol *s, ast *v)
{
    symAssign *a = malloc(sizeof(symAssign));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = '=';
    a->s = s;
    a->v = v;
    return (ast *)a;
}

ast *newFlow(int nodetype, ast *cond, ast *tl, ast *el, ast *posCmd)
{
    flow *a = malloc(sizeof(flow));
    if (!a)
    {
        yyerror("sem espaco");
        exit(1);
    }
    a->nodetype = nodetype;
    a->cond = cond;//cond FOR
    a->tl = tl;//list FOR
    a->el = el;// init FOR
    a->posCmd = posCmd;
    return (ast *)a;
}

void freeTree(ast *a)
{
    switch (a->nodetype)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case 'A':
    case 'O':
    case 'L':
        freeTree(a->r);
    case 'C':
    case 'F':
        freeTree(a->l);
    case 'K':
    case 'N':
        break;
    case '=':
        free(((symAssign *)a)->v);
        break;
    case 'R':
        free(((flow *)a)->posCmd);
    case 'I':
    case 'W':
        free(((flow *)a)->cond);
        if (((flow *)a)->tl)
            freeTree(((flow *)a)->tl);
        if (((flow *)a)->el)
            freeTree(((flow *)a)->el);
        break;
    default:
        printf("erro interno: free bad node %c \n", a->nodetype);
    }
    free(a);
}

symList *newSymList(symbol *sym, symList *next)
{
    symList *sl = malloc(sizeof(symList));
    if (!sl)
    {
        yyerror("sem espaco");
        exit(1);
    }
    sl->sym = sym;
    sl->next = next;
    return sl;
}

void freeSymList(symList *sl)
{
    symList *nsl;
    while (sl)
    {
        nsl = sl->next;
        free(sl);
        sl = nsl;
    }
}

static double callBuiltIn(fnCall *);
static double callUser(ufnCall *);

double eval(ast *a)
{
    double v;
    if (!a)
    {
        yyerror("erro interno, null eval");
        return 0.0;
    }

    switch (a->nodetype)
    {
    case 'K':
        v = ((numVal *)a)->number;
        break;
    case 'N':
        v = ((symRef *)a)->s->value;
        break;
    case '=':
        v = ((symAssign *)a)->s->value = eval(((symAssign *)a)->v);
        break;
    case '+':
        v = eval(a->l) + eval(a->r);
        break;
    case '-':
        v = eval(a->l) - eval(a->r);
        break;
    case '*':
        v = eval(a->l) * eval(a->r);
        break;
    case '/':
        if (eval(a->r) == 0.0)
        {
            yyerror("Divisao por zero");
            return 0.0;
        }
        v = eval(a->l) / eval(a->r);
        break;
    case 'A':
        v = (eval(a->l) && eval(a->r));
        break;
    case 'O':
        v = (eval(a->l) || eval(a->r));
        break;
    case '1':
        v = (eval(a->l) > eval(a->r)) ? 1 : 0;
        break;
    case '2':
        v = (eval(a->l) < eval(a->r)) ? 1 : 0;
        break;
    case '3':
        v = (eval(a->l) != eval(a->r)) ? 1 : 0;
        break;
    case '4':
        v = (eval(a->l) == eval(a->r)) ? 1 : 0;
        break;
    case '5':
        v = (eval(a->l) >= eval(a->r)) ? 1 : 0;
        break;
    case '6':
        v = (eval(a->l) <= eval(a->r)) ? 1 : 0;
        break;
    case 'I':
        if (eval(((flow *)a)->cond) != 0)
        {
            if (((flow *)a)->tl)
            {
                v = eval(((flow *)a)->tl);
            }
            else
            {
                v = 0.0;
            }
        }
        else
        {
            if (((flow *)a)->el)
            {
                v = eval(((flow *)a)->el);
            }
            else
            {
                v = 0.0;
            }
        }
        break;
    case 'W':
        v = 0.0;
        if (((flow *)a)->tl)
        {
            while (eval(((flow *)a)->cond) != 0)
                v = eval(((flow *)a)->tl);
        }
        break;
    case 'R':
        v = 0.0;
        if (((flow *)a)->tl)
        {
            for (eval(((flow *)a)->el); eval(((flow *)a)->cond); eval(((flow *)a)->posCmd))
            {

                v = eval(((flow *)a)->tl);
            }
            break;
        }
    case 'L':
        eval(a->l);
        v = eval(a->r);
        break;
    case 'F':
        v = callBuiltIn((fnCall *)a);
        break;
    case 'C':
        v = callUser((ufnCall *)a);
        break;
    default:
        printf("erro interno: bad node %c\n", a->nodetype);
    }
    return v;
}

static double callBuiltIn(fnCall *f)
{
    enum bifs funcType = f->functype;
    double v = eval(f->l);
    switch (funcType)
    {
    case B_sqrt:
        return sqrt(v);
    case B_exp:
        return exp(v);
    case B_log:
        return log(v);
    case B_print:
        printf(" = %4.4g\n", v);
        return v;
    default:
        printf("Funcao desconhecida: %d\n", funcType);
        return 0.0;
    }
}

void doDef(symbol *name, symList *syms, ast *func)
{
    if (name->syms)
        freeSymList(name->syms);
    if (name->func)
        freeTree(name->func);
    name->syms = syms;
    name->func = func;
}

static double callUser(ufnCall *f)
{
    symbol *fn = f->s;
    symList *sl;
    ast *args = f->l;
    double *oldVal, *newVal;
    double v;
    int nargs;
    int i;
    if (!fn->func)
    {
        printf("Funcao nao definida: %s\n", fn->name);
        return 0.0;
    }
    sl = fn->syms;
    for (nargs = 0; sl; sl = sl->next)
        nargs++;
    oldVal = (double *)malloc(nargs * sizeof(double));
    newVal = (double *)malloc(nargs * sizeof(double));
    if (!oldVal || !newVal)
    {
        yyerror("sem espaco em %s", fn->name);
        return 0.0;
    }
    for (i = 0; i < nargs; i++)
    {
        if (!args)
        {
            yyerror("poucos argumentos na chamada da funcao %s", fn->name);
            free(oldVal);
            free(newVal);
            return 0.0;
        }

        if (args->nodetype == 'L')
        {
            newVal[i] = eval(args->l);
            args = args->r;
        }
        else
        {
            newVal[i] = eval(args);
            args = NULL;
        }
    }

    sl = fn->syms;
    for (i = 0; i < nargs; i++)
    {
        symbol *s = sl->sym;
        oldVal[i] = s->value;
        s->value = newVal[i];
        sl = sl->next;
    }
    free(newVal);
    v = eval(fn->func);
    sl = fn->syms;
    for (i = 0; i < nargs; i++)
    {
        symbol *s = sl->sym;
        s->value = oldVal[i];
        sl = sl->next;
    }
    free(oldVal);
    return v;
}

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "Erro na linha %d: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[]) {

    if(argc == 1){
        printf("> ");
        yyparse();
        return 0;
    }

    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Erro ao abrir arquivo de saída");
        fclose(inputFile);
        return 1;
    }

    if (freopen(argv[2], "w", stdout) == NULL) {
        perror("Erro ao redirecionar stdout");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    yyin = inputFile;
    printf("> ");
    yyparse();

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}


