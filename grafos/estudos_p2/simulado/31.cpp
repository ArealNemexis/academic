#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int N = 100;

vector<ii> adj[N];
vector<bool> visited;
vector<int> dist;
vector<char> parse = {'a','b','c','d','e','f'};

void dijkstra(int s);

int main(int argc, char const *argv[])
{
    int n, m, i;
    int a, b, peso;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d;%d;%d", &a, &b, &peso);
        adj[a].push_back({b, peso});
        adj[b].push_back({a, peso});
    }
    int r = 0;
    // for (auto g : adj)
    // {
        
    //     for (auto x : g)
    //     {
    //         cout << r << " " << x.first << " " << x.second << endl;
    //     }
    //     r++;
    // }

    dijkstra(5);
    for(int i = 0; i < n; i++) {
        cout << parse[i] << " " << dist[i] << endl;
    }
    return 0;
}

void dijkstra(int s) {
    visited.assign(N, false);
    dist.assign(N, 9999);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(visited[u] == true) continue;

        visited[u] = true;

        for(auto x: adj[u]){
            int v = x.first, w = x.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
}