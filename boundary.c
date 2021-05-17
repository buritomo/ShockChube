#include <stdio.h>
#include "global.h"
#include "boundary.h"

void boundaryValue(void){
    rho[0] = RHO_0;
    rho[split-1] = RHO_N;

    return;
}