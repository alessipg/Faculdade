#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern int yylineno;
extern int yydebug;
void yyerror(char *s, ...);
extern FILE *yyin;
typedef struct Plan Plan;
typedef struct Agent Agent;
typedef struct BodyList BodyList;
typedef struct PlanList PlanList;
typedef struct Knowledge Knowledge;
typedef struct AgentList AgentList;
typedef struct BeliefList BeliefList;

struct BodyList
{
    char *body;
    char type;
    struct BodyList *next;
};

struct BeliefList
{
    char *b;
    struct BeliefList *next;
};

struct Plan
{
    char *nome;
    Knowledge *trigger;
    Knowledge *ctx;
    BodyList *body;
};

struct PlanList
{
    Plan *p;
    PlanList *next;
};

struct Agent
{
    char *nome;
    BeliefList *beliefs;
    char *goal;
    PlanList *plans;
};

struct AgentList
{
    char *id;
    Agent *a;
    AgentList *next;
};

struct Knowledge
{
    char *knowledge;
    int type; //'B' = belief, 'G' = goal
};

void eval(AgentList *al);
void freePlan(Plan *plan);
void freeAgent(Agent *agent);
void freeBodyList(BodyList *body);
void freePlanList(PlanList *plans);
void freeAgentList(AgentList *agents);
void freeBeliefList(BeliefList *beliefs);
Knowledge *newKnowledge(char *name, int type);
void copyString(char **destino, char *conteudo);
PlanList *newPlanList(Plan *plan, PlanList *next);
BeliefList *newBeliefList(char *belief, BeliefList *next);
AgentList *newAgentList(char *id, Agent *a, AgentList *next);
BodyList *newBodyList(char *body, char type, BodyList *next);
Agent *newAgent(char *nome, BeliefList *beliefs, char *goal, PlanList *plans);
Plan *newPlan(char *nome, Knowledge *trigger, Knowledge *ctx, BodyList *body);