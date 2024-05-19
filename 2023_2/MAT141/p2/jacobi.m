function[X1] = jacobi(A,b,erro,X)

n = length(b);

for i=1:n
  I(i,1)=b(i)/A(i,i);
  for j = 1:n
    if(i==j)
      D(i,j) = 0;
    else
      D(i,j) = -A(i,j)/A(i,i);
    endif
    endfor
  endfor
k = 0;
while(k<100)
X1 = I+D*X;
ER = abs((X1-X)./X1);% *100 se porcentagem
if(max(ER)<erro)
  break;
endif
k=k+1;
X=X1;
printf("%d %d %d %d\n",k, X(1),X(2),X(3))
endwhile
endfunction
