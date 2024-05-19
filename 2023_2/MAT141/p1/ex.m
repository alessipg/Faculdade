format long;
a=1;
b=-100.0001;
c=0.01;


raiz = sqrt(b^2-4*a*c);

x1 = (-b+raiz)/2*a;

x2 = (-b-raiz)/2*a;

x2certo = 2*c/(-b+raiz);

ea = x2certo - x2;

er = ea/x2certo;
