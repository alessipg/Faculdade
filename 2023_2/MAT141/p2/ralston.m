function[X,Y] = ralston(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
  X(i+1) = X(i)+h;
  K1 = f(X(i),Y(i));
  K2 = f(X(i)+3/4*h,Y(i)+3/4*K1*h);
  Y(i+1) = Y(i)+(K1*1/3+K2*2/3)*h;
endfor

endfunction
