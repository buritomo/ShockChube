#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"

void fds(void){
    for(int k=0; k<x_split; k++){
        double c = sqrt(GAMMA * p[k] / rho[k]);
        double b1 = u[k] * u[k] / 2 * (GAMMA - 1) / c / c;
        double b2 = (GAMMA - 1) / c / c;
    }
}