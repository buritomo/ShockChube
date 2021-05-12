#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "initial.h"

void initialValue(void){
    for(int kx=0; kx<x_split/2; kx++){
        for(int ky=0; ky<y_split; ky++){
            rho[kx + ky * x_split] = RHO_0;
            p[kx + ky * x_split] = P_0;
            u[kx + ky * x_split] = U_0;
            v[kx + ky * x_split] = V_0;
        }
    }
    for(int kx=x_split/2; kx<x_split; kx++){
        for(int ky=0; ky<y_split; ky++){
            rho[kx + ky * x_split] = RHO_N;
            p[kx + ky * x_split] = P_N;
            u[kx + ky * x_split] = U_N;
            v[kx + ky * x_split] = V_N;
        }
    }
    return;
}