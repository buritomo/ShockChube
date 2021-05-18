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
    defineGrid();
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAssumedPotential();

    while(time <= TIME_MAX){
        makePotential();
        fdsXdir();
        fdsYdir();
        rungekutta();
        /*        
        for(int k=1;k<split-1;k++){
            Q1[k] = Q1[k] - TIME_STEP / Y_STEP * (Fhalf1[k] - Fhalf1[k-1]);
            Q2[k] = Q2[k] - TIME_STEP / Y_STEP * (Fhalf2[k] - Fhalf2[k-1]);
            Q3[k] = Q3[k] - TIME_STEP / Y_STEP * (Fhalf3[k] - Fhalf3[k-1]);
            Q4[k] = Q4[k] - TIME_STEP / Y_STEP * (Fhalf4[k] - Fhalf4[k-1]);
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
                ErrorExport();
                exit(1);
            }
        }
    }
    printf("All calculation is finished.\n");
    export();
    releaseAssumedPotential();
    freeGrid();
    return 0;
}
