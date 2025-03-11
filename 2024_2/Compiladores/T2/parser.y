%{
    #define YYDEBUG 1
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "conversor.h"

    int yylex(void);
%}

%union {
    Agent *a; 
    char *s;
    AgentList *al;
    BeliefList *bl;
    BodyList *b;
    PlanList *pl;
    Plan *p;
    Knowledge *k;
}

%debug

%token <s> STRING P_ACTION P_BELIEF P_GOAL
%token AGENTCODE BELIEFS GOAL PLANS TRIGGER CTX BODY NAME

%type <a> agent 
%type <al> agentList
%type <bl> beliefList beliefs
%type <s> goal name
%type <k> knowledge
%type <p> plan
%type <pl> plans planList
%type <b> bodyList

%start agents

%%

agents:
    '{' AGENTCODE ':' '{' agentList '}' '}' { printf("Bison: processando agentes na linha %d\n", yylineno);eval($5); freeAgentList($5); }
    ;

agentList:
    STRING ':' agent { $$ = newAgentList($1, $3, NULL); }
    | STRING ':' agent ',' agentList { $$ = newAgentList($1, $3, $5); }
    ;

agent:
    '{' name ',' beliefs ',' goal ',' plans '}' { $$ = newAgent($2, $4, $6, $8); }
    ;
name:
    NAME ':' STRING { $$ = $3; }
    ;
beliefs:
    BELIEFS ':' '[' beliefList ']' { $$ = $4; }
    ;

beliefList:
    STRING { $$ = newBeliefList($1, NULL); }
    | STRING ',' beliefList { $$ = newBeliefList($1, $3); }
    ;

goal:
    GOAL ':' STRING { $$ = $3; }
    ;

plans:
    PLANS ':' '{' planList '}' { $$ = $4; }
    ;

planList:
    plan { $$ = newPlanList($1, NULL); }
    | plan ',' planList { $$ = newPlanList($1, $3); }
    ;

plan:
    STRING ':' '{' TRIGGER ':' knowledge ',' CTX ':' knowledge ',' BODY ':' '[' bodyList ']' '}' { $$ = newPlan($1, $6, $10, $15); }
    ;
knowledge:
    P_BELIEF    { $$ = newKnowledge($1, 'B'); }
    | P_GOAL    { $$ = newKnowledge($1, 'G'); }
    ;
bodyList:
    P_ACTION { $$ = newBodyList($1, 'A', NULL); }
    | P_BELIEF { $$ = newBodyList($1, 'B', NULL); }
    | P_GOAL { $$ = newBodyList($1, 'G', NULL); }
    | P_ACTION ',' bodyList { $$ = newBodyList($1, 'A', $3); }
    | P_BELIEF ',' bodyList { $$ = newBodyList($1, 'B', $3); }
    | P_GOAL ',' bodyList { $$ = newBodyList($1, 'G', $3); }
    ;

%%
