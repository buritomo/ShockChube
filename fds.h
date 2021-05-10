#ifndef FDS_H_
    #define FDS_H_

    static double b1, b2;
    static double Q_L[3];
    static double Q_R[3];
    static double E_L[3];
    static double E_R[3];
    static double R[3*3];
    static double L[3*3];
    static double lambda[3];
    static double w[3*3];
    static double rho_L, rho_R;
    static double u_L, u_R;
    static double e_L, e_R;
    static double p_L, p_R;
    static double H_L, H_R; 
    static double c_L, c_R;
    static double rho_ave;
    static double u_ave;
    static double e_ave;
    static double p_ave;
    static double H_ave;
    static double c_ave;

    void fds(void);
    void RoeAverage(void);
    void RightArray(double *R, int k);
    void LeftArray(double *L, int k);
    void Lambda(double *lambda, int k);
    void muscl(double *left, double *right, double *value, int k);
    void musclArray(void);
    double limiter(double x, double y);
    double max(double x, double y);
    double min(double x, double y);
    double sgn(double x);


#endif //FDS_H_