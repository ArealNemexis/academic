#include <stdio.h>
#include <stdlib.h>

int subset_recursivo(int *vet, int n, int x, int y, int valor);
int *aloca_vetor(int tamanho);
void mostrar_vetor(int *vet, int tamanho);
int somatorio_vetor(int *vet, int tamanho);

int main(int argc, char const *argv[])
{
    int *vet, tam = 0, lixeira_chamada_java, valor, sum_vet;
    FILE *uvloop = fopen("casos.txt", "r");
    printf("Programa feito por um funcionário da AutomatizAI ALTAMENTE CAPACITADO\n\n#felippePagaORodizioPraNos\n\n\n");

    printf("Lendo o arquivo, entrarei em um uvloop\n");
    while (!feof(uvloop))
    {
        fscanf(uvloop, "%d", &lixeira_chamada_java);
        tam++;
    }

    printf("Li o arquivo, fim do uvloop\n");

    fseek(uvloop, 0, SEEK_SET);

    vet = (int *)malloc(sizeof(int)*tam);

    for(int i = 0; i < tam;i++){
        fscanf(uvloop, "%d", &vet[i]);
    }

    printf("\ndigite o valor desejado: ");
    scanf("%d", &valor);

    sum_vet = somatorio_vetor(vet, tam);
    if (subset_recursivo(vet, tam, 0, sum_vet, valor))
        printf("\nExiste Subset Sum, você me deve uma pizza");
    else
        printf("\nNão existe Subset Sum, você me deve uma pizza");

    printf("\n");
    return 0;
}

int subset_recursivo(int *vet, int n, int x, int y, int valor)
{
    if (n == -1)
        return 0;

    if (x + vet[n] == valor)
        return 1;

    return (subset_recursivo(vet, n - 1, x + vet[n], y - vet[n], valor) || subset_recursivo(vet, n - 1, x, y - vet[n], valor));
}

int *aloca_vetor(int tamanho)
{
    int *vet;
    int i;
    vet = (int *)calloc(tamanho, sizeof(int));

    vet[0] = 2;
    for (i = 1; i < tamanho; i++)
    {
        vet[i] = vet[i - 1] + 1 + rand() % 3;
    }

    return vet;
}

int somatorio_vetor(int *vet, int tamanho)
{
    int i;
    int som = 0;
    for (i = 0; i < tamanho; i++)
    {
        som = som + vet[i];
    }
    return som;
}