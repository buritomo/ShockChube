#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAIN_C_

#include "global.h"
#include "grid.h"
#include "initial.h"
#include "boundary.h"
#include "read.h"
#include "fds.h"
#include "rungekutta.h"
#include "calc.h"
#include "output.h"

int main(void){
    areaSet();
    makeGrid();
    defineXgrid();
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAssumedPotential();

    while(time < TIME_MAX){
        makePotential();
        fds();
        //rungekutta();
        for(int k=1;k<x_split-1;k++){
            Q1[k] = Q1[k] - TIME_STEP / X_STEP * (Ehalf1[k] - Ehalf1[k-1]);
            Q2[k] = Q2[k] - TIME_STEP / X_STEP * (Ehalf2[k] - Ehalf2[k-1]);
            Q3[k] = Q3[k] - TIME_STEP / X_STEP * (Ehalf3[k] - Ehalf3[k-1]);
        }
        inversePotentialToParams();
        boundaryValue();
        time = time + TIME_STEP;
        printTimer();
        for(int k=0; k<x_split; k++){
            if(isnan(rho[k])){
                printf("Not a number!\n");
                printf("%lf, %d\n", time, k);
                export();
                exit(1);
            }
        }
    }
    export();
    releaseAssumedPotential();
    freeGrid();
    return 0;
}
