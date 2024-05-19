%function [x1,x2,x1pivo,x2pivo,erro]=gauss_ex1(A,b)
format long
A=input('Insira a matriz dos coeficientes, ex. [1 2; 3 4]:    ');
disp('Insira o vetor dos termos independentes, ex. [1;2]');
b=input('');

Ab=[A,b]; %Criando matriz completa do sistema
A1=Ab; %Matriz auxiliar para calculos

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Eliminacao de Gauss sem Pivoteamento%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

m21=Ab(2,1)/Ab(1,1); %multiplicador
A1(2,:)=Ab(2,:)-m21*Ab(1,:); %eliminacao de x1 da eq. 2

%Substituicao regressiva
x2=A1(2,3)/A1(2,2); %Calculo x2
x1=(A1(1,3)-A1(1,2)*x2)/A1(1,1); %Calculo x1

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Eliminacao de Gauss com Pivoteamento%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Troca da linha 1 com a 2.
A2(1,:)=Ab(2,:);
A2(2,:)=Ab(1,:);

M21=A2(2,1)/A2(1,1); %multiplicador

A21(1,:)=A2(1,:);
A21(2,:)=A2(2,:)-M21*A2(1,:); %Eliminacao de x1 da eq. 2
x2pivo=A21(2,3)/A21(2,2); %Calculo x2
x1pivo=(A21(1,3)-A21(1,2)*x2pivo)/A21(1,1); %Calculo x1

erro=abs(x1pivo-x1); %Calculo do erro cometido quando nao se usa pivoteamento

%SA�DAS
printf('\n Sem pivoteamento: x1=%.20f; x2=%.20f\n',x1,x2)
printf('\n Com pivoteamento: x1=%f; x2=%f\n',x1pivo,x2pivo)
printf('\n O erro absoluto cometido no calculo de x1 foi: %e',erro)

%endfunction
