#include "minimum.h"

void parabola(fun_t f, double a, double b, double eps, int N, int tr, res_t *p)
{
    int n = -1;
    double dx, dx1, dx2, df, df1, df2, f1, f2, f3;
    double x, x1, e, c , d, z;
    
    if ((a - b >= 0) || (eps <= 0))
    {
        p->st = -1;
        fprintf(stderr, "Status : %d\n", p->st);
        return;
    }   

    if (tr != 0)
    {
        printf(" n   |          xm           |          dx           |          df          \n");
        printf("____________________________________________________________________________\n");
    }

    x = (a + b)/2;
    e = (a + b)/2;
    
    do
    {
        n += 1;
        if (n > N)
        {
            p->st = -2;
            fprintf(stderr, "Status : %d\n", p->st);
            return;
        }

        x1 = x;
        
        f1 = f(a);
        f2 = f(e);
        f3 = f(b);

        dx1 = e - a;
        dx2 = e - b;
        df1 = f2 - f1;
        df2 = f2 - f3;
        z = dx1*df2 - dx2*df1;
        
        if (z == 0)
        {
            p->st = -3;
            fprintf(stderr, "Status : %d\n", p->st);
            return; 
        }
        
        x = e - (dx1*dx1*df2 - dx2*dx2*df1) / (2*z);
        
        if ((x - b > 0) || (x - a < 0))
        { 
            p->st = -3;
            fprintf(stderr, "Status : %d\n", p->st);
            return;
        }
        
        dx = fabs(x1 - x);
        df = fabs(f(x1) - f(x)); 
        
        if (tr != 0)
        {
            printf("%3d  | %2.15e | %2.15e | %2.15e\n", n, x1, dx, df);
        } 
        
        if (e - x > 0)
        {
            c = x;
            d = e;
        } else
        {
            c = e;
            d = x;
        }

        if (f(c) - f(d) < 0)
        {
            b = d;
            e = c;
        } else
        {
            a = c;
            e = d;
        }

        p->x = x;
        p->fx = f(x);
        p->n = n;   
    } while (dx - eps >= 0);

    p->st = 0;
    return;
}
