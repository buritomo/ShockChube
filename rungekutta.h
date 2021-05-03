#ifndef RUNGEKUTTA_H_
    #define RUNGEKUTTA_H_

    static double *k1;
    static double *k2;
    static double *k3;
    
    void setAssumedPotential(void);
    void releaseAssumedPotential(void);
    void rungekutta(void);



#endif //RUNGEKUTTA_H_