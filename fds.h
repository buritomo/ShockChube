#ifndef FDS_H_
    #define FDS_H_

    static double *rho_ave;
    static double *u_ave; 
    static double *H_ave;
    static double *c_ave;

    void fds(void);
    void setAverage(void);
    void releaseAverage(void);
    void RoeAverage(void);
    void RightArray(double *R, double b1, double b2, int k);
    void LeftArray(double *L, double b1, double b2, int k);
    void Lambda(double *lambda, int k);


#endif //FDS_H_