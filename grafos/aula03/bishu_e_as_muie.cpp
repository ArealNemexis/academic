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
    int n, qtd_muie=0;
    int muie_mais_prox = INT_MAX;
    int distancia_muie_mais_prox = INT_MAX;

    scanf("%d", &n);

    vector<list<int>> graph(n+1);
    int origin, destiny;

    for (int i = 1; i < n+1; i++)
    {
        visited[i] = 0;
        distances[i] = 0;
    }

    for (int i = 0; i < n-1; i++)
    {
        scanf("%d %d", &origin, &destiny);
        graph[origin].push_back(destiny);
        graph[destiny].push_back(origin);
    }

    scanf("%d", &qtd_muie);
    int array_muies[qtd_muie];
    for(int i = 0; i < qtd_muie; i++){
        scanf("%d", &array_muies[i]);
    }
    

    dfs(1, graph, 0);
    
    for(int i = 0; i < qtd_muie; i++){
        if(distances[array_muies[i]] < distancia_muie_mais_prox){
            if(array_muies[i] < muie_mais_prox){
                muie_mais_prox = array_muies[i];
            }
        }
    }
    printf("%d\n", muie_mais_prox);
    return 0;
}
