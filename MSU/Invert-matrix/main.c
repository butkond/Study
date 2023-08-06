#include "gauss.h"

int main(int argc, char *argv[]) 
{
    double  c, d, y, t1, t2, norm1, norm2;
    int     n, i, j, k, len, res1, res2;
    double  *a, *aa, *b, *x, *e;
    double  *a2, *b2, *x2, *e2, *aa2;
    int     *indi, *indi2;
    clock_t t_e, t_s;

    FILE *f;
    
    if(argc == 1)
    {
        erro(0);
        return -1;
    }
    
    if(argc == 3 || argc > 4) 
    {
        erro(1);
        return -1;

    } else if(argc == 2)
    {
        // Открытие файла в случае запуска программы с одним аргументом
        f = fopen(argv[1], "r");

        if(!f)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            return -1;
        }

        i = 0;
        while(fscanf(f, "%lf", &y) == 1)
        {
            i++;
        }

        if (!feof(f))
        {
            fprintf(stderr, "Incorrect data in file\n");
            fclose(f);            
            return -1;
        }

        rewind(f);
    
        // Проверка корректности количества элементов в файле
        c = sqrt(i);
        d = modf(c, &c);
        
        if(d != 0)
        {
            fprintf(stderr, "Incorrect data in file\n");
            fclose(f);            
            return -1;
        }

        n = c;

        indi  = (int*) malloc (n * sizeof(int));

        if(!indi)
        {
            fprintf(stderr, "Can't allocate memory\n");
            fclose(f);
            return -1;
        }    

        a = (double*) malloc (5 * n * n * sizeof(double));    

        if(!a)
        {
            fprintf(stderr, "Can't allocate memory\n");
            free(a);
            return -1;
        }

        len = n * n;

        aa   = a  + len;
        e    = aa + len;
        b    = e  + len;
        x    = b  + len;
        
        // Заполнение матрицы A из файла        
        for(i = 0; i < n*n; i++) 
        {    
            if(fscanf(f, "%lf", &a[i]) != 1) 
            {
                fclose (f);
                free(a);
                return -1;
            }
        }

        fclose(f);        

    } else if(argc == 4)
    {
        // Считывание параметров c, d, n в случае запуска программы с 3 аргументами
        if(!toDouble(argv[1], &c))
        {
            erro(2);
            return -1;
        }
        
        if(!toDouble(argv[2], &d))
        {
            erro(3);
            return -1;
        }        
        
        if(!toInt(argv[3], &n))
        {
            erro(4);
            return -1;
        }

        if(c == 0) 
        {
            erro(2);
            return -1;
        }

        if(n <= 0) 
        {
            erro(4);
            return -1;
        }

        indi  = (int*) malloc (3 * n * sizeof(int));

        if(!indi)
        {
            fprintf(stderr, "Can't allocate memory\n");
            return -1;
        }        

        indi2 = indi + n; 
        
        a = (double*) malloc (5 * n * n * sizeof(double));    

        if(!a)
        {
            fprintf(stderr, "Can't allocate memory\n");
            return -1;
        }    

        len = n * n;

        aa   = a  + len;
        e    = aa + len;
        b    = e  + len;
        x    = b  + len;

        a2 = (double*) malloc (20 * n * n * sizeof(double));    

        if(!a2)
        {
            fprintf(stderr, "Can't allocate memory\n");
            free(a);
            return -1;
        } 

        len = 4 * len; 

        b2   = a2 + len;
        x2   = b2 + len;
        e2   = x2 + len;
        aa2  = e2 + len;

        // Заполнение матрицы A порядка n по введенным параметрам c и d
        fill(a, c, d, n);

        // Заполнение матрицы A порядка 2n по введенным параметрам c и d
        fill(a2, c, d, 2 * n);       
    }

    // Инициализация единичной матрицы  (n x n)
    // Копирование матрицы A (n x n)
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j) e[i*n + j] = 1;
            else       e[i*n + j] = 0;         
            
            aa[i*n + j]= a[i*n + j];
        }
    }
    
    // Инициализация единичной матрицы  (2n x 2n)
    // Копирование матрицы A (2n x 2n)    
    if(argc == 4)
    {
        k = 2 * n;
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k; j++)
            {
                if(i == j) e2[i*k + j] = 1;
                else       e2[i*k + j] = 0;

                aa2[i*k + j] = a2[i*k + j];           
            }
        }        
    }

    // Нахождение обратной матрицы и вычисление времени выполнения процедуры  
    t_s  = clock();
    res1 = gauss(a, b, x, indi, n);
    t_e  = clock();

    t1 = (double)(t_e - t_s) / CLOCKS_PER_SEC;   
    
    // Обнуление элементов матрицы B (n x n) для записи в нее элементов матрицы AA* (n x n)
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j++) b[i*n + j] = 0;           
    }     

    res2 = 0;
    if(argc == 4)
    {
        t_s  = clock();
        res2 = gauss(a2, b2, x2, indi2, 2 * n);
        t_e  = clock();

        t2 = (double)(t_e - t_s) / CLOCKS_PER_SEC;
        
        k = 2 * n;
        // Обнуление элементов матрицы B (2n x 2n) для записи в нее элементов матрицы AA* (2n x 2n)
        for(i = 0; i < k; i ++)
        {
            for(j = 0; j < k; j++) b2[i*k + j] = 0;           
        } 
    }    

    if(res1 == 0 && res2 == 0)
    {        
        // Печать значения времени нахождения обратной матрицы
        if(argc == 2)
        {
            // Если n <= 10, то печатаются исходная матрица и обратная к ней
            if(n <= 10) print_matrix(aa, x, n);
            
            // Вычисление элементов матрицы AA* 
            mult(aa, x, b, n);

            // Вычисление точности приближения
            norm1 = norm(b, e, n);

            printf("Time (sec) : %.15e\n", t1);
            printf("||AA* - E||: %.15e\n", norm1);    
        } else
        {
            // Если n <= 10, то печатаются исходная матрица и обратная к ней
            if(n <= 10) print_matrix(aa, x, n);
            if(2 * n <= 10) print_matrix(aa2, x2, 2 * n);            
            
            // Вычисление элементов матрицы AA* (n x n)
            mult(aa, x, b, n); 

            // Вычисление элементов матрицы AA* (2n x 2n)
            mult(aa2, x2, b2, 2 * n);              

            printf("t1                   : %.15e\n", t1);
            printf("t2                   : %.15e\n", t2);
            printf("t2/t1                : %.15e\n", t2 / t1);                        
            
            // Вычисление точности приближения
            norm1 = norm(b, e, n);            
            norm2 = norm(b2, e2, 2 * n);

            printf("||AA* - E|| (n x n)  : %.15e\n", norm1);             
            printf("||AA* - E|| (2n x 2n): %.15e\n", norm2);       

            free(a2);
        }
        free(indi);
        free(a);   

        return 0;       
    } else
    {
        // Матрица A вырождена если res = -1
        fprintf(stderr, "detA = 0\n");  
        free(indi);
        free(a);
        free(a2);    
        
        return -1;
    }    
}

double norm(double *b, double *e, int n)
{
    int i, j;
    double sum, max = 0;
    
    for(i = 0; i < n; i ++)
    {
        sum = 0;

        for(j = 0; j < n; j++) 
        {
            sum += fabs(b[i*n + j] - e[i*n + j]);
        }

        if(max < sum) max = sum;
    }     

    return max;
}

void mult(double *a, double *x, double *b, int n)
{
    int i, j, k;
    
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j++)
        {    
            for(k = 0; k < n; k++) 
            {
                b[i*n + j] += a[i*n + k] * x[k*n + j]; 
            }
        }
    } 
}

void print_matrix(double *a, double *x, int n)
{
    int i, j;
    
    printf("A  (%d x %d):\n", n, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%.1lf ", a[i*n + j]);
        }
        printf("\n");
    }
    printf("\n");
        
    printf("A* (%d x %d):\n", n, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%.1lf ", x[i*n + j]);
        }
        printf("\n");
    }
    printf("\n"); 

    return;
}

void fill(double *a, double c, double d, int n)
{
    int i;

    for(i = 0; i < n * n; i++) 
    {
        a[i] = 0;
    }
    
    // Заполняем диагональ
    for(i = 0; i < n; i++) 
    {
        a[i * n + i] = d;
    }
    
    // Заполняем над диагональю
    for(i = 0; i < n - 1; i++) 
    {
        a[i * n + i + 1] = c;
    }
    
    // Заполняем под диагональю
    for(i = 1; i < n; i++) 
    {
        a[i * n + i - 1] = c;
    }

    return;
}

void erro (int m) 
{
    if (m == 0)
    {
        fprintf(stderr, "Usage: ./prog file\nUsage: ./prog c d n\n");             
    } else if (m == 1)
    {
        fprintf (stderr, "Incorrect number of arguments\n");
    } else if (m == 2)
    {
        fprintf (stderr, "Incorrect value of c\n");
    } else if (m == 3)
    {
        fprintf (stderr, "Incorrect value of d\n");
    } else if (m == 4)
    {
        fprintf (stderr, "Incorrect value of n\n");
    }

    return;
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
