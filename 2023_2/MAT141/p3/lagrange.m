function[yint, L] = lagrange(x,y,xint)

n=length(x);
for i = 1:n
  L(i) = 1;
  for j = 1:n
    if (j!=i)
      L(i)=L(i)*((xint-x(j))/(x(i)-x(j)));
    endif
   endfor
endfor
yint=0;
for i = 1:n
  yint=yint+y(i)*L(i);
  endfor
endfunction
