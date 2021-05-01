#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #define X_STEP 0.00001
    #define TIME_STEP 0.00001
    #define GAMMA 1.4
    #define TIME_MAX 0.01

    #define RHO_0 1.0
    #define P_0 1.0
    #define U_0 0.0
    #define RHO_N 0.125
    #define P_N 0.1
    #define U_N 0.0

    #ifdef MAIN_C_
    volatile double *rho;
    volatile double *u;
    volatile double *e;
    volatile double *p;
    volatile double *area;
    volatile double time;
    volatile double *Q1;
    volatile double *Q2;
    volatile double *Q3;
    volatile double *E1;
    volatile double *E2;
    volatile double *E3;
    volatile double *Ehalf1;
    volatile double *Ehalf2;
    volatile double *Ehalf3;
    volatile int x_split;
    #else
    extern volatile double *rho;
    extern volatile double *u;
    extern volatile double *e;
    extern volatile double *p;
    extern volatile double *area;
    extern volatile double time;
    extern volatile double *Q1;
    extern volatile double *Q2;
    extern volatile double *Q3;
    extern volatile double *E1;
    extern volatile double *E2;
    extern volatile double *E3;
    extern volatile double *Ehalf1;
    extern volatile double *Ehalf2;
    extern volatile double *Ehalf3;
    extern volatile int x_split;
    #endif

#endif //GLOBAL_H_