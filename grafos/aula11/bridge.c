#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
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

int min(int a, int b)
{
    return a < b ? a : b;
}
queue *alocaQueue();
queueItem *alocaItem(int value);
void push(queue *q, int value);
int pop(queue *q);
int isEmpty(queue *q);
void bfs(vertice *vertices, int qtd_vertices, int raiz, int dist);
void dfs(vertice *vertices, int qtd_vertices, int raiz, int pai);
int cc = 0;

int distancias[1000] = {0};

int main(int argc, char const *argv[])
{
    int qtd_vertices, qtd_arestas, i, a, b;
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

    dfs(vertices, qtd_vertices, 1, 1);

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

            if (vertices[filhoAtual].visitado == 0)
            {
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

void dfs(vertice *vertices, int qtd_vertices, int raiz, int pai)
{
    int i;
    if (vertices[raiz].visitado != 0)
    {
        return;
    }

    // printf("\n %d",raiz);
    vertices[raiz].visitado = 1;
    vertices[raiz].in = cc;
    vertices[raiz].lower = cc;
    cc++;

    for (i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        int filhoAtual = vertices[raiz].lista_adj[i];
        if (filhoAtual == pai)
        {
            continue;
        }
        if (vertices[filhoAtual].visitado == 0)
        {
            dfs(vertices, qtd_vertices, filhoAtual, raiz);
        }
        else
        {
            if (vertices[filhoAtual].visitado == 1 && filhoAtual != pai)
            {
                // printf("backedge %d %d\n", raiz, filhoAtual);
                vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].in);
            }
        }

        // if verifica ponte 
        if (vertices[filhoAtual].lower > vertices[raiz].in)
        {
            printf("ponte %d %d\n", raiz, filhoAtual);
        }
        //sempre pos ponte
        vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].lower);
    }
}