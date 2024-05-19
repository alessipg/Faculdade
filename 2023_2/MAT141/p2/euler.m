function[X,Y] = euler(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
   X(i+1) = X(i)+h;
   K1 = f(X(i),Y(i));
   Y(i+1) = Y(i)+K1*h;
  endfor

endfunction;
