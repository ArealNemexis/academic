#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
} vertice;

int cc = 0;
int min(int a, int b) { return a < b ? a : b; }
void dfs_ponte(vertice *vertices, int raiz, int pai);

int main()
{
    int n, m, a, b, i;
    vertice *vertices;
    scanf("%d %d", &n, &m);

    vertices = (vertice *)calloc(n + 1, sizeof(vertice));
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);

        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;

        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }

    dfs_ponte(vertices, 1, 1);
}

void dfs_ponte(vertice *vertices, int raiz, int pai)
{

    if (vertices[raiz].visitado == 1)
    {
        return;
    }

    vertices[raiz].visitado = 1;
    vertices[raiz].in = cc;
    vertices[raiz].lower = cc;
    cc++;

    for (int i = 0; i < vertices[raiz].tam_lista_adj; i++)
    {
        int filhoAtual = vertices[raiz].lista_adj[i];

        if (filhoAtual == pai)
        {
            continue;
        }

        if (vertices[filhoAtual].visitado == 0)
        { // forward edge
            dfs_ponte(vertices, filhoAtual, raiz);
        }
        else
        {
            if (vertices[filhoAtual].visitado == 1 && filhoAtual != pai)
            { // backedge
                vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].in);
            }
        }

        if (vertices[filhoAtual].lower > vertices[raiz].in)
        {
            printf("ponte %d %d\n", filhoAtual, raiz);
        }

        vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].lower);
    }
}