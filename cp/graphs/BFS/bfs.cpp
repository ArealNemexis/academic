#include <bits/stdc++.h>

using namespace std;

vector< list<int> > graph(5);

void bfs(int node){
    queue<int> q;
    vector<int> v;
    int aux;
    q.push(node);
    v.push_back(node);

    while (!q.empty())
    {
        aux = q.front();
        q.pop();
        cout << aux << " ";

        for(auto x:graph[aux]){
            if(find(v.begin(),v.end(), x) == v.end()){
                v.push_back(x);
                q.push(x);
            }
        }

    }
}

int main()
{
    set<int> visited;
    set<int>::iterator it;
    graph[0] = {1,2,3};
    graph[1] = {0,3,4};
    graph[2] = {0,3};
    graph[3] = {0,1,2};
    graph[4] = {1,2};

    bfs(0);

    cout << endl;
    return 0;
}