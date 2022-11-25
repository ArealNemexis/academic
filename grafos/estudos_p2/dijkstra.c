#include <stdio.h>
#include <stdlib.h>


typedef struct elemento
{
    int vertice;
    int distancia;
} elemento;

typedef struct vertice
{
    int visitado;
    int lista_adj[1001];
    int tam_lista_adj;
    int in;
    int lower;
} vertice;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;


elemento heap[1000];

int filho_esquerda(int indice) {
    return indice * 2;
}

int filho_direita(int indice) {
    return (indice * 2) + 1;
}

int define_pai(int indice) {
    return indice / 2;
}

int min(int a, int b) return a < b ? a : b;

void subir_minimo(int indice) {
    if(indice <= 1)
        return;
    
    int pai = define_pai(indice);

    if(heap[indice].distancia < heap[pai].distancia){
        
    }
}