#include <stdio.h>
#include <stdlib.h>
#define tam 10

int *allocAndGenerate()
{
    int *aloc = (int *)malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++)
    {
        aloc[i] = rand() % tam;
    }

    return aloc;
}

void printArray(int *vet, int size, char sep)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d%c", vet[i], sep);
    }
    printf("\n");
}

int divide(int *arr, int inicio, int fim)
{
    int pivo = arr[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++)
    {

        if (arr[j] < pivo)
        {
            i++;
            int aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
    int aux = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = aux;

    return (i + 1);
}

void quickSort(int *arr, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = divide(arr, inicio, fim);

        quickSort(arr, inicio, meio - 1);
        quickSort(arr, meio + 1, fim);
    }
}

int main(int argc, char const *argv[])
{

    int *arr;

    arr = allocAndGenerate();

    printArray(arr, tam, ' ');
    quickSort(arr, 0, tam - 1);
    printArray(arr, tam, ' ');

    return 0;
}
