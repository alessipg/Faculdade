#include "conversor.h"

void copyString(char **destino, char *conteudo)
{
    *destino = malloc(strlen(conteudo) + 1);
    if (!*destino)
    {
        yyerror("Sem espaco para string");
        exit(0);
    }
    strcpy(*destino, conteudo);
}
BodyList *newBodyList(char *body, char type, BodyList *next)
{
    BodyList *b = malloc(sizeof(BodyList));
    if (!b)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    copyString(&b->body, body);
    b->next = next;
    b->type = type;
    return b;
}

Plan *newPlan(char *nome, Knowledge *trigger, Knowledge *ctx, BodyList *body)
{
    Plan *p = malloc(sizeof(Plan));
    if (!p)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    copyString(&p->nome, nome);

    p->trigger = malloc(sizeof(Knowledge));
    if (!p->trigger)
    {
        yyerror("Sem espaco para trigger");
        exit(0);
    }
    copyString(&p->trigger->knowledge, trigger->knowledge);
    p->trigger->type = trigger->type;

    p->ctx = malloc(sizeof(Knowledge));
    if (!p->ctx)
    {
        yyerror("Sem espaco para contexto");
        exit(0);
    }
    copyString(&p->ctx->knowledge, ctx->knowledge);
    p->ctx->type = ctx->type;

    p->body = body;
    return p;
}

PlanList *newPlanList(Plan *p, PlanList *next)
{
    PlanList *pl = malloc(sizeof(PlanList));
    if (!pl)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    pl->p = p;
    pl->next = next;
    return pl;
}

BeliefList *newBeliefList(char *belief, BeliefList *next)
{
    BeliefList *b = malloc(sizeof(BeliefList));
    if (!b)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    copyString(&b->b, belief);
    b->next = next;
    return b;
}

Agent *newAgent(char *nome, BeliefList *beliefs, char *goal, PlanList *plans)
{
    Agent *a = malloc(sizeof(Agent));
    if (!a)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    copyString(&a->nome, nome);
    a->beliefs = beliefs;
    copyString(&a->goal, goal);
    a->plans = plans;
    return a;
}

AgentList *newAgentList(char *id, Agent *a, AgentList *next)
{
    AgentList *al = malloc(sizeof(AgentList));
    if (!al)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    al->id = strdup(id);
    al->a = a;
    al->next = next;
    return al;
}
Knowledge *newKnowledge(char *name, int type)
{
    Knowledge *k = malloc(sizeof(Knowledge));
    if (!k)
    {
        yyerror("Sem espaco");
        exit(0);
    }
    copyString(&k->knowledge, name);
    k->type = type;

    return k;
}

void eval(AgentList *al)
{

    // Abrindo o arquivo de saída
    FILE *file = fopen("agente.py", "w");
    if (!file)
    {
        fprintf(stderr, "Erro ao criar o arquivo de saída.\n");
        return;
    }

    // Adiciona o cabeçalho do MASPY
    fprintf(file, "from maspy import *\n\n");

    // Iterar sobre a lista de agentes
    AgentList *currentAgent = al;
    while (currentAgent)
    {
        Agent *a = currentAgent->a;

        // Classe do agente
        fprintf(file, "class %s(Agent):\n", currentAgent->id);
        fprintf(file, "    def __init__(self, agt_name):\n");
        fprintf(file, "        super().__init__(agt_name)\n");
        /*Esta faltando avaliar o prefixo A B e G nos planos*/
        // Adiciona as crenças
        BeliefList *currentBelief = a->beliefs;
        while (currentBelief)
        {
            fprintf(file, "        self.add(Belief(\"%s\"))\n", currentBelief->b);
            currentBelief = currentBelief->next;
        }

        // Adiciona as metas
        if (a->goal && a->goal[0] != '\0')
            fprintf(file, "        self.add(Goal(\"%s\"))\n", a->goal);

        // Adiciona os planos
        PlanList *currentPlan = a->plans;
        while (currentPlan)
        {
            Plan *p = currentPlan->p;
            char trigger[10];
            char ctx[10];
            if (p->trigger->type == 'B')
            {
                strcpy(trigger, "Belief");
            }
            else
            {
                strcpy(trigger, "Goal");
            }
            if (p->ctx->type == 'B')
            {
                strcpy(ctx, "Belief");
            }
            else
            {
                strcpy(ctx, "Goal");
            }
            fprintf(file, "\n    @pl(gain,%s(\"%s\"), %s(\"%s\"))\n", trigger, p->trigger->knowledge, ctx, p->ctx->knowledge);
            fprintf(file, "    def %s_(self, src):\n", p->trigger->knowledge);
            BodyList *currentBody = p->body;

            while (currentBody)
            {
                if (currentBody->type == 'A')
                    fprintf(file, "        self.print(\"%s\")\n", currentBody->body);
                else if (currentBody->type == 'B')
                    fprintf(file, "        self.add(Belief(\"%s\"))\n", currentBody->body);
                else if (currentBody->type == 'G')
                    fprintf(file, "        self.add(Goal(\"%s\"))\n", currentBody->body);
                else
                {
                    fprintf(stderr, "Erro: tipo de body incompativel.\n");
                    fclose(file);
                }
                currentBody = currentBody->next;
            }
            currentPlan = currentPlan->next;
        }

        // Linha em branco entre classes de agentes
        fprintf(file, "\n");
        currentAgent = currentAgent->next;
    }

    // Adiciona código para iniciar o sistema
    currentAgent = al;
    while (currentAgent)
    {
        Agent *a = currentAgent->a;
        fprintf(file, "%s(\"%s\")\n", currentAgent->id, a->nome);
        currentAgent = currentAgent->next;
    }
    fprintf(file, "Admin().start_system()\n");

    fclose(file);
    printf("Arquivo Python compatível com MASPY gerado com sucesso: output_maspy.py\n");
}

void freeBodyList(BodyList *body)
{
    while (body)
    {
        BodyList *temp = body;
        body = body->next;
        free(temp->body);
        free(temp);
    }
}

void freeBeliefList(BeliefList *beliefs)
{
    while (beliefs)
    {
        BeliefList *temp = beliefs;
        beliefs = beliefs->next;
        free(temp->b);
        free(temp);
    }
}

void freePlan(Plan *plan)
{
    if (plan)
    {
        free(plan->nome);
        free(plan->trigger);
        free(plan->ctx);
        freeBodyList(plan->body);
        free(plan);
    }
}

void freePlanList(PlanList *plans)
{
    while (plans)
    {
        PlanList *temp = plans;
        plans = plans->next;
        freePlan(temp->p);
        free(temp);
    }
}

void freeAgent(Agent *agent)
{
    if (agent)
    {
        free(agent->nome);
        freeBeliefList(agent->beliefs);
        free(agent->goal);
        freePlanList(agent->plans);
        free(agent);
    }
}

void freeAgentList(AgentList *agents)
{
    while (agents)
    {
        AgentList *temp = agents;
        agents = agents->next;
        free(temp->id);
        freeAgent(temp->a);
        free(temp);
    }
}

// Declaração de funções do Bison e Flex
extern int yyparse();
extern void yyrestart(FILE *input_file);
extern FILE *yyin;

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "Erro na linha %d: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    // Verifica se o arquivo de entrada foi passado como argumento
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <arquivo.json>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo JSON para leitura
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Reinicia o lexer para processar o novo arquivo
    yyrestart(input_file);
    yydebug = 0;
    // Chama o parser
    printf("Parsing do arquivo JSON em andamento...\n");
    if (yyparse() == 0)
    {
        printf("Parsing concluído com sucesso.\n");
    }
    else
    {
        fprintf(stderr, "Erro durante o parsing do arquivo JSON.\n");
        fclose(input_file);
        return 1;
    }

    // Fecha o arquivo de entrada
    fclose(input_file);

    // Chama a função eval para processar os dados e gerar o código Python
    printf("Gerando código Python a partir dos dados...\n");

    printf("Processo concluído. Verifique o arquivo de saída.\n");
    return 0;
}
