function erroSimpson(a,b,m4,erro)

r=nthroot((((b-a)^5*m4)/(180*erro)),4);
printf("Numero minimo de intervalos:%d \nObs Arredondar para o prox. par maior\n",r);
endfunction
