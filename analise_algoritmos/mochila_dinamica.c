#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int mochila_dinamica(int W, int pesos[], int valores[], int qtd_mochila);
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

    printf("\n");
    mochila_dinamica(50, pesos, valores, tam);
    return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }

int mochila_dinamica(int W, int pesos[], int valores[], int qtd_mochila)
{
    int w;
    int **tabelinha_da_maldade = (int **)malloc(sizeof(int*)*(qtd_mochila + 1));

    for(int i = 0; i < qtd_mochila + 1; i++){
        tabelinha_da_maldade[i] = (int *)malloc(sizeof(int)*(W + 1));
    }
 
    for (int i = 0; i <= qtd_mochila; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                tabelinha_da_maldade[i][w] = 0;
            else if (pesos[i - 1] <= w)
                tabelinha_da_maldade[i][w] = max(valores[i - 1]
                          + tabelinha_da_maldade[i - 1][w - pesos[i - 1]],
                          tabelinha_da_maldade[i - 1][w]);
            else
                tabelinha_da_maldade[i][w] = tabelinha_da_maldade[i - 1][w];
        }
    }
 
    int resposta = tabelinha_da_maldade[qtd_mochila][W];

    printf("\npodemos levar %d\nos itens são: ", resposta);
     
    w = W;
    for (int i = qtd_mochila; i > 0 && resposta > 0; i--) {
         
        if (resposta == tabelinha_da_maldade[i - 1][w])
            continue;       
        else {
            printf("%d ", pesos[i - 1]);
            resposta = resposta - valores[i - 1];
            w = w - pesos[i - 1];
        }
    }
    printf("\n");
}


void mostrar_vetor(int *vet, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf(" %d", vet[i]);
    }
}