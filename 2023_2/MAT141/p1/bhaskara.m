function[x1,x2,x2mod,EA,ER] = bhaskara(a,b,c)
format long
raiz=sqrt(b^2-4*a*c);
x1=(-b+raiz)/(2*a);
x2=(-b-raiz)/(2*a);
x2mod=2*c/(-b+raiz);
EA=x2mod - x2;
ER=EA-x2mod;
endfunction
