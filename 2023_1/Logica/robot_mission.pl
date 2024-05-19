robot(r2d2).
robot(c3po).
robot(bb8).

knowledge(c3po, tradutor).
knowledge(r2d2, mensageiro).
knowledge(bb8, navegador).

diplomaticMission(X,Y) :-
    					robot(X),
    					robot(Y),
    					knowledge(X, tradutor),
    					knowledge(Y, mensageiro).
spaceMission(X,Y) :-
    			robot(X),
    			robot(Y),
    			(knowledge(X, navegador), knowledge(Y, mensageiro));
    			(knowledge(X, navegador), knowledge(Y, tradutor)).
exploreMission(X,Y) :-
					robot(X),
    				robot(Y),
    				(knowledge(X, tradutor), knowledge(Y, mensageiro));
    				(knowledge(X, tradutor), knowledge(Y, navegador)).
allMissionSettings(X,Y) :-
					diplomaticMission(X,Y);
    				spaceMission(X,Y);
    				exploreMission(X,Y).