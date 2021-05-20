#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "output.h"

void export(void){
    char filename[100];
    int step_cnt = (time / time_step);
    int max_step_cnt = (int)(time_max / time_step / 10);

    if(step_cnt % max_step_cnt == 0){
        FILE *fp;
        sprintf(filename, "Time%.3fsec.csv", time);

        fp = fopen(filename, "w");
        //fprintf(fp, "TIME = %.8f\n", time);
        //fprintf(fp, "x, rho, p, u, e, H, c\n");
        for(int kx=0; kx<x_split; kx++){
            for(int ky=0; ky<y_split; ky++){
                //fprintf(fp, "%.8f, %.8f, %.8f, %.8f, %.8f, %.8f, %.8f\n", area[k], rho[k], p[k], u[k], e[k], H[k], c[k]);
                int k = kx + ky * x_split;
                fprintf(fp, "%.8f, ", rho[k]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }

    return;
}

void ErrorExport(void){
    FILE *fp;

    fp = fopen("errorData.csv", "w");
    //fprintf(fp, "TIME = %.8f\n", time);
    fprintf(fp, "x, rho, p, u, e, H, c\n");
    for(int k=0; k<split; k++){
        fprintf(fp, "%.8f, %.8f, %.8f, %.8f, %.8f, %.8f, %.8f\n", area[k], rho[k], p[k], u[k], e[k], H[k], c[k]);
    }
    fclose(fp);

    return;
}