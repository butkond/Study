#ifndef _GAUSS_H_
#define _GAUSS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int    gauss(double *a, double *b, double *x, int *indi, int n);
int    toDouble(const char *s, double *xp); 
void   erro(int m);
int    toInt(const char *s, int *xp);
void   fill(double *a, double c, double d, int n);
void   print_matrix(double *a, double *x, int n);
void   mult(double *a, double *x, double *b, int n);
double norm(double *b, double *e, int n);

#endif
