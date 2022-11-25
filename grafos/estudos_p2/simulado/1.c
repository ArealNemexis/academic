#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_list_adj;
    int in;
    int lower;
} vertice;
int cc = 0;

void dfs_ponte(vertice *vertices, int raiz, int pai);
int min(int a, int b) {return a < b ? a : b;}

int main()
{
    int n, m, i, a, b;
    vertice *vertices;

        scanf("%d %d", &n, &m);

    vertices = (vertice *)calloc(n + 1, sizeof(vertice));

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);

        vertices[a].lista_adj[vertices[a].tam_list_adj] = b;
        vertices[a].tam_list_adj++;
        vertices[b].lista_adj[vertices[b].tam_list_adj] = a;
        vertices[b].tam_list_adj++;
    }

    dfs_ponte(vertices, 1, 1);
}

void dfs_ponte(vertice *vertices, int raiz, int pai)
{
    if (vertices[raiz].visitado != 0)
    {
        return;
    }
    vertices[raiz].visitado = 1;
    vertices[raiz].in = cc;
    vertices[raiz].lower = cc;
    cc++;

    /*
    se é o pai n faz nada
    se n foi visitado é um forward edge
    se foi visitado e n é o pai eh um backedge
    */
    for (int i = 0; i < vertices[raiz].tam_list_adj; i++)
    {
        int filhoAtual = vertices[raiz].lista_adj[i];

        if (filhoAtual == pai)
        {
            continue;
        }
        if (vertices[filhoAtual].visitado == 0)
        {
            dfs_ponte(vertices, filhoAtual, raiz); // forward edge
        }
        else
        {
            if (vertices[filhoAtual].visitado == 1 && filhoAtual != pai)
            {
                vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].in);
            }
        }

        /*
        se o lower do filho for maior q o in do pai entao eh ponte
        */
        if (vertices[filhoAtual].lower > vertices[raiz].in)
        {
            printf("ponte %d %d\n", raiz, filhoAtual);
        }

        /*rebalancear*/
        vertices[raiz].lower = min(vertices[raiz].lower, vertices[filhoAtual].lower);
    }
}