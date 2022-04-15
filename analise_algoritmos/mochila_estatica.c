#include <stdio.h>
#include <stdlib.h>
int max(int a, int b);
int mochilinha_recursivamente_falando(int W, int pesos[], int valores[], int qtd_mochila);
void mostrar_vetor(int *vet, int tamanho);

int main()
{
    int lixeira_chamada_java, lixeira_chamada_php, tam = 0, *pesos, *valores, valor;
    char lixo;
    FILE *uvloop = fopen("casos2.txt", "r");

    printf("Programa feito por um funcionário da AutomatizAI ALTAMENTE CAPACITADO\n\n#felippePagaORodizioPraNos\n\n\n");

    printf("Lendo o arquivo, entrarei em um uvloop\n");
    while (!feof(uvloop))
    {
        fscanf(uvloop, "%d%c%d", &lixeira_chamada_java, &lixo, &lixeira_chamada_php);
        tam++;
    }

    printf("Li o arquivo, fim do uvloop\n");

    fseek(uvloop, 0, SEEK_SET);

    pesos = (int *)malloc(sizeof(int)*tam);
    valores = (int *)malloc(sizeof(int)*tam);

    for(int i = 0; i < tam;i++){
        fscanf(uvloop, "%d%c%d", &pesos[i], &lixo, &valores[i]);
    }

    printf("\nDigite o valor desejado: ");
    scanf("%d", &valor);


    printf("\npesos  : ");
    mostrar_vetor(pesos, tam);
    printf("\nvalores: ");
    mostrar_vetor(valores, tam);

    printf("\nvalor possivel %d\n", mochilinha_recursivamente_falando(valor, pesos, valores, tam));
    
    
    return 0;
}

void mostrar_vetor(int *vet, int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf(" %d", vet[i]);
    }
}


int max(int a, int b) { return (a > b) ? a : b; }

int mochilinha_recursivamente_falando(int W, int pesos[], int valores[], int qtd_mochila)
{

    if (qtd_mochila == 0 || W == 0)
        return 0;

    if (pesos[qtd_mochila - 1] > W)
        return mochilinha_recursivamente_falando(W, pesos, valores, qtd_mochila - 1);
 
    else
        return max(
            valores[qtd_mochila - 1]
                + mochilinha_recursivamente_falando(W - pesos[qtd_mochila - 1],
                           pesos, valores, qtd_mochila - 1),
            mochilinha_recursivamente_falando(W, pesos, valores, qtd_mochila - 1));
}