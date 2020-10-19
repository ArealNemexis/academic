#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector< vector< ii > > graph(5);

int main()
{
    graph[0] = {make_pair(1,30),make_pair(2, 10),make_pair(3, 15)};
    graph[1] = {make_pair(0, 24),make_pair(3, 70),make_pair(4, 110)};
    graph[2] = {make_pair(0, 54),make_pair(3, 66)};
    graph[3] = {make_pair(0, 12),make_pair(1, 43),make_pair(2, 21)};
    graph[4] = {make_pair(1, 56),make_pair(2, 65)};
    
    // graph[0].push_back(ii(3,3)); <-- to insert a vertex

    cout << graph.size() << endl;
    for(int i = 0; i < graph.size();i++)
    {
        cout << i << " : ";
        for(auto y:graph[i])
        {
            cout << "(" << y.first << "," << y.second << ")" << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}
