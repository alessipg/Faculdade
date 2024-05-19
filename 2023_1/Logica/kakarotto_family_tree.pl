masculino(vegeta_iii).
masculino(vegeta_iv).
masculino(goku).
masculino(gohan).
masculino(bardock).
masculino(raditz).
masculino(mrsatan).
masculino(goten).
feminino(gine).
feminino(chichi).
feminino(videl).
feminino(pan).

progenitor(vegeta_iii,vegeta_iv).
progenitor(bardock,raditz).
progenitor(bardock,goku).
progenitor(gine,raditz).
progenitor(gine,goku).
progenitor(goku,goten).
progenitor(goku,gohan).
progenitor(chichi,gohan).
progenitor(chichi,goten).
progenitor(mrsatan,videl).
progenitor(gohan,pan).
progenitor(videl,pan).


pai(X, Y) :-
		progenitor(X, Y),
    	masculino(X).

mae(X, Y) :-
    	progenitor(X, Y),
    	feminino(X).

filho(Y, X) :-
    	progenitor(X, Y),
		masculino(Y).

filha(Y, X) :-
    	progenitor(X, Y),
    	feminino(Y).

avo(X, Z) :-		%avó
    	progenitor(X,Y),
   		progenitor(Y,Z),
    	feminino(X).

irma(X, Y) :-
    	feminino(X),
    	progenitor(Z, Y),
    	progenitor(Z, X),
    	X \= Y.

irmao(bardock,vegeta_iii).
irmao(X, Y) :-
    	masculino(X),
    	progenitor(Z, Y),
    	progenitor(Z, X),
    	X \= Y.

tio(X,Z) :-
    	irmao(X,Y),%já vai verificar se masculino
    	filho(Z,Y).

tia(X,Z) :-
    	irma(X,Y),%já vai verificar se feminino
    	filho(Z,Y).

primo(X,Z) :-
    		filho(X,Y),
    		(filho(Z,Y1);filha(Z,Y1)),
    		(irmao(Y, Y1);irma(Y,Y1)).
prima(X,Z) :-
    		filha(X,Y),
    		(filho(Z,Y1);filha(Z,Y1)),
    		(irmao(Y, Y1);irma(Y,Y1)).
antepassado(X, Z) :-
    	progenitor(X,Z).

antepassadoindireto(X, Z) :-
    	progenitor(X, Y),
    	antepassado(Y, Z).