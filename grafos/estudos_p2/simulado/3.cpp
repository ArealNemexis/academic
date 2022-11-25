#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int N = 100;
const int infinito = 1e9;

vector<ii> adj[N];
vector<int> dist;
vector<bool> visited;

/*
0 a
1 b
2 c
3 d
4 e
5 f
*/

void dijkstra(int s);

int main(int argc, char const *argv[])
{
    int n, m, i;
    int a,b, peso;

    scanf("%d %d", &n, &m);

    for(i = 0; i < m; i++){
        scanf("%d;%d;%d", &a, &b, &peso);
        adj[a].push_back({b,peso});
        adj[b].push_back({a,peso});
    }

    dijkstra(5);
    for(int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }
    return 0;
}


void dijkstra(int s){
    dist.assign(N, infinito);
    visited.assign(N, false);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> >pq;
    pq.push({0,s});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for(auto i: adj[u]){
            int v = i.first, w = i.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}