#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
using namespace std;

int main(){
    stack<int> pilha;

    pilha.push(3);
    pilha.push(4);
    pilha.push(5);

    cout << pilha.top() << "\n";

    cout << pilha.size() << "\n";

    cout << pilha.empty() << "\n";

    pilha.pop();
    pilha.pop();
    pilha.pop();

    cout << pilha.size() << "\n";

    cout << pilha.empty() << "\n";

    return 0;
}