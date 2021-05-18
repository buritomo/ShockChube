#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "fds.h"


void fdsXdir(void){

    for(int kx=1; kx<x_split-1; kx++){
        for(int ky=0; ky<y_split; ky++){
            int k = kx + ky * x_split;
            muscl(&rho_L, &rho_R, rho, k, X_DIR);
            muscl(&u_L, &u_R, u, k, X_DIR);
            muscl(&v_L, &v_R, v, k, X_DIR);
            muscl(&p_L, &p_R, p, k, X_DIR);
            muscl(&e_L, &e_R, e, k, X_DIR);
            muscl(&H_L, &H_R, H, k, X_DIR);
            muscl(&c_L, &c_R, c, k, X_DIR);

            RoeAverage();

            b1 = (u_ave * u_ave + v_ave * v_ave) / 2 * (GAMMA - 1) / c_ave / c_ave;
            b2 = (GAMMA - 1) / c_ave / c_ave;
            RightArrayXdir(R, k);
            LeftArrayXdir(L, k);
            LambdaXdir(lambda, k);
            musclArrayXdir();
            for(int l=0; l<4; l++){
                for(int m=0; m<4; m++){
                    w[l + 4*m] = 0.0;
                    for(int n=0; n<4; n++){
                        w[l+4*m] = w[l+4*m] + R[l+4*n] * lambda[n] * L[n+4*m];
                    }
                }
            }
            Ehalf1[k] = 0.5 * (E_L[0] + E_R[0] - w[0+4*0] * (Q_R[0] - Q_L[0]) - w[0+4*1] * (Q_R[1] - Q_L[1]) - w[0+4*2] * (Q_R[2] - Q_L[2]) - w[0+4*3] * (Q_R[3] - Q_L[3]));
            Ehalf2[k] = 0.5 * (E_L[1] + E_R[1] - w[1+4*0] * (Q_R[0] - Q_L[0]) - w[1+4*1] * (Q_R[1] - Q_L[1]) - w[1+4*2] * (Q_R[2] - Q_L[2]) - w[1+4*3] * (Q_R[3] - Q_L[3]));
            Ehalf3[k] = 0.5 * (E_L[2] + E_R[2] - w[2+4*0] * (Q_R[0] - Q_L[0]) - w[2+4*1] * (Q_R[1] - Q_L[1]) - w[2+4*2] * (Q_R[2] - Q_L[2]) - w[2+4*3] * (Q_R[3] - Q_L[3]));
            Ehalf4[k] = 0.5 * (E_L[3] + E_R[3] - w[3+4*0] * (Q_R[0] - Q_L[0]) - w[3+4*1] * (Q_R[1] - Q_L[1]) - w[3+4*2] * (Q_R[2] - Q_L[2]) - w[3+4*3] * (Q_R[3] - Q_L[3]));
        }
    }

    return;
}

void RightArrayXdir(double *R, int k){
    R[0 + 4 * 0] = 1;
    R[0 + 4 * 1] = 1;
    R[0 + 4 * 2] = 1;
    R[0 + 4 * 3] = 0;
    R[1 + 4 * 0] = u_ave - c_ave;
    R[1 + 4 * 1] = u_ave;
    R[1 + 4 * 2] = u_ave + c_ave;
    R[1 + 4 * 3] = 0;
    R[2 + 4 * 0] = v_ave;
    R[2 + 4 * 1] = v_ave;
    R[2 + 4 * 2] = v_ave;
    R[2 + 4 * 3] = 1;
    R[3 + 4 * 0] = H_ave - u_ave * c_ave;
    R[3 + 4 * 1] = 0.5 * (u_ave * u_ave + v_ave * v_ave);
    R[3 + 4 * 2] = H_ave + u_ave * c_ave;
    R[3 + 4 * 3] = v_ave;

    return;
}

void LeftArrayXdir(double *L, int k){
    L[0 + 4 * 0] = 0.5 * (b1 + u_ave / c_ave);
    L[0 + 4 * 1] = -0.5 * (1 / c_ave +  b2 * u_ave);
    L[0 + 4 * 2] = -0.5 * b2 * v_ave;
    L[0 + 4 * 3] = 0.5 * b2;
    L[1 + 4 * 0] = 1 - b1;
    L[1 + 4 * 1] = b2 * u_ave;
    L[1 + 4 * 2] = b2 * v_ave;
    L[1 + 4 * 3] = -1 * b2;
    L[2 + 4 * 0] = 0.5 * (b1 - u_ave / c_ave);
    L[2 + 4 * 1] = 0.5 * (1 / c_ave -  b2 * u_ave);
    L[2 + 4 * 2] = -0.5 * b2 * v_ave;
    L[2 + 4 * 3] = 0.5 * b2;
    L[3 + 4 * 0] = -1 * v_ave;
    L[3 + 4 * 1] = 0;
    L[3 + 4 * 2] = 1;
    L[3 + 4 * 3] = 0;

    return;  
}

void LambdaXdir(double *lambda, int k){
    lambda[0] = fabs(u_ave - c_ave);
    lambda[1] = fabs(u_ave);
    lambda[2] = fabs(u_ave + c_ave);
    lambda[3] = fabs(u_ave);

    return;
}


void fdsYdir(void){

    for(int kx=0; kx<x_split; kx++){
        for(int ky=1; ky<y_split-1; ky++){
            int k = kx + ky * x_split;
            muscl(&rho_L, &rho_R, rho, k, Y_DIR);
            muscl(&u_L, &u_R, u, k, Y_DIR);
            muscl(&v_L, &v_R, v, k, Y_DIR);
            muscl(&p_L, &p_R, p, k, Y_DIR);
            muscl(&e_L, &e_R, e, k, Y_DIR);
            muscl(&H_L, &H_R, H, k, Y_DIR);
            muscl(&c_L, &c_R, c, k, Y_DIR);

            RoeAverage();

            b1 = (u_ave * u_ave + v_ave * v_ave) / 2 * (GAMMA - 1) / c_ave / c_ave;
            b2 = (GAMMA - 1) / c_ave / c_ave;
            RightArrayYdir(R, k);
            LeftArrayYdir(L, k);
            LambdaYdir(lambda, k);
            musclArrayYdir();
            
            for(int l=0; l<4; l++){
                for(int m=0; m<4; m++){
                    w[l + 4*m] = 0.0;
                    for(int n=0; n<4; n++){
                        w[l+4*m] = w[l+4*m] + R[l+4*n] * lambda[n] * L[n+4*m];
                    }
                }
            }
            /*
           for(int l=0; l<3; l++){
               for(int m=0; m<3; m++){
                   w[l + 3 * m] = 0.0;
                   for(int n=0; n<3; n++){
                       w[l+3*m] = w[l+3*m] + R[l+3*n] * lambda[n] * L[n+3*m];
                   }
               }
           }*/
           /*
            Fhalf1[k] = 0.5 * (F_L[0] + F_R[0] - w[0+4*0] * (Q_R[0] - Q_L[0]) - w[0+4*1] * (Q_R[1] - Q_L[1]) - w[0+4*2] * (Q_R[2] - Q_L[2]) - w[0+4*3] * (Q_R[3] - Q_L[3]));
            Fhalf2[k] = 0.5 * (F_L[1] + F_R[1] - w[1+4*0] * (Q_R[0] - Q_L[0]) - w[1+4*1] * (Q_R[1] - Q_L[1]) - w[1+4*2] * (Q_R[2] - Q_L[2]) - w[1+4*3] * (Q_R[3] - Q_L[3]));
            Fhalf3[k] = 0.5 * (F_L[2] + F_R[2] - w[2+4*0] * (Q_R[0] - Q_L[0]) - w[2+4*1] * (Q_R[1] - Q_L[1]) - w[2+4*2] * (Q_R[2] - Q_L[2]) - w[2+4*3] * (Q_R[3] - Q_L[3]));
            Fhalf4[k] = 0.5 * (F_L[3] + F_R[3] - w[3+4*0] * (Q_R[0] - Q_L[0]) - w[3+4*1] * (Q_R[1] - Q_L[1]) - w[3+4*2] * (Q_R[2] - Q_L[2]) - w[3+4*3] * (Q_R[3] - Q_L[3]));
            */

           for(int l=0; l<4; l++){
               Fhalf[k + split * l] = 0.5 * (F_L[l] + F_R[l]);
               for(int m=0; m<4; m++){
                   Fhalf[k+split*l] = Fhalf[k+split*l] - 0.5 * w[l+4*m] * (Q_R[m] - Q_L[m]);
               }

           }
        
        
        }
    }

    return;
}

void RightArrayYdir(double *R, int k){
    R[0 + 4 * 0] = 1;
    R[0 + 4 * 1] = 1;
    R[0 + 4 * 2] = 1;
    R[0 + 4 * 3] = 0;
    R[1 + 4 * 0] = u_ave;
    R[1 + 4 * 1] = u_ave;
    R[1 + 4 * 2] = u_ave;
    R[1 + 4 * 3] = 1;
    R[2 + 4 * 0] = v_ave - c_ave;
    R[2 + 4 * 1] = v_ave;
    R[2 + 4 * 2] = v_ave + c_ave;
    R[2 + 4 * 3] = 0;
    R[3 + 4 * 0] = H_ave - v_ave * c_ave;
    R[3 + 4 * 1] = 0.5 * (u_ave * u_ave + v_ave * v_ave);
    R[3 + 4 * 2] = H_ave + v_ave * c_ave;
    R[3 + 4 * 3] = u_ave;
    /*
    R[0 + 3 * 0] = 1;
    R[0 + 3 * 1] = 1;
    R[0 + 3 * 2] = 1;
    R[1 + 3 * 0] = v_ave - c_ave;
    R[1 + 3 * 1] = v_ave;
    R[1 + 3 * 2] = v_ave + c_ave;
    R[2 + 3 * 0] = H_ave - c_ave * v_ave;
    R[2 + 3 * 1] = 0.5 * v_ave * v_ave;
    R[2 + 3 * 2] = H_ave + c_ave * v_ave;
    */
    return;
}

void LeftArrayYdir(double *L, int k){
    
    L[0 + 4 * 0] = 0.5 * (b1 + v_ave / c_ave);
    L[0 + 4 * 1] = -0.5 * b2 * u_ave;
    L[0 + 4 * 2] = -0.5 * (1 / c_ave +  b2 * v_ave);
    L[0 + 4 * 3] = 0.5 * b2;
    L[1 + 4 * 0] = 1 - b1;
    L[1 + 4 * 1] = b2 * u_ave;
    L[1 + 4 * 2] = b2 * v_ave;
    L[1 + 4 * 3] = -1 * b2;
    L[2 + 4 * 0] = 0.5 * (b1 - v_ave / c_ave);
    L[2 + 4 * 1] = -0.5 * b2 * u_ave;
    L[2 + 4 * 2] = 0.5 * (1 / c_ave -  b2 * v_ave);
    L[2 + 4 * 3] = 0.5 * b2;
    L[3 + 4 * 0] = -1 * u_ave;
    L[3 + 4 * 1] = 1;
    L[3 + 4 * 2] = 0;
    L[3 + 4 * 3] = 0;
    /*
   L[0 + 3 * 0] = 0.5 * (b1 + v_ave / c_ave);
   L[0 + 3 * 1] = -0.5 * (1 / c_ave + b2 * v_ave);
   L[0 + 3 * 2] = 0.5 * b2;
   L[1 + 3 * 0] = 1 - b1;
   L[1 + 3 * 1] = b2 * v_ave;
   L[1 + 3 * 2] = -b2;
   L[2 + 3 * 0] = 0.5 * (b1 - v_ave);
   L[2 + 3 * 1] = 0.5 * (1 / c_ave - b2 * v_ave);
   L[2 + 3 * 2] = 0.5 * b2; 
    */
    return;  
}

void LambdaYdir(double *lambda, int k){
    lambda[0] = fabs(v_ave - c_ave);
    lambda[1] = fabs(v_ave);
    lambda[2] = fabs(v_ave + c_ave);
    lambda[3] = fabs(v_ave);

    return;
}

void RoeAverage(void){
    rho_ave = sqrt(rho_L * rho_R);
    u_ave = (sqrt(rho_L) * u_L + sqrt(rho_R) * u_R) / ((sqrt(rho_L) + sqrt(rho_R)));
    v_ave = (sqrt(rho_L) * v_L + sqrt(rho_R) * v_R) / ((sqrt(rho_L) + sqrt(rho_R)));
    H_ave = (sqrt(rho_L) * H_L + sqrt(rho_R) * H_R) / ((sqrt(rho_L) + sqrt(rho_R)));
    c_ave = sqrt((GAMMA - 1) * (H_ave - 0.5 * (u_ave * u_ave + v_ave * v_ave)));

    return;
}

void muscl(double *left, double *right, double *value, int k, int dir){
    int delta;
    if(dir == X_DIR){
        delta = 1;
    }
    else{
        delta = x_split;
    }

    double delta_j_plus = value[k+delta] - value[k];
    double delta_j_minus = value[k] - value[k-delta];
    double delta_J1_plus = value[k+2*delta] - value[k+delta];
    double b = (3 - KAPPA) / (1 - KAPPA);

    *left = value[k] + EPSILON / 4 * ((1 - KAPPA) * (limiter(delta_j_minus, b * delta_j_plus)) + (1 + KAPPA) * (limiter(delta_j_plus, b * delta_j_minus)));
    *right = value[k+delta] - EPSILON / 4 * ((1 + KAPPA) * (limiter(delta_j_plus, b * delta_J1_plus)) + (1 - KAPPA) * (limiter(delta_J1_plus, b * delta_j_plus)));

    return;
}

void musclArrayXdir(void){
    Q_L[0] = rho_L;
    Q_L[1] = rho_L * u_L;
    Q_L[2] = rho_L * v_L;
    Q_L[3] = e_L;

    Q_R[0] = rho_R;
    Q_R[1] = rho_R * u_R;
    Q_R[2] = rho_R * v_R;
    Q_R[3] = e_R;

    E_L[0] = rho_L * u_L;
    E_L[1] = p_L + rho_L * u_L * u_L;
    E_L[2] = rho_L * u_L * v_L;
    E_L[3] = (e_L + p_L) * u_L;

    E_R[0] = rho_R * u_R;
    E_R[1] = p_R + rho_R * u_R * u_R;
    E_R[2] = rho_R * u_R * v_R;
    E_R[3] = (e_R + p_R) * u_R;

    return;
}

void musclArrayYdir(void){
    Q_L[0] = rho_L;
    Q_L[1] = rho_L * u_L;
    Q_L[2] = rho_L * v_L;
    Q_L[3] = e_L;

    Q_R[0] = rho_R;
    Q_R[1] = rho_R * u_R;
    Q_R[2] = rho_R * v_R;
    Q_R[3] = e_R;

    F_L[0] = rho_L * v_L;
    F_L[1] = rho_L * u_L * v_L;
    F_L[2] = rho_L * v_L * v_L + p_L;
    F_L[3] = (e_L + p_L) * v_L;

    F_R[0] = rho_R * v_R;
    F_R[1] = rho_R * u_R * v_R;
    F_R[2] = rho_R * v_R * v_R + p_R;
    F_R[3] = (e_R + p_R) * v_R;

    return;
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