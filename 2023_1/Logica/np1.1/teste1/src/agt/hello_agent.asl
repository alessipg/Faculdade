// Agent sample_agent in project teste1

/* Initial beliefs and rules */

tem(agua).
tem(pohdecafe).
tem(filtro).
tem(maquinadecafe).

/* Initial goals */

!makecoffee.

/* Plans */
@prepararCafeFiltrado
+!makecoffee : tem(agua) & tem(filtro) & tem(pohdecafe) <-
    .print("aquecer agua.");
    .print("colocar agua e po de cafe.");
    .print("passar cafe filtrado.");
    .print("servir cafe!");
    -tem(filtro);
    -tem(pohdecafe);
    !makecoffee.

@prepararCafeEspresso
+!makecoffee : tem(agua) & tem(maquinadecafe) <-
    .print("ligar maquina de cafe.");
    .print("colocar agua.");
    .print("triturar graos");
    .print("servir cafe!").


{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
