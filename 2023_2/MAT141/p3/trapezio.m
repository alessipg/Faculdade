function [I,soma]=trapezio(f,a,b,n)

h=(b-a)/n;
x(1)=a;
y(1)=f(a);
for i = 1:n
  x(i+1)=x(i)+h;
  y(i+1)=f(x(i+1));
endfor
soma = 0;
for i=2:n
  soma=soma+y(i);
endfor
I=h/2*(y(1)+2*soma+y(n+1));
  endfunction
