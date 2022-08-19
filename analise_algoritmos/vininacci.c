 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "omp.h"

void fibonacci_recursivo(long long int x, long long int y, long long int z, long long int soma_t);
void fibonacci_iterativo(int n);

int main()
{
    
    long long int soma_t = 0, x = 1, y = 1;
    int n = 0;
    double t1, t2;

    printf("\nDigite o N-esimo termo que voce deseja: ");
    scanf("%d", &n);
   
   t1 = omp_get_wtime();

    // fibonacci_iterativo(n);

    n -= 2;
    fibonacci_recursivo(n, x, y, soma_t);

    t2 = omp_get_wtime();

    printf("\nTempo gasto: %f segundos", t2 - t1);
}

void fibonacci_recursivo(long long int x, long long int y, long long int z, long long int soma_t)
{   
    soma_t = y + z;

    if (x == 1)
    {
        printf("\nRecursivo - N-esimo termo da serie do Fibonacci: %lld", soma_t);
        return;
    }

    y = z;
    z = soma_t;
    fibonacci_recursivo(x - 1, y, z, soma_t);
}

void fibonacci_iterativo(int n){

    long long int soma_t = 0, x = 1, y = 1;

    for (int i = 3; i <= n; i++)
    {
        soma_t = x + y;
        if (i == n)
        {
            printf("\nIterativo - N-esimo termo da serie do Fibonacci: %lld", soma_t);
            break;
        }
        x = y;
        y = soma_t;
    }

}