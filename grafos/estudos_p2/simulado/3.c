#include <stdio.h>
#include <stdlib.h>
int count = 1;

typedef struct elemento
{
    int vertice;
    int distancia;
} elemento;

int qtd_global[10001];
int count_min_heap = 0;
elemento heap[1000];

typedef struct vertice
{
    int visitado;
    int distancia;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
} vertice;

int min(int x, int y)
{
    return x < y ? x : y;
}

int define_filho_esquerda(int indice)
{
    return indice * 2;
}

int define_filho_direita(int indice)
{
    return (indice * 2) + 1;
}

int define_pai(int indice)
{
    return indice / 2;
}

void subir_minimo(int indice)
{

    elemento aux;

    if (indice <= 1)
        return;

    int pai = define_pai(indice);

    if (heap[indice].distancia < heap[pai].distancia)
    {
        aux = heap[indice];
        heap[indice] = heap[pai];
        heap[pai] = aux;
        subir_minimo(pai);
    }
}

void desce_minimo(int indice)
{
    if (indice * 2 > count_min_heap)
        return;

    int esquerda = define_filho_esquerda(indice);
    int direita = define_filho_direita(indice);

    int menor = indice;

    if (esquerda <= count_min_heap && heap[esquerda].distancia < heap[menor].distancia)
    {
        menor = esquerda;
    }

    if (direita <= count_min_heap && heap[direita].distancia < heap[menor].distancia)
    {
        menor = direita;
    }

    if (menor == indice)
        return;

    elemento aux;

    aux = heap[indice];
    heap[indice] = heap[menor];
    heap[menor] = aux;
    desce_minimo(menor);
}

int push_fila(elemento x)
{
    count_min_heap++;
    heap[count_min_heap] = x;
    subir_minimo(count_min_heap);
}

elemento pop()
{
    elemento retorno;
    if (count_min_heap == 0)
    {
        retorno.distancia = -1;
        retorno.vertice = -1;
        return retorno;
    }

    retorno = heap[1];
    // printf("\n %d",heap[1]);
    heap[1] = heap[count_min_heap];
    count_min_heap--;
    desce_minimo(1);
    return retorno;
}

int empty()
{
    if (count_min_heap == 0)
        return 1;
    else
        return 0;
}

void djikstra(vertice *vertices, int raiz)
{

    int corrente, distancia_atual;
    elemento elemento_aux;
    // registro *aux;

    inicializar_distancias(vertices);

    vertices[raiz].distancia = 0;
    elemento_aux.distancia = 0;
    elemento_aux.vertice = raiz;
    push_fila(elemento_aux);

    while (!empty())
    {
        elemento_aux = pop();
        corrente = elemento_aux.vertice;
        distancia_atual = elemento_aux.distancia;
        // printf("\n Processando vertice %d Distancia atual  %d",corrente,distancia_atual);

        if (vertices[corrente].tam_lista_adj)
        {
            printf("\n Vertice em componente desconetado");
            return;
        }

        for (int i = 0; i < vertices[corrente].tam_lista_adj; i++)
        {
            int filhoAtual = vertices[corrente].lista_adj[i];
            if (distancia_atual + vertices[corrente])
            {
                /* code */
            }
            
        }
        // aux = vertices[corrente].lista_adj->inicio;
        // while (aux != NULL)
        // {
        //     if (distancia_atual + aux->peso < vertices[aux->valor].distancia)
        //     {
        //         vertices[aux->valor].distancia = distancia_atual + aux->peso;
        //         elemento_aux.distancia = vertices[aux->valor].distancia;
        //         elemento_aux.vertice = aux->valor;
        //         push_fila(elemento_aux);
        //     }
        //     aux = aux->prox;
        // }
    }
}
