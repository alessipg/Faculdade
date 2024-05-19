/*
 *Definição: conjunto de entidades competindo por um recurso escasso.
 *FIFO: First In, First Out
 * Dependendo da ordem de inserção e remoção, pode gerar demora em um dos casos.
 * a)inserção início: inserção rápida, remoção lenta.
 * b)inserção fim: inserção lenta, remoção rápida.
 * 
 * Bem implementada com listas circulares.
 * mantemos sempre um ponteiro para o ultimo no,
 * 
 * o campo prox do ultimo aponta para  o primeiro 
 * insere no fim e remove no primeiro.
 * 
 * 
 * inserindo o nó com valor 50, haverá um ponteiro ult da main apontando para ele e o prox dentro do nó 50, aponta para
 * o primeiro, no caso, ele mesmo
 * ult_main ===> no50 | no50->prox ===> primeiro elemento(no50);
 *
 */