#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void makeGrid(void){
    rho = (double * )malloc(sizeof(double) * split);
    u = (double * )malloc(sizeof(double) * split);
    v = (double * )malloc(sizeof(double) * split);
    e = (double * )malloc(sizeof(double) * split);
    p = (double * )malloc(sizeof(double) * split);
    c = (double * )malloc(sizeof(double) * split);
    H = (double * )malloc(sizeof(double) * split);
    area = (double * )malloc(sizeof(double) * split);
    Q1 = (double * )malloc(sizeof(double) * split);
    Q2 = (double * )malloc(sizeof(double) * split);
    Q3 = (double * )malloc(sizeof(double) * split);
    Q4 = (double * )malloc(sizeof(double) * split);
    E1 = (double * )malloc(sizeof(double) * split);
    E2 = (double * )malloc(sizeof(double) * split);
    E3 = (double * )malloc(sizeof(double) * split);
    E4 = (double * )malloc(sizeof(double) * split);
    F1 = (double * )malloc(sizeof(double) * split);
    F2 = (double * )malloc(sizeof(double) * split);
    F3 = (double * )malloc(sizeof(double) * split);
    F4 = (double * )malloc(sizeof(double) * split);
    Ehalf1 = (double * )malloc(sizeof(double) * split);
    Ehalf2 = (double * )malloc(sizeof(double) * split);
    Ehalf3 = (double * )malloc(sizeof(double) * split);
    Ehalf4 = (double * )malloc(sizeof(double) * split);
    Fhalf1 = (double * )malloc(sizeof(double) * split);
    Fhalf2 = (double * )malloc(sizeof(double) * split);
    Fhalf3 = (double * )malloc(sizeof(double) * split);
    Fhalf4 = (double * )malloc(sizeof(double) * split);
    return;
}

void defineXYgrid(void){
    for(int kx=0; kx<x_split; kx++){
        for(int ky=0;ky<y_split; ky++){
            area[kx + ky * x_split] = (double)kx * 1.0 / (double)x_split + (double)ky * 1.0 / (double)y_split * (double) x_split;
        }
    }
    return;
}

void freeGrid(void){
    free(rho);
    free(u);
    free(v);
    free(e);
    free(p);
    free(c);
    free(H);
    free(area);
    free(Q1);
    free(Q2);
    free(Q3);
    free(Q4);
    free(E1);
    free(E2);
    free(E3);
    free(E4);
    free(F1);
    free(F2);
    free(F3);
    free(F4);
    free(Ehalf1);
    free(Ehalf2);
    free(Ehalf3);
    free(Ehalf4);
    free(Fhalf1);
    free(Fhalf2);
    free(Fhalf3);
    free(Fhalf4);

    return;
}