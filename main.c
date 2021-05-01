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
    calcInternalEnergy();

    while(time < TIME_MAX){
        makePotential();

        inversePotentialToParams();
        time += TIME_STEP;
    }



    freeGrid();
    return 0;
}
