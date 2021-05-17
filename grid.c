#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void makeGrid(void){
    rho = (double * )malloc(sizeof(double) * split);
    u = (double * )malloc(sizeof(double) * split);
    e = (double * )malloc(sizeof(double) * split);
    p = (double * )malloc(sizeof(double) * split);
    c = (double * )malloc(sizeof(double) * split);
    H = (double * )malloc(sizeof(double) * split);
    area = (double * )malloc(sizeof(double) * split);
    Q1 = (double * )malloc(sizeof(double) * split);
    Q2 = (double * )malloc(sizeof(double) * split);
    Q3 = (double * )malloc(sizeof(double) * split);
    E1 = (double * )malloc(sizeof(double) * split);
    E2 = (double * )malloc(sizeof(double) * split);
    E3 = (double * )malloc(sizeof(double) * split);
    Ehalf1 = (double * )malloc(sizeof(double) * split);
    Ehalf2 = (double * )malloc(sizeof(double) * split);
    Ehalf3 = (double * )malloc(sizeof(double) * split);
    return;
}

void defineXgrid(void){
    for(int k=0; k<split; k++){
        area[k] = (double)k * 1.0 / (double)split;
    }
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