#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"

void calcInternalEnergy(void){
    for(int k=0; k<x_split; k++){
        e[k] = p[k] / (rho[k] * (GAMMA - 1));
    }
    return;
}

void makePotential(void){
    for(int k=0; k<x_split; k++){
        Q1[k] = rho[k];
        Q2[k] = rho[k] * u[k];
        Q3[k] = e[k];

        E1[k] = rho[k] * u[k];
        E2[k] = p[k] + rho[k] * u[k] * u[k];
        E3[k] = (e[k] + p[k]) * u[k];
    }

    return;
}

void inversePotentialToParams(void){
    for(int k=0; k<x_split; k++){
        rho[k] = Q1[k];
        u[k] = Q2[k] / rho[k];
        e[k] = Q3[k];
        p[k] = e[k] * rho[k] * (GAMMA - 1);
    }
    return;
}