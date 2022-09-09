#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
} vertice;

void mostrar_tudo(vertice *vertices, int qtd_vertices);
void dfs(vertice *vertices, int qtd_vertices, int raiz);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i, a, b, qtd_cc = 0;
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


    // dfs_bipartido(vertices, qtd_vertices, 0, corInicial);
    // mostrar_tudo(vertices,qtd_vertices);

    int quantidadeVisitados = 0;
    int arrayQtdGrupos[qtd_vertices];
    int indiceQtdGrupos = 0;

    for(int i = 1; i <= qtd_vertices; i++){
        arrayQtdGrupos[i] = 1;
    }
    for(i=1;i<=qtd_vertices;i++)
    {
        if (vertices[i].visitado==0)
        {
            dfs(vertices,qtd_vertices,i);
            qtd_cc++;
            int contagemAtual = 0;
            for(int j = 1; j <= qtd_vertices;j++){
                if(vertices[j].visitado == 1){
                    contagemAtual++;
                    // vertices[j].visitado == -1;
                }
            }
            if (quantidadeVisitados == 0){
                arrayQtdGrupos[indiceQtdGrupos] = contagemAtual;
                quantidadeVisitados = contagemAtual;
            }
            else {
                arrayQtdGrupos[indiceQtdGrupos] = abs(quantidadeVisitados - contagemAtual);
                quantidadeVisitados = contagemAtual;
            }
            // arrayQtdGrupos[indiceQtdGrupos] = contagemAtual;
            indiceQtdGrupos++;
        }
    }
    int qtdChefes = 1;
    for(int i = 0; i < indiceQtdGrupos; i++){
        qtdChefes *= arrayQtdGrupos[i];
    }

    // for(int i = 1; i <= qtd_vertices; i++){
    //     printf("%d %d\n", i, arrayQtdGrupos[i]);
    // }
    printf("%d %d\n", qtd_cc, qtdChefes);

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
