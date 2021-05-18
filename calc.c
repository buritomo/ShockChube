#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"

void calcInternalValues(void){
    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;
            e[k] = rho[k] * (p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]));
            c[k] = sqrt(GAMMA * p[k] / rho[k]);
            H[k] = GAMMA * p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]);
        }
    }
    return;
}

void makePotential(void){
    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;
            Q1[k] = rho[k];
            Q2[k] = rho[k] * u[k];
            Q3[k] = rho[k] * v[k];
            Q4[k] = e[k];
        }
    }

    return;
}

void inversePotentialToParams(void){
    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;

            rho[k] = Q1[k];
            u[k] = Q2[k] / rho[k];
            v[k] = Q3[k] / rho[k];
            e[k] = Q4[k];
            p[k] = (e[k] - 0.5 * rho[k] * (u[k] * u[k] + v[k] * v[k])) *  (GAMMA - 1);
            c[k] = sqrt(GAMMA * p[k] / rho[k]);
            H[k] = GAMMA * p[k] / (rho[k] * (GAMMA - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]);
            if(isnan(c[k])){
                printf("Error C is here!\n");
            }
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