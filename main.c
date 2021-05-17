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
    defineXYgrid();
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAssumedPotential();

    while(time <= TIME_MAX){
        if(fabs(time - 0.05) < 0.000001){
            printf("here!\n");
        }
        makePotential();
        fdsX();
        fdsY();
        rungekutta();
        /*
        for(int k=1;k<split-1;k++){
            Q1[k] = Q1[k] - TIME_STEP / X_STEP * (Ehalf1[k] - Ehalf1[k-1]);
            Q2[k] = Q2[k] - TIME_STEP / X_STEP * (Ehalf2[k] - Ehalf2[k-1]);
            Q3[k] = Q3[k] - TIME_STEP / X_STEP * (Ehalf3[k] - Ehalf3[k-1]);
            Q4[k] = Q4[k] - TIME_STEP / X_STEP * (Ehalf4[k] - Ehalf4[k-1]);
        }//*/
        inversePotentialToParams();
        boundaryValue();
        time = time + TIME_STEP;
        printTimer();
        export();
        for(int k=0; k<split; k++){
            if(isnan(rho[k])){
                printf("Not a number!\n");
                printf("%lf, %d\n", time, k);
                ErrorExport(rho);
                exit(1);
            }
        }
        if(rho[50] < rho[51]){
            printf("Inverse is here!\n");
        }
        if(time > 0.011568){
            printf("next is problem?\n");
        }
    }
    printf("All calculation is finished.\n");
    export();
    releaseAssumedPotential();
    freeGrid();
    return 0;
}
