function [a,b,k] = bissecab_modificado(a,b,prec)%o nome da funcao deve ser igual ao do arquivo
  %Este codigo calcula o zero de uma funcao utilizando
  %o metodo da bisseccao
  f = @(x) x.*log10(x)-1; %falta o operador '*' na funcao
  nmax = 100;
  k=0;
  if (f(a)*f(b)>0)
    error('A condicao f(a)*f(b)<0 nao foi satisfeita')
  else
    while k<nmax
      p=(a+b)/2; %isolar a+b para efetuar o calculo correto
       if (abs(b-a)<prec) %comparar somente b-a neste metodo
        break
       endif
      k=k+1;
      if f(a)*f(p)<0
        b=p;%trocar primeiro b
      else
        a=p;%ou entao trocar a
      endif
    endwhile
  endif %encerramento laco if
endfunction
