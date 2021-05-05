#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "fds.h"


void fds(void){
    double b1, b2;
    double R[3*3];
    double L[3*3];
    double lambda[3];
    double w[3*3];

    RoeAverage();

    for(int k=0; k<x_split-1; k++){
        b1 = u_ave[k] * u_ave[k] / 2 * (GAMMA - 1) / c_ave[k] / c_ave[k];
        b2 = (GAMMA - 1) / c_ave[k] / c_ave[k];
        RightArray(R, b1, b2, k);
        LeftArray(L, b1, b2, k);
        Lambda(lambda, k);
        for(int l=0; l<3; l++){
            for(int m=0; m<3; m++){
                w[l + 3*m] = 0.0;
                for(int n=0; n<3; n++){
                    w[l+3*m] = w[l+3*m] + R[l+3*n] * lambda[n] * L[n+3*m];
                }
            }
        }
        Ehalf1[k] = 0.5 * (E1[k] + E1[k+1] - w[0+3*0] * (Q1[k+1] - Q1[k]) - w[0+3*1] * (Q2[k+1] - Q2[k]) - w[0+3*2] * (Q3[k+1] - Q3[k]));
        Ehalf2[k] = 0.5 * (E2[k] + E2[k+1] - w[1+3*0] * (Q1[k+1] - Q1[k]) - w[1+3*1] * (Q2[k+1] - Q2[k]) - w[1+3*2] * (Q3[k+1] - Q3[k]));
        Ehalf3[k] = 0.5 * (E3[k] + E3[k+1] - w[2+3*0] * (Q1[k+1] - Q1[k]) - w[2+3*1] * (Q2[k+1] - Q2[k]) - w[2+3*2] * (Q3[k+1] - Q3[k]));
    }

    return;
}

void setAverage(void){
    rho_ave = (double * )malloc(sizeof(double) * x_split);
    u_ave = (double * )malloc(sizeof(double) * x_split);
    c_ave = (double * )malloc(sizeof(double) * x_split);
    H_ave = (double * )malloc(sizeof(double) * x_split);

    return;
}

void releaseAverage(void){
    free(rho_ave);
    free(u_ave);
    free(c_ave);
    free(H_ave);
    return;
}

void RoeAverage(void){
    for(int k=0; k<x_split-1; k++){
        rho_ave[k] = sqrt(rho[k] * rho[k+1]);
        u_ave[k] = (sqrt(rho[k]) * u[k] + sqrt(rho[k+1]) * u[k+1]) / ((sqrt(rho[k]) + sqrt(rho[k+1])));
        H_ave[k] = (sqrt(rho[k]) * H[k] + sqrt(rho[k+1]) * H[k+1]) / ((sqrt(rho[k]) + sqrt(rho[k+1])));
        c_ave[k] = sqrt((GAMMA - 1) * (H_ave[k] - 0.5 * u_ave[k] * u_ave[k]));
    }
    return;
}

void RightArray(double *R, double b1, double b2, int k){
    R[0 + 3 * 0] = 1;
    R[0 + 3 * 1] = 1;
    R[0 + 3 * 2] = 1;
    R[1 + 3 * 0] = u_ave[k] - c_ave[k];
    R[1 + 3 * 1] = u_ave[k];
    R[1 + 3 * 2] = u_ave[k] + c_ave[k];
    R[2 + 3 * 0] = H_ave[k] - u_ave[k] * c_ave[k];
    R[2 + 3 * 1] = 0.5 * u_ave[k] * u_ave[k];
    R[2 + 3 * 2] = H_ave[k] + u_ave[k] * c_ave[k];

    return;
}

void LeftArray(double *L, double b1, double b2, int k){
    L[0 + 3 * 0] = 0.5 * (b1 + u_ave[k] / c_ave[k]);
    L[0 + 3 * 1] = -0.5 * (1 / c_ave[k] +  b2 * u_ave[k]);
    L[0 + 3 * 2] = 0.5 * b2;
    L[1 + 3 * 0] = 1 - b1;
    L[1 + 3 * 1] = b2 * u_ave[k];
    L[1 + 3 * 2] = -1 * b2;
    L[2 + 3 * 0] = 0.5 * (b1 - u_ave[k] / c_ave[k]);
    L[2 + 3 * 1] = 0.5 * (1 / c_ave[k] -  b2 * u_ave[k]);
    L[2 + 3 * 2] = 0.5 * b2;

    return;  
}

void Lambda(double *lambda, int k){
    lambda[0] = abs(u_ave[k] - c_ave[k]);
    lambda[1] = abs(u_ave[k]);
    lambda[2] = abs(u_ave[k] + c_ave[k]);

    return;
}