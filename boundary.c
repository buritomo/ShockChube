#include <stdio.h>
#include "global.h"
#include "boundary.h"

void boundaryValue(void){
    for(int kx=0; kx<x_split; kx++){
        rho[kx + 0 * x_split] = RHO_0;
        rho[kx + (y_split-1) * x_split] = RHO_N;
    }
/*
    for(int ky=0; ky<y_split; ky++){
        rho[0 + ky * x_split] = RHO_0;
        rho[(x_split - 1) + ky * x_split] = RHO_N;
    }*/

    return;
}