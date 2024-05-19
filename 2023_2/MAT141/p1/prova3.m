function[exato,aprox,ea,er]=prova3(x)

exato = exp(x);

aprox = 1+x+x^2/factorial(2)+x^3/factorial(3)+x^4/factorial(4)+x^5/factorial(5);

ea = exato - aprox;
er = ea/exato;

endfunction
