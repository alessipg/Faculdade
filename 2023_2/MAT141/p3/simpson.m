function[I,somapar,somaimpar] = simpson(f,a,b,n)
%entradas utilizadas na prova
%f =
%
%@(x) (x .^ 4 - 5 .* x .^ 3 + 1.75 .* x .^ 2 - 10.2 .* x + 1)
%
%>> [I,somapar,somaimpar] = simpson(f,0,2,424)
h = (b-a)/n;
x(1) = a;
y(1) = f(a);
for i =1:n
  x(i+1)=x(i)+h;
  y(i+1)=f(x(i+1));
endfor

%versao principal
somapar=0;
somaimpar = 0;
for j = 1:n/2
  somapar = somapar+y(2*j);
endfor
for j = 2:n/2
  somaimpar = somaimpar + y(2*j-1)
endfor
I=h/3*(y(1)+4*somapar+2*somaimpar+y(n+1));

%alternativa
%somapar=0;
%somaimpar = 0;
%for j = 2:2:n
%  somapar = somapar+y(j);
%endfor
%for j = 3:2:n-1
%  somaimpar = somaimpar + y(j)
%endfor
%I=h/3*(y(1)+4*somapar+2*somaimpar+y(n+1));

endfunction
