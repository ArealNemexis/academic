#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int listAdj[1000];
    int tam_lista_adj;
    int in;
    int out;
} vertice;

void dfs(vertice *vertices, int qtd_vertices, int raiz);

int main(int argc, char const *argv[])
{
    int qtd_arestas, qtd_vertices, i, a, b;
    vertice *vertices;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].listAdj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].listAdj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    dfs(vertices, qtd_vertices, 1);

    return 0;
}

void dfs(vertice *vertices, int qtd_vertices, int raiz)
{
    int i;

    if (vertices[raiz].visitado == 1)
    {
        return;
    }

    vertices[raiz].visitado = 1;
    printf("%d -> ", raiz);

    for (i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].listAdj[i]].visitado == 0)
        {
            dfs(vertices, qtd_vertices, vertices[raiz].listAdj[i]);
        }
    }
}