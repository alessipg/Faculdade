function[a,b,k]=falsaP(f,a,b,erro)

if(f(a)*f(b)>0)
  error('f(a)*f(b) precisa ser menor que 0')
endif

k=0;

while(k<100)

  p=(a*abs(f(b)) + b*abs(f(a))) / (abs(f(b))+abs(f(a)));

if(abs(f(p))<erro)
  break;
endif
k=k+1;
if(f(a)*f(p)<0)
  b = p;
else
  a = p;
 endif
endwhile

endfunction
