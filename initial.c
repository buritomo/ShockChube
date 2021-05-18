#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "initial.h"

void initialValue(void){
    for(int kx=0; kx<x_split; kx++){
        for(int ky=0; ky<y_split/2; ky++){
            int k = kx + ky * x_split;
            rho[k] = RHO_0;
            p[k] = P_0;
            u[k] = U_0;
            v[k] = V_0;
        }
    }
    for(int kx=0; kx<x_split; kx++){
        for(int ky=y_split/2; ky<y_split; ky++){
            int k = kx + ky * x_split;
            rho[k] = RHO_N;
            p[k] = P_N;
            u[k] = U_N;
            v[k] = V_N;
        }
    }
    return;
}