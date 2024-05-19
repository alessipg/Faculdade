function[X,Y] = terceira(f,xi,xf,yi,h)

X(1) = xi;
Y(1) = yi;

n = (xf-xi)/h;

for i = 1: n
  X(i+1) = X(i)+h;
  K1= f(X(i),Y(i));
  K2= f(X(i)+1/2*h,Y(i)+1/2*K1*h);
  K3= f(X(i)+h,Y(i)-K1*h+2*K2*h);

  Y(i+1) = Y(i)+1/6*(K1+4*K2+K3)*h;
  printf("%.4f | %.4f | %.4f | %.4f | %.4f\n",X(i),Y(i), K1, K2, K3);
endfor
printf("%.4f | %.4f\n",X(n+1),Y(n+1));
endfunction
