#include <stdio.h>
#include <stdlib.h>
#define numberHash 349
typedef struct registro REG;

struct registro
{
    int chave, ocorrencia;
    REG *prox;
};

// hash code gen
int hash(int chave, int NumberHash)
{
    return chave % NumberHash;
}

int main()
{
    REG **table;
    REG *tAux;
    int size;
    int aux;
    int h;

    scanf("%d", &size);
    table = malloc(size * sizeof(REG *));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &aux);
        h = hash(aux, numberHash);
        tAux = table[h];
        while (tAux != NULL && tAux->chave != aux)
        {
            tAux = tAux->prox;
        }
        if (tAux != NULL)
        {
            tAux->ocorrencia += 1;
        }
        else
        {
            tAux = malloc(sizeof(REG));
            tAux->chave = aux;
            tAux->ocorrencia = 1;
            tAux->prox = table[h];
            table[h] = tAux;
        }
    }
    return 0;
}