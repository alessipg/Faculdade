function erroTrapezio(a,b,m2,erro)

r=sqrt(((b-a)^3*m2)/(12*erro))
printf("Numero minimo de subintervalos:%f \nObs Arredondar para o maior\n",r);

endfunction
