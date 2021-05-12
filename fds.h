#ifndef FDS_H_
    #define FDS_H_

    static double b1, b2;
    static double Q_L[4];
    static double Q_R[4];
    static double E_L[4];
    static double E_R[4];
    static double F_L[4];
    static double F_R[4];
    static double R[4*4];
    static double L[4*4];
    static double lambda[4];
    static double w[3*3];
    static double rho_L, rho_R;
    static double u_L, u_R;
    static double v_L, v_R;
    static double e_L, e_R;
    static double p_L, p_R;
    static double H_L, H_R; 
    static double c_L, c_R;
    static double rho_ave;
    static double u_ave;
    static double v_ave;
    static double e_ave;
    static double p_ave;
    static double H_ave;
    static double c_ave;

    void fdsX(void);
    void fdsY(void);
    void RoeAverage(void);
    void xRightArray(double *R, int k);
    void xLeftArray(double *L, int k);
    void xLambda(double *lambda, int k);
    void yRightArray(double *R, int k);
    void yLeftArray(double *L, int k);
    void yLambda(double *lambda, int k);
    void muscl(double *left, double *right, double *value, int k, int dir);
    void musclArray(int dir);
    double limiter(double x, double y);
    double max(double x, double y);
    double min(double x, double y);
    double sgn(double x);


#endif //FDS_H_