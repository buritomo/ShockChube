#include <stdio.h>
#include "global.h"
#include "boundary.h"

void boundaryValue(void){
    for(int ky=0; ky<y_split; ky++){
        rho[0 + ky * x_split] = RHO_0;
        rho[(x_split - 1) + ky * x_split] = RHO_N;
    }
    return;
}