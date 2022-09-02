#include <bits/stdc++.h>

using namespace std;
int visited[10000];
int distances[10000];

void add_edge(int a, int b, vector<list<int>> graph)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void dfs(int vertex, vector<list<int>> graph, int distance)
{
    // cout << vertex << "\n ";
    visited[vertex] = 1;
    distances[vertex] = distance;
    for (auto const &x : graph[vertex])
    {
        // printf("visited[x] = %d\n", visited[x]);
        if (visited[x] == 0)
        {
            // printf("chamando do %d pro %d\n", vertex, x);
            dfs(x, graph, distance+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, e;

    scanf("%d", &n);
    scanf("%d", &e);

    vector<list<int>> graph(n);
    int origin, destiny;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        distances[i] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &origin, &destiny);
        graph[origin - 1].push_back(destiny - 1);
        graph[destiny - 1].push_back(origin - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, graph);
            // for (int j = 0; j < n; j++)
            // {
            //     printf("%d ", visited[j]);
            // }
            // printf("\n");
            // break;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", distances[i]);
    }
    printf("\n");
    return 0;
}
