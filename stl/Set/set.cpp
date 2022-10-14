#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

using namespace std;

int main()
{
    set<int> s;
    set<int>::iterator si;
    s.insert(1);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(1);

    for (si = s.begin(); si != s.end(); si++)
    {
        cout << *si << endl;
    }

    return 0;
}
