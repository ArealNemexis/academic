#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

const int N = 100;
const int infinito = 1e9;


vector<ii> adj[N];
vector<int> dist;
vector<bool> visited;

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