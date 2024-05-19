function[X,Y]= pontomedio(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
   X(i+1) = X(i)+h;
   K1 = f(X(i),Y(i));
   ym = Y(i)+K1*h/2;
   xm = X(i) + h/2;
   K2 = f(xm,ym);
   Y(i+1) =  Y(i)+K2*h;
endfor
endfunction
