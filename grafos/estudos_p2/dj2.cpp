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

int main()
{
    adj[1].push_back({2,1});
    adj[1].push_back({7,1});
    adj[2].push_back({3,1});
    adj[2].push_back({8,1});
    adj[3].push_back({4,1});
    adj[4].push_back({7,1});
    adj[4].push_back({8,1});
    adj[8].push_back({5,1});
    adj[5].push_back({6,1});
    adj[6].push_back({7,1});

    dijkstra(1);
    vector<int> v;
    pair<int,int> menor;
    menor = make_pair(-1,infinito); 
    v.push_back(4);
    v.push_back(7);
    v.push_back(8);
    for(auto x:v){
        cout << "menor distancia ate " << x << " = " << dist[x] << "\n";
        if(dist[x] < menor.second){
            menor = make_pair(x, dist[x]);
        }
    }


    for(int i = 0; i<N;i++){
        cout << "menor distancia de 1 ate " << i << " = " << dist[i] << "\n";
    }

    cout << menor.first << "\n";
    return 0;
}