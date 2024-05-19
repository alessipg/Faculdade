// Agent ct in project ac13

/* Initial beliefs and rules */

cruzamento(ocupado).

/* Initial goals */

!verificarSensor.

/* Plans */

+!verificarSensor : cruzamento(ocupado) <- 
                        .print("Cruzamento ocupado");
                        .send(va, achieve, frear);
                        -cruzamento(ocupado);
                        +cruzamento(livre);
                        !verificarSensor.

+!verificarSensor : cruzamento(livre) <- 
                        .print("Cruzamento livre");
                        .send(va, achieve, acelerar).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
