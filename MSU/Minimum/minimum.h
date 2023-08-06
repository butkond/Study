#ifndef _MINIMUM_H_
#define _MINIMUM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define M_E 2.7182818284590452354
#define M_PI 3.14159265358979323846

typedef double (*fun_t)(double);

typedef struct {
    int    st;
    double x;
    double fx;
    int    n; 
} res_t;

void parabola(fun_t f, double a, double b, double eps, int N, int tr, res_t *p);

double g   (double x);
double f1  (double x);
double f2  (double x);
double f3  (double x);
double f4  (double x);
double f5  (double x);
double f6  (double x);
double f7  (double x);
double f8  (double x);
double f9  (double x);
double f10 (double x);
double f11 (double x);
double f12 (double x);
double f13 (double x);
double f14 (double x);
double f15 (double x);
double f16 (double x);

void erro     (int m);
int  toDouble (const char *s, double *xp);
int  toInt    (const char *s, int *xp);

#endif
