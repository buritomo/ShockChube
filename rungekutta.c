#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "rungekutta.h"

void setAssumedPotential(void){
    k1 = (double * )malloc(sizeof(double) * split);
    k2 = (double * )malloc(sizeof(double) * split);
    k3 = (double * )malloc(sizeof(double) * split);
    k4 = (double * )malloc(sizeof(double) * split);
    
    return;
}

void releaseAssumedPotential(void){
    free(k1);
    free(k2);
    free(k3);
    free(k4);

    return;
}

void rungekutta(void){
    double lam[4];
    lam[0] = 0.25;
    lam[1] = 1.0 / 3.0;
    lam[2] = 0.5;
    lam[3] = 1.0;

    for(int k=0; k<split; k++){
        k1[k] = Q1[k];
        k2[k] = Q2[k];
        k3[k] = Q3[k];
        k4[k] = Q4[k];
    }

    for(int k=0; k<4; k++){
        for(int lx=1; lx<x_split-1; lx++){
            for(int ly=1; ly<y_split; ly++){
                k1[lx + x_split * ly] = k1[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Ehalf1[lx + x_split * ly] - Ehalf1[lx + x_split * ly - 1]);
                k2[lx + x_split * ly] = k2[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Ehalf2[lx + x_split * ly] - Ehalf2[lx + x_split * ly - 1]);
                k3[lx + x_split * ly] = k3[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Ehalf3[lx + x_split * ly] - Ehalf3[lx + x_split * ly - 1]);
            }
        }
    }

    for(int k=0; k<4; k++){
        for(int lx=1; lx<x_split; lx++){
            for(int ly=1; ly<y_split-1; ly++){
                k1[lx + x_split * ly] = k1[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Fhalf1[lx + x_split * ly] - Fhalf1[lx + x_split * (ly-1)]);
                k2[lx + x_split * ly] = k2[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Fhalf2[lx + x_split * ly] - Fhalf2[lx + x_split * (ly-1)]);
                k3[lx + x_split * ly] = k3[lx + x_split * ly] - lam[k] * TIME_STEP / X_STEP * (Fhalf3[lx + x_split * ly] - Fhalf3[lx + x_split * (ly-1)]);
            }
        }
    }

    for(int k=0; k<split; k++){
        Q1[k] = k1[k];
        Q2[k] = k2[k];
        Q3[k] = k3[k];
        Q4[k] = k4[k];
    } 

    return;    
}
