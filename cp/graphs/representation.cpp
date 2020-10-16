#include <bits/stdc++.h>

using namespace std;

vector< list<int> > graph(5);
// 0 = 'A'
// 1 = 'B'
// 2 = 'C'
// 3 = 'D'
// 4 = 'E'

void add_edge(int a, int b){
    graph[a].push_back(b);
}

int main()
{
    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,3);

    add_edge(1,0);
    add_edge(1,3);
    add_edge(1,4);

    add_edge(2,0);
    add_edge(2,3);

    add_edge(3,0);
    add_edge(3,1);
    add_edge(3,2);

    add_edge(4,1);
    add_edge(4,3);

    for(int i = 0; i < graph.size();i++){
        list<int>::iterator it;

        cout << i << " : ";
        for(it = graph[i].begin(); it != graph[i].end(); it++){
            cout << *it << " - ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Grafos são
*/