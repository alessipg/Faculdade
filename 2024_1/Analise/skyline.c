#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    int tam;
    int x;
    int y;
    struct Point *prox;
}Point;

Point *mergeSkyline(Point *w, Point *x){
    while(1){
        if(w == NULL || x == NULL) return NULL;
        int menorX;
        if(w->x < w->y){
            menorX = w->x;
        }else{
            menorX = w->y;
        }
        
    }

}
Point *skyline(int **v,int p, int q){
    if (p == q){
        Point *point1 = malloc(sizeof(Point));
        if(!point1) return NULL;
        point1->x = v[0][0];
        point1->y = v[0][2];
        Point *point2 = malloc(sizeof(Point));
        if(!point2) return NULL;
        point2->x = v[0][1];
        point2->y = 0;
        point1->prox = point2;
        point2->prox = NULL;
        return point1;
    }
    if(p<q){
        return NULL;
    }
    int m = (p+q)/2;
    Point *w = skyline(v,p,m);
    Point *x = skyline(v,m+1,q);
    return mergeSkyline(w,x); 
}
void print(Point *sky){
    Point *aux = sky;
    while(aux != NULL){
        printf("(%d %d) ",aux->x,aux->y);
        aux = aux->prox;
    }
}
int main(){
    int **predios = malloc(1 * sizeof(int *));
    predios[0] = malloc(3 * sizeof(int));
    predios[0][0] = 2;
    predios[0][1] = 9;
    predios[0][2] = 10;
    Point *sky = skyline(predios,1,1);
    print(sky);
}