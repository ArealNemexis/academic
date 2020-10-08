#include <iostream>
#include <set>

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
