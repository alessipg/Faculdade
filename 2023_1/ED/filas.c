/*
 *Defini��o: conjunto de entidades competindo por um recurso escasso.
 *FIFO: First In, First Out
 * Dependendo da ordem de inser��o e remo��o, pode gerar demora em um dos casos.
 * a)inser��o in�cio: inser��o r�pida, remo��o lenta.
 * b)inser��o fim: inser��o lenta, remo��o r�pida.
 * 
 * Bem implementada com listas circulares.
 * mantemos sempre um ponteiro para o ultimo no,
 * 
 * o campo prox do ultimo aponta para  o primeiro 
 * insere no fim e remove no primeiro.
 * 
 * 
 * inserindo o n� com valor 50, haver� um ponteiro ult da main apontando para ele e o prox dentro do n� 50, aponta para
 * o primeiro, no caso, ele mesmo
 * ult_main ===> no50 | no50->prox ===> primeiro elemento(no50);
 *
 */