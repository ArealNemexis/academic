#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int cor; // -1 none, 0 azul, 1 verde
} vertice;

void mostrar_tudo(vertice *vertices, int qtd_vertices);
void dfs(vertice *vertices, int qtd_vertices, int raiz);
void dfs_bipartido(vertice *vertices, int qtd_vertices, int raiz, int cor_pai);
int main()
{
    int corInicial = 0;
    int qtd_vertices, qtd_arestas;
    int i, a, b, qtd_cc = 0;
    vertice *vertices;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    for (i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;

        vertices[a].cor = -1;
        vertices[b].cor = -1;
    }


    dfs_bipartido(vertices, qtd_vertices, 0, corInicial);
    mostrar_tudo(vertices,qtd_vertices);

        // for(i=1;i<=qtd_vertices;i++)
        // {
        //     if (vertices[i].visitado==0)
        //     {
        //         dfs(vertices,qtd_vertices,i);
        //         qtd_cc++;
        //     }
        // }

        // printf("\n%d", qtd_cc);

    // dfs(vertices,qtd_vertices,1);

    return 0;
}

void mostrar_tudo(vertice *vertices, int qtd_vertices)
{
    int i, j;

    for (i = 1; i <= qtd_vertices; i++)
    {
        printf("\n Vertice: %d", i);
        printf("\n Cor: %d", vertices[i].cor);
        printf("\n Lista de adjacencias: ");

        for (j = 0; j < vertices[i].tam_lista_adj; j++)
        {
            printf("%d ", vertices[i].lista_adj[j]);
        }
    }
}

void dfs(vertice *vertices, int qtd_vertices, int raiz)
{
    int i;
    if (vertices[raiz].visitado != 0)
    {
        return;
    }

    // printf("\n %d",raiz);
    vertices[raiz].visitado = 1;

    for (i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado == 0)
        {
            dfs(vertices, qtd_vertices, vertices[raiz].lista_adj[i]);
        }
    }
}

void dfs_bipartido(vertice *vertices, int qtd_vertices, int raiz, int cor_pai)
{
    int i;
    if (vertices[raiz].visitado != 0) // ja foi visitado
    {
        return;
    }

    // printf("\n %d",raiz);
    vertices[raiz].visitado = 1;
    vertices[raiz].cor = !cor_pai;

    for (i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].visitado == 0)
        {
            dfs_bipartido(vertices, qtd_vertices, vertices[raiz].lista_adj[i], vertices[raiz].cor);
        }
        else
        {
            if (vertices[raiz].cor == vertices[vertices[raiz].lista_adj[i]].cor)
            {
                printf("erro, n eh bipartido");
            }
        }
    }
}