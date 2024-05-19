function [yint,DD] = newton(x,y,xint)
  %valores que utilizei para calcular o erro:
  %abs((x-300)*(x-350))*0.0000222
  %abs((x-250)*(x-300)*(x-350))*-0.000000108
  n = length(x);
  for i = 1:n
    DD(i,1)=y(i);
  endfor
  for j = 2:n
    for i = 1:n-j+1
      DD(i,j)=((DD(i+1,j-1)-DD(i,j-1))/(x(j+i-1)-x(i)));
    endfor
  endfor
  for j=1:n
    a(j)=DD(1,j);
  endfor
  yint=a(1);
  xtemp=1;
  for k =2:n
    xtemp=xtemp*(xint-x(k-1));
    yint=yint+a(k)*xtemp;
  endfor
endfunction
