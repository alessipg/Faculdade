function [p,k] = secante(f,x0,x1,erro)
format long;
  k=0;
  while (k<100)

    if(abs(x1-x0)<erro)
      break;
    endif
  p = (x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
  x0=x1;
  x1=p;
  k=k+1;
  printf("%d | %f | %f |\n", k, x0, p);
  endwhile

  endfunction
