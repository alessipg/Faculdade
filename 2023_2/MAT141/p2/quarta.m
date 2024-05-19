function[X,Y] = quarta(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
  X(i+1) = X(i)+h;
  K1= f(X(i),Y(i));
  K2= f(X(i)+1/2*h,Y(i)+1/2*K1*h);
  K3= f(X(i)+1/2*h,Y(i)+1/2*K2*h);
  K4= f(X(i)+h,Y(i)+K3*h);
  Y(i+1) = Y(i)+1/6*(K1+2*K2+2*K3+K4)*h;

  endfor
endfunction
