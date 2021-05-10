#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "fds.h"


void fds(void){

    for(int k=0; k<x_split-1; k++){
        muscl(&rho_L, &rho_R, rho, k);
        muscl(&e_L, &e_R, e, k);
        muscl(&p_L, &p_R, p, k);
        muscl(&H_L, &H_R, H, k);
        muscl(&c_L, &c_R, c, k);

        RoeAverage();

        b1 = u_ave * u_ave / 2 * (GAMMA - 1) / c_ave / c_ave;
        b2 = (GAMMA - 1) / c_ave / c_ave;
        RightArray(R, k);
        LeftArray(L, k);
        Lambda(lambda, k);
        musclArray();
        for(int l=0; l<3; l++){
            for(int m=0; m<3; m++){
                w[l + 3*m] = 0.0;
                for(int n=0; n<3; n++){
                    w[l+3*m] = w[l+3*m] + R[l+3*n] * lambda[n] * L[n+3*m];
                }
            }
        }
        Ehalf1[k] = 0.5 * (E_L[0] + E_R[0] - w[0+3*0] * (Q_R[0] - Q_L[0]) - w[0+3*1] * (Q_R[1] - Q_L[1]) - w[0+3*2] * (Q_R[2] - Q_L[2]));
        Ehalf2[k] = 0.5 * (E_L[1] + E_R[1] - w[1+3*0] * (Q_R[0] - Q_L[0]) - w[1+3*1] * (Q_R[1] - Q_L[1]) - w[1+3*2] * (Q_R[2] - Q_L[2]));
        Ehalf3[k] = 0.5 * (E_L[2] + E_R[2] - w[2+3*0] * (Q_R[0] - Q_L[0]) - w[2+3*1] * (Q_R[1] - Q_L[1]) - w[2+3*2] * (Q_R[2] - Q_L[2]));
    }

    return;
}

void RoeAverage(void){
    rho_ave = sqrt(rho_L * rho_R);
    u_ave = (sqrt(rho_L) * u_L + sqrt(rho_R) * u_R) / ((sqrt(rho_L) + sqrt(rho_R)));
    H_ave = (sqrt(rho_L) * H_L + sqrt(rho_R) * H_R) / ((sqrt(rho_L) + sqrt(rho_R)));
    c_ave = sqrt((GAMMA - 1) * (H_ave - 0.5 * u_ave * u_ave));

    return;
}

void RightArray(double *R, int k){
    R[0 + 3 * 0] = 1;
    R[0 + 3 * 1] = 1;
    R[0 + 3 * 2] = 1;
    R[1 + 3 * 0] = u_ave - c_ave;
    R[1 + 3 * 1] = u_ave;
    R[1 + 3 * 2] = u_ave + c_ave;
    R[2 + 3 * 0] = H_ave - u_ave * c_ave;
    R[2 + 3 * 1] = 0.5 * u_ave * u_ave;
    R[2 + 3 * 2] = H_ave + u_ave * c_ave;

    return;
}

void LeftArray(double *L, int k){
    L[0 + 3 * 0] = 0.5 * (b1 + u_ave / c_ave);
    L[0 + 3 * 1] = -0.5 * (1 / c_ave +  b2 * u_ave);
    L[0 + 3 * 2] = 0.5 * b2;
    L[1 + 3 * 0] = 1 - b1;
    L[1 + 3 * 1] = b2 * u_ave;
    L[1 + 3 * 2] = -1 * b2;
    L[2 + 3 * 0] = 0.5 * (b1 - u_ave / c_ave);
    L[2 + 3 * 1] = 0.5 * (1 / c_ave -  b2 * u_ave);
    L[2 + 3 * 2] = 0.5 * b2;

    return;  
}

void Lambda(double *lambda, int k){
    lambda[0] = abs(u_ave - c_ave);
    lambda[1] = abs(u_ave);
    lambda[2] = abs(u_ave + c_ave);

    return;
}

void muscl(double *left, double *right, double *value, int k){
    double delta_j_plus = value[k+1] - value[k];
    double delta_j_minus = value[k] - value[k-1];
    double delta_J1_plus = value[k+2] - value[k-1];
    double b = (3 - KAPPA) / (1 - KAPPA);

    *left = value[k] + EPSILON / 4 * ((1 - KAPPA) * (limiter(delta_j_minus, b * delta_j_plus)) + (1 + KAPPA) * (limiter(delta_j_plus, b * delta_j_minus)));
    *right = value[k+1] - EPSILON / 4 * ((1 + KAPPA) * (limiter(delta_j_plus, b * delta_J1_plus)) + (1 - KAPPA) * (limiter(delta_J1_plus, b * delta_j_plus)));

    return;
}

void musclArray(void){
    Q_L[0] = rho_L;
    Q_L[1] = rho_L * u_L;
    Q_L[2] = e_L;

    Q_R[0] = rho_R;
    Q_R[1] = rho_R * u_L;
    Q_R[2] = e_R;

    E_L[0] = rho_L * u_L;
    E_L[1] = p_L + rho_L * u_L * u_L;
    E_L[2] = (e_L + p_L) * u_L;

    E_R[0] = rho_R * u_R;
    E_R[1] = p_R + rho_R * u_R * u_R;
    E_R[2] = (e_R + p_R) * u_R;
}

double limiter(double x, double y){
    return (sgn(x) * max(0, min(abs(x), sgn(x) * y)));
}

double max(double x, double y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}

double min(double x, double y){
    if(x > y){
        return y;
    }
    else{
        return x;
    }
}

double sgn(double x){
    if(x > 0){
        return 1.0;
    }
    else if(x < 0){
        return -1.0;
    }
    else{
        return 0.0;
    }
}