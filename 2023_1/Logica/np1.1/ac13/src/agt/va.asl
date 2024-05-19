// Agent va in project ac13

/* Initial beliefs and rules */
posicao(cruzamento).

/* Initial goals */


/* Plans */

+!acelerar[source(Ag)] : posicao(cruzamento) <-
        .print("Desativando freio e acelerando");
        .print("Avancando no cruzamento");
        .print("Ordem solicitada pelo agente ", Ag).

+!frear[source(Ag)] : posicao(cruzamento) <-
        .print("Acionando freios e parando no cruzamento");
        .print("Ordem solicitada pelo agente ", Ag).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
