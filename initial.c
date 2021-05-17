#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "initial.h"

void initialValue(void){
    for(int k=0; k<split/2; k++){
        rho[k] = RHO_0;
        p[k] = P_0;
        u[k] = U_0;
    }
    for(int k=split/2; k<split; k++){
        rho[k] = RHO_N;
        p[k] = P_N;
        u[k] = U_N;
    }
    return;
}