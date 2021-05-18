#include <stdio.h>
#include "global.h"
#include "read.h"

void areaSet(void){
    x_split = 1 / X_STEP;
    y_split = 1 / Y_STEP;
    split = x_split * y_split;
    return;
}