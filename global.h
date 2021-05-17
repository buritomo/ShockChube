#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #define X_STEP    0.001
    #define TIME_STEP 0.00001
    #define GAMMA 1.4
    #define TIME_MAX  0.1
    #define MAX_STEP_CNT (int)(TIME_MAX / TIME_STEP / 10)

    #define RHO_0 1.0
    #define P_0 1.0
    #define U_0 0.0
    #define RHO_N 0.125
    #define P_N 0.1
    #define U_N 0.0

    #define KAPPA 1.0 / 3.0
    #define EPSILON 1.0

    #ifdef MAIN_C_
    double *rho;
    double *u;
    double *e;
    double *p;
    double *H;
    double *c;
    double *area;
    double time;
    double time_flag;
    double *Q1;
    double *Q2;
    double *Q3;
    double *E1;
    double *E2;
    double *E3;
    double *Ehalf1;
    double *Ehalf2;
    double *Ehalf3;
    volatile int split;

    #else
    extern double *rho;
    extern double *u;
    extern double *e;
    extern double *p;
    extern double *H;
    extern double *c;
    extern double *area;
    extern double time;
    extern double time_flag;
    extern double *Q1;
    extern double *Q2;
    extern double *Q3;
    extern double *E1;
    extern double *E2;
    extern double *E3;
    extern double *Ehalf1;
    extern double *Ehalf2;
    extern double *Ehalf3;
    extern volatile int split;

    #endif

#endif //GLOBAL_H_