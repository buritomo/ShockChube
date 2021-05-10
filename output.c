#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "output.h"

void export(void){
    char filename[100];
    int step_cnt = (time / TIME_STEP);

    if(step_cnt % 10000 == 0){
        FILE *fp;
        sprintf(filename, "Time%.3fsec.csv", time);

        fp = fopen(filename, "w");
        //fprintf(fp, "TIME = %.8f\n", time);
        fprintf(fp, "x, rho, p, u, e, H, c\n");
        for(int k=0; k<x_split; k++){
            fprintf(fp, "%.8f, %.8f, %.8f, %.8f, %.8f, %.8f, %.8f\n", area[k], rho[k], p[k], u[k], e[k], H[k], c[k]);
        }
        fclose(fp);

    }

    return;
}