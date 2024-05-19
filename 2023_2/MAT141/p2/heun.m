function[X,Y] = heun(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
  X(i+1) = X(i)+h;
  K1 = f(X(i),Y(i));
  K2 = f(X(i)+h,Y(i)+K1*h);
  Y(i+1) = Y(i)+(K1*1/2+K2*1/2)*h;
endfor

endfunction
