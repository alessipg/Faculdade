function[X1] = seidel(A,b,erro,X)
%necessário declarar X = [0;0;0] para o código funcionar
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

X1=X;
for i=1:n
X1(i,1) = I(i,1) + D(i,:) * X1;
endfor


ER = abs((X1-X)./X1);% *100 se porcentagem
printf("%f | %f | %f | %f | %f\n",k, X1(1),X1(2),X1(3),X1(4))
if(max(ER)<erro)
  break;
endif
k=k+1;
X=X1;

endwhile
endfunction
