function[i,j,er] = prova2(x)
format long;
f1 = @(x) (sqrt(64+x)-8)/x;

f2 = @(x) 1/(sqrt(64+x)+8);

i = f1(x);
j = f2(x);

er = (j-i)/j;
endfunction
