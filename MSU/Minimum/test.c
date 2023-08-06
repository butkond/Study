#include "minimum.h"

double g (double x)
{
    if(x > 0)
    {
        return x;
    } else return 0;
} 
double f1  (double x) { return x*(x-2); }
double f2  (double x) { return fabs(f1(x)); }
double f3  (double x) { return g(f1(x)); }
double f4  (double x) { return x*x*x; }
double f5  (double x) { return x*(x-2)*(x-3); }
double f6  (double x) { return fabs(f5(x)); }
double f7  (double x) { return g(f5(x)); }
double f8  (double x) { return fabs(sin(x*x)); }
double f9  (double x) { return g(sin(x*x)); }
double f10 (double x) { return fabs(pow(M_E, 0.1*x)*sin(x)); }
double f11 (double x) { return g(pow(M_E, 0.1*x)*sin(x)); }
double f12 (double x) { return -5*x*x*x*x*x+4*x*x*x*x-12*x*x*x+11*x*x-2*x+1; }
double f13 (double x) { return -log(x-2)*log(x-2)+log(10-x)*log(10-x)-pow(x, 0.2); }
double f14 (double x) { return -3*x*sin(0.75*x)+pow(M_E, -2*x); }
double f15 (double x) { return pow(M_E, 3*x)+5*pow(M_E, -2*x); }
double f16 (double x) { return 0.2*x*log(x)+(x-2.3)*(x-2.3); }
