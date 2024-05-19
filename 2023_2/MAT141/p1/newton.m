function[p,k]=newton(f,df,x0,erro)
format long;
k = 0;
while(k<100)
  printf("K=%d | x0 = %f | f(x0) = %f | df(x0) = %f\n",k,x0,f(x0),df(x0));
  p=x0-f(x0)/df(x0);

if(abs(p-x0)< erro)
  break;
endif
  k=k+1;
  x0=p;

endwhile

endfunction
