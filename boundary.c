#include <stdio.h>
#include "global.h"
#include "boundary.h"

void boundaryValue(void){
    for(int ky=0; ky<x_split; ky++){
        rho[0 + ky * x_split] = rho_0;
        rho[1 + ky* x_split] = rho_0;
        rho[(x_split-1) + ky * x_split] = rho_N;
        rho[(x_split-2) + ky * x_split] = rho_N;
    }

    return;
}