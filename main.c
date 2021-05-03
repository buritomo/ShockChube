#include <stdio.h>
#include <stdlib.h>

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
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAverage();
    setAssumedPotential();

    while(time < TIME_MAX){
        makePotential();
        fds();
        rungekutta();
        inversePotentialToParams();
        time = time + TIME_STEP;
        printTimer();
    }
    export();
    releaseAssumedPotential();
    releaseAverage();
    freeGrid();
    return 0;
}
