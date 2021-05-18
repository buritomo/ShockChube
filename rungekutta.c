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

    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;
            k1[k] = Q1[k];
            k2[k] = Q2[k];
            k3[k] = Q3[k];
            k4[k] = Q4[k];
        }
    }

    for(int k=0; k<4; k++){
        for(int lx=2; lx<x_split-1; lx++){
            for(int ly=0; ly<y_split; ly++){
                int l = lx + ly * x_split;
                k1[l] = k1[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf1[l] - Ehalf1[l-1]);
                k2[l] = k2[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf2[l] - Ehalf2[l-1]);
                k3[l] = k3[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf3[l] - Ehalf3[l-1]);
                k4[l] = k4[l] - lam[k] * TIME_STEP / X_STEP * (Ehalf4[l] - Ehalf4[l-1]);
            }   
        }
    }

    for(int k=0; k<4; k++){
        for(int lx=0; lx<x_split; lx++){
            for(int ly=2; ly<y_split-1; ly++){
                int l = lx + ly * x_split;
                k1[l] = k1[l] - lam[k] * TIME_STEP / Y_STEP * (Fhalf1[l] - Fhalf1[l-x_split]);
                k2[l] = k2[l] - lam[k] * TIME_STEP / Y_STEP * (Fhalf2[l] - Fhalf2[l-x_split]);
                k3[l] = k3[l] - lam[k] * TIME_STEP / Y_STEP * (Fhalf3[l] - Fhalf3[l-x_split]);
                k4[l] = k4[l] - lam[k] * TIME_STEP / Y_STEP * (Fhalf4[l] - Fhalf4[l-x_split]);
            }   
        }
    }

    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;
            Q1[k] = k1[k];
            Q2[k] = k2[k];
            Q3[k] = k3[k];
            Q4[k] = k4[k];
        }
    } 

    return;    
}
