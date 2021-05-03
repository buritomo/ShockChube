#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void makeGrid(void){
    rho = (double * )malloc(sizeof(double) * x_split);
    u = (double * )malloc(sizeof(double) * x_split);
    e = (double * )malloc(sizeof(double) * x_split);
    p = (double * )malloc(sizeof(double) * x_split);
    c = (double * )malloc(sizeof(double) * x_split);
    H = (double * )malloc(sizeof(double) * x_split);
    area = (double * )malloc(sizeof(double) * x_split);
    Q1 = (double * )malloc(sizeof(double) * x_split);
    Q2 = (double * )malloc(sizeof(double) * x_split);
    Q3 = (double * )malloc(sizeof(double) * x_split);
    E1 = (double * )malloc(sizeof(double) * x_split);
    E2 = (double * )malloc(sizeof(double) * x_split);
    E3 = (double * )malloc(sizeof(double) * x_split);
    Ehalf1 = (double * )malloc(sizeof(double) * x_split);
    Ehalf2 = (double * )malloc(sizeof(double) * x_split);
    Ehalf3 = (double * )malloc(sizeof(double) * x_split);
    return;
}

void freeGrid(void){
    free(rho);
    free(u);
    free(e);
    free(p);
    free(c);
    free(H);
    free(area);
    free(Q1);
    free(Q2);
    free(Q3);
    free(E1);
    free(E2);
    free(E3);
    free(Ehalf1);
    free(Ehalf2);
    free(Ehalf3);

    return;
}