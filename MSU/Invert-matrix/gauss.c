#include "gauss.h"
#define  A(i, j) a[(indi[i])*n + j]
#define  B(i, j) b[(indi[i])*n + j]
#define  EPS 1e-15

int gauss(double *a, double *b, double *x, int *indi, int n)
{
    int i, j, k, max, tmp;
    double sum, max_element;

    // Инициализация массива индексов строк
    for(i = 0; i < n; i++) indi[i] = i;   
    
    // Инициализация единичной матрицы B
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j) B(i, j) = 1;
            else       B(i, j) = 0;            
        }
    }

    // Прямой ход метода Гаусса
    for(j = 0; j < n; j++) 
    {
        // Сортировка строк по наибольшему элементу j-го столбца
        max = j;
        
        for(i = j + 1; i < n; i++) 
        {
            if(fabs(A(i, j)) > fabs(A(max, j))) 
                max = i;
        }

        tmp = indi[j];
        indi[j] = indi[max];
        indi[max] = tmp;

        // Деление j-й строки на найденный наибольший элемент j-го столбца
        max_element = A(j, j);

        // Проверка на вырожденность
        if(fabs(max_element) < EPS) return -1;
        
        for(i = 0; i < n; i++) 
        {
            A(j, i) /= max_element;
            B(j, i) /= max_element;
        }

        // Обнуление остальных элементов j-го столбца
        // Соответсвующие преобразования с остальными элементами матриц A и B
        for(k = j + 1; k < n; k++) 
        {
            max_element = A(k, j);
            
            for(i = 0; i < n; i++) 
            {
                A(k, i) -= A(j, i) * max_element;
                B(k, i) -= B(j, i) * max_element;
            }
        }

    }

    // Обратный ход
    for(k = 0; k < n; k++)
    {
        x[(n - 1)*n + k] = B(n - 1, k);
        
        for(i = n - 2; i >= 0; i--)
        {
            sum = 0;
            
            for(j = i + 1; j < n; j++)
                sum += A(i, j) * x[j*n + k];

            x[i*n + k] = B(i, k) - sum;
        }
    }

    return 0;
}
