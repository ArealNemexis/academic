#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
} vertice;

typedef struct queueItem
{
    int value;
    struct queueItem *prox;
    struct queueItem *anterior;
} queueItem;

typedef struct queue
{
    struct queueItem *comeco;
    struct queueItem *fim;
} queue;



queue *alocaQueue();
queueItem *alocaItem(int value);
void push(queue *q, int value);
int pop(queue *q);
int isEmpty(queue *q);
void bfs(vertice *vertices, int qtd_vertices, int raiz, int dist);


int distancias[1000] = {0};

int main(int argc, char const *argv[])
{
    int qtd_vertices, qtd_arestas, i,a,b;
    vertice *vertices;
    
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }
    bfs(vertices, qtd_vertices, 1, 0);
    for(i = 1; i <= qtd_vertices; i++){
        printf("%d %d\n", i, distancias[i]);
    }

    return 0;
}

queue *alocaQueue()
{
    return (queue *)calloc(1, sizeof(queue));
}

queueItem *alocaItem(int value)
{
    queueItem *new = (queueItem *)calloc(1, sizeof(queueItem));
    new->value = value;
    return new;
}

void push(queue *q, int value)
{
    queueItem *new = alocaItem(value);
    if (q->comeco == NULL)
    {
        q->comeco = new;
        q->fim = new;
    }
    else
    {
        // q->comeco->anterior = new;
        // new->prox = q->comeco;
        // q->comeco = new;
        q->fim->prox = new;
        q->fim = new;
    }
}

int pop(queue *q)
{
    if (q->fim == NULL)
    {
        return -1;
    }
    else
    {
        queueItem *aux = q->comeco;
        int retorno = aux->value;
        q->comeco = aux->prox;
        free(aux);
        return retorno;
    }
}
void bfs(vertice *vertices, int qtd_vertices, int raiz, int dist)
{
    
    queue *q = alocaQueue();
    distancias[raiz] = dist;

    push(q, raiz);
    while (isEmpty(q) != 1)
    {
        int atual = pop(q);
        vertices[atual].visitado = 1;

        for (int i = 0; i < vertices[atual].tam_lista_adj; i++)
        {
            int filhoAtual = vertices[atual].lista_adj[i];

            if(vertices[filhoAtual].visitado == 0){
                distancias[filhoAtual] = distancias[atual] + 1;
                push(q, filhoAtual);
                vertices[filhoAtual].visitado = 1;
            }
        }
    }
}

int isEmpty(queue *q)
{
    return (q->comeco == NULL && q->comeco == NULL) ? 1 : 0;
}