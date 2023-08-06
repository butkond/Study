#include "minimum.h"

int main (int argc, char *argv[]) 
{
    double a, b, eps, res1, res2, res3, res4, res5;
    int n, fn, tr = 0;  
    res_t p;
    fun_t fs[16] = {f1,  f2,  f3,  f4,
                    f5,  f6,  f7,  f8,
                    f9,  f10, f11, f12,
                    f13, f14, f15, f16};
    
    if(argc == 1) 
    {
        erro(0);
        return -1;
    }
    if((argc < 6) || (argc > 7)) 
    {
        erro(5);
        return -1;
    }
    if(!toDouble(argv[2], &a))
    {
        erro(1);
        return -1;
    } 
    if(!toDouble(argv[3], &b))
    {
        erro(2);
        return -1;
    }
    if(!toDouble(argv[4], &eps))
    {
        erro(3);
        return -1;
    } 
    if((!toInt(argv[1], &fn)) || (fn < 1) || (fn > 16))
    {
        erro(4);
        return -1;
    }
    if((!toInt(argv[5], &n)) || (n < 1))
    {
        erro(6);
        return -1;
    }   
    if(argc == 7)
    {
        char* trace = "trace"; 
        if(strcmp(argv[6], trace) == 0)
        {
            tr = 1;
        } else
        {    
            erro(10);
            return -1;
        }
    }
    
    parabola(fs[fn-1], a, b, eps, n, tr, &p);
    
    if(p.st == -1)
    {
        erro(7);
        return -1;
    }
    if(p.st == -2)
    {
        erro(8);
        return -1;
    }
    if(p.st == -3)
    {
        erro(9);
        return -1;
    }
     
    res1 = sqrt(M_PI);
    res2 = sqrt(2*M_PI);
    res3 = M_PI;
    res4 = 2*M_PI;
    res5 = (5 + sqrt(7))/3;

    printf("status                   : %d\n", p.st);
    printf("xmin                     : %.15e\n", p.x);
    printf("f(xmin)                  : %.15e\n", p.fx);
    printf("n                        : %d\n", p.n);
    printf("|xmin - sqrt(Pi)|        : %.15e\n", fabs (p.x - res1));
    printf("|xmin - sqrt(2Pi)|       : %.15e\n", fabs (p.x - res2)); 
    printf("|xmin - Pi|              : %.15e\n", fabs (p.x - res3));
    printf("|xmin - 2Pi|             : %.15e\n", fabs (p.x - res4));
    printf("|xmin - (5 + sqrt(7))/3| : %.15e\n", fabs (p.x - res5));         
    
    return 0;
}

void erro (int m) 
{
    int i;
    char name[16][32] = {"x(x - 2)", "|f1(x)|", "g(f1(x))", "|x^3|", "x(x - 2)(x - 3)",
                         "|f5(x)|", "g(f5(x))", "|sin(x^2)|", "g(sin(x^2))",
                         "|e^0.1x sin(x)|", "g(e^0.1x sin(x))", "-5x^5+4x^4-12x^3+11x^2-2x+1",
                         "-ln^2(x-2) + ln^2(10-x) - x^0.2", "-3 x sin(0.75x) + e^(-2x)",
                         "e^3x + 5e^(-2x)", "0.2 x ln(x) + (x - 2.3)^2"};
    
        if (m == 0)
        {
           printf("\nUsage: ./prog fn a b e N [trace]\n");        
           printf("fn:\n");
           for (i = 0; i < 16; i++) 
           {
               fprintf(stderr, "%2d -   %s\n", i+1, name[i]);
           } 
           fprintf(stderr, "\n       g(x) = x, if x > 0");
           fprintf(stderr, "\n       g(x) = 0, if x <= 0\n");     
        } else if (m == 1)
        {
            fprintf (stderr, "Incorrect value of a\n");
        } else if (m == 2)
        {
            fprintf (stderr, "Incorrect value of b\n");
        } else if (m == 3)
        {
            fprintf (stderr, "Incorrect value of eps\n");
        } else if (m == 4)
        {
            fprintf (stderr, "Incorrect number of test\n");
        } else if (m == 5)
        {
            fprintf (stderr, "Incorrect number of arguments\n");
        } else if (m == 6)
        {
            fprintf (stderr, "Incorrect number of steps\n");
        } else if (m == 7)
        {
            fprintf (stderr, "Try a < b, eps > 0\n");
        } else if (m == 8)
        {
            fprintf (stderr, "Limit of steps\n");
        } else if (m == 9)
        {
            fprintf (stderr, "Can't calculate min of function\n");
        } else if (m == 10)
        {
            fprintf (stderr, "Incorrect value of trace\n");
        }
    return;
}

int toDouble (const char *s, double *xp) 
{
    char *e;
    
    errno = 0;
    *xp = strtod (s, &e);
    
    if (!errno && *e == '\0') 
    {
        return 1; 
    }
    
    return 0; 
}


int toInt (const char *s, int *xp) 
{
    char *e;
    long l;
    
    errno = 0;
    l = strtol (s, &e, 10);
    
    if (!errno && *e == '\0') 
    {
        if (INT_MIN <= l && l <= INT_MAX) 
        {
            *xp = (int) l;
            return 1; 
        }
    }
    
    return 0; 
}
