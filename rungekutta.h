#ifndef RUNGEKUTTA_H_
    #define RUNGEKUTTA_H_

    static double *k1;
    static double *k2;
    static double *k3;
    static double *k4;
    static double *kari;
    
    void setAssumedPotential(void);
    void releaseAssumedPotential(void);
    void rungekutta(void);



#endif //RUNGEKUTTA_H_