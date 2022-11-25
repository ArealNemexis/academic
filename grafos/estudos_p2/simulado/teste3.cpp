#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int inf = 1e9;

typedef pair<int,int> ii;

vector<ii> adj[N];
vector<int> dist;
vector<bool> visited;



void dijkstra(int s){

    dist.assign(N, inf);
    visited.assign(N, false);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) 
            continue;
        visited[u] = true;

        for(auto adjcs: adj[u]){
            int v = adjcs.first, w = adjcs.second; // vertice e pesoW
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    

}