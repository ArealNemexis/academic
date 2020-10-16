#include <bits/stdc++.h>

using namespace std;

vector< list<int> > graph(5);

void dfs(set<int>&visited, int vertex){
    if(visited.find(vertex) == visited.end()){
        cout << vertex << " ";
        visited.insert(vertex);
        for(list<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++)
        {
            dfs(visited, *it);
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

    dfs(visited, 0);
    cout << endl;

    return 0;
}
