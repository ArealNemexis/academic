#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

using namespace std;

int main()
{
    forward_list<int> fl;
    forward_list<int>::iterator flit;

    fl.push_front(1);
    fl.push_front(2);
    fl.push_front(3);
    for (flit = fl.begin(); flit != fl.end(); flit++)
    {
        cout << *flit << endl;
    }

    return 0;
}

/**
 * Forward list é uma lista ligada simples, conhecendo os conceitos de estrutura de dados mais basicos
 * é possivel implementa-la.
 * */