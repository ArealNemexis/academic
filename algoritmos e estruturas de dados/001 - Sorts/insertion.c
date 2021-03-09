#include <stdio.h>
#include <stdlib.h>
#define tam 100

int *allocAndGenerate();
void printArray(int *vet, int size,  char sep);

int main(int argc, char const *argv[])
{
    int *arr;

    arr = allocAndGenerate();

    printArray(arr, tam, ' ');

    return 0;
}

int *allocAndGenerate()
{
    int* aloc = (int *)malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++)
    {
        aloc[i] = rand() % tam;
    }

    return aloc;
}

void printArray(int *vet, int size, char sep){
    for(int i = 0; i < size; i++){
        printf("%d%c", vet[i], sep);
    }
    printf("\n");
}

void insertionSort(int *vet, int size){
    
}