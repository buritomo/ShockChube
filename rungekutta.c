#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "rungekutta.h"

void setAssumedPotential(void){
    k1 = (double * )malloc(sizeof(double) * x_split);
    k2 = (double * )malloc(sizeof(double) * x_split);
    k3 = (double * )malloc(sizeof(double) * x_split);
    
    return;
}

void releaseAssumedPotential(void){
    free(k1);
    free(k2);
    free(k3);

    return;
}

void rungekutta(void){
    double lam[4];
    lam[0] = 0.25;
    lam[1] = 1.0 / 3.0;
    lam[2] = 0.5;
    lam[3] = 1.0;

    for(int k=0; k<x_split; k++){
        k1[k] = Q1[k];
        k2[k] = Q2[k];
        k3[k] = Q3[k];
    }

    for(int k=0; k<4; k++){
        for(int l=1; l<x_split-1; l++){
            k1[l] = k1[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf1[l] - Ehalf1[l-1]);
            k2[l] = k2[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf2[l] - Ehalf2[l-1]);
            k3[l] = k3[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf3[l] - Ehalf3[l-1]);
        }
    }

    for(int k=0; k<x_split; k++){
        Q1[k] = k1[k];
        Q2[k] = k2[k];
        Q3[k] = k3[k];
    } 

    return;    
}
