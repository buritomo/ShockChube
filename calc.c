#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"

void calcInternalValues(void){
    for(int k=0; k<x_split; k++){
        e[k] = rho[k] * (p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * u[k] * u[k]);
        c[k] = sqrt(GAMMA * p[k] / rho[k]);
        H[k] = GAMMA * p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * u[k] * u[k];
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
        p[k] = (e[k] - 0.5 * rho[k] * u[k] * u[k]) *  (GAMMA - 1);
        c[k] = sqrt(GAMMA * p[k] / rho[k]);
        H[k] = GAMMA * p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * u[k] * u[k];
        if(isnan(c[k])){
            printf("Error C is here!\n");
        }
    }
    return;
}

void printTimer(void){
    if((time - time_flag) > (TIME_MAX / 100)){
        double rate = time / TIME_MAX * 100;
        printf("%.1f %% is finished....\n", rate);
        time_flag = time;
    }
    return;
}