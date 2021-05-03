#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "output.h"

void export(void){
    FILE *fp;

    fp = fopen("Density.csv", "w");
    fprintf(fp, "TIME = %.8f\n", time);
    for(int k=0; k<x_split; k++){
        fprintf(fp, "%.8f, %.8f, %.8f, %.8f\n", area[k], rho[k], p[k], u[k]);
    }
    fclose(fp);
    return;
}