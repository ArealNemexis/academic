#include <iostream>
#include <list>

using namespace std;

class Graph{

    int V;
    list<int> *adj;
    void bridgeDFS(int v, bool visited[], int in[], int lower[], int pai[]);

public:
    Graph (int V);
    void adicionaAresta(int x, int y);
    void bridge();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::adicionaAresta(int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void Graph::bridgeDFS(int u, bool visited[], int in[], int lower[], int pai[]){

    static int t = 0;

    visited[u] = true;
    in[u] = lower[u] = ++t;

    list<int>::iterator i;

    for(i = adj[u].begin(); i != adj[u].end(); ++i){

        int v = *i;

        if(!visited[v]){
            pai[v] = u;
            bridgeDFS(v, visited, in, lower, pai);

            lower[u] = min(lower[v], lower[u]);

            if(in[u] < lower[v]){
                cout << u << " " << v <<endl;
            }
        }

        else if(v != pai[u]){
            lower[u] = min(in[v], lower[u]);
        }
    }
}

void Graph::bridge(){
    bool *visited = new bool[V];
    int *in = new int[V];
    int *lower = new int[V];
    int *pai = new int[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
        pai[i] = -1;
    }

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            bridgeDFS(i, visited, in, lower, pai);
        }
    }
}

int main(){

    int a,v, x, y;
    cin >> v >> a;
    Graph g(v+1);

    for (int i = 0; i < a; i++){
        cin >> x >> y;
        g.adicionaAresta(x, y);
    }

    g.bridge();

    return 0;
}

