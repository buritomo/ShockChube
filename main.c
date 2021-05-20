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
    inputSetting();
    inputInitialValue();
    areaSet();
    makeGrid();
    defineGrid();
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAssumedPotential();

    while(time <= time_max){
        makePotential();
        fdsXdir();
        fdsYdir();
        rungekutta();
        inversePotentialToParams();
        boundaryValue();
        time = time + time_step;
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
