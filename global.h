#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #define X_STEP    0.01
    #define Y_STEP    1
    #define TIME_STEP 0.000001
    #define GAMMA 1.4
    #define TIME_MAX  0.1
    #define MAX_STEP_CNT (int)(TIME_MAX / TIME_STEP / 10)

    #define RHO_0 1.0
    #define P_0 1.0
    #define U_0 0.0
    #define V_0 0.0
    #define RHO_N 0.125
    #define P_N 0.1
    #define U_N 0.0
    #define V_N 0.0

    #define KAPPA 1.0 / 3.0
    #define EPSILON 1.0

    #define X_DIR 1
    #define Y_DIR 2

    #ifdef MAIN_C_
    double *rho;
    double *u;
    double *v;
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
    double *Q4;
    double *E1;
    double *E2;
    double *E3;
    double *E4;
    double *F1;
    double *F2;
    double *F3;
    double *F4;
    double *Ehalf1;
    double *Ehalf2;
    double *Ehalf3;
    double *Ehalf4;
    double *Fhalf1;
    double *Fhalf2;
    double *Fhalf3;
    double *Fhalf4;
    volatile int x_split;
    volatile int y_split;
    volatile int split;

    #else
    extern double *rho;
    extern double *u;
    extern double *v;
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
    extern double *Q4;
    extern double *E1;
    extern double *E2;
    extern double *E3;
    extern double *E4;
    extern double *F1;
    extern double *F2;
    extern double *F3;
    extern double *F4;
    extern double *Ehalf1;
    extern double *Ehalf2;
    extern double *Ehalf3;
    extern double *Ehalf4;
    extern double *Fhalf1;
    extern double *Fhalf2;
    extern double *Fhalf3;
    extern double *Fhalf4;    extern volatile int x_split;
    extern volatile int y_split;
    extern volatile int split;

    #endif

#endif //GLOBAL_H_