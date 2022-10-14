#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define dbg(x) count << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int calc(string s, int sz)
{
    if (s[sz - 1] == 'M')
        return 0; 
    else
    {
        if (s[sz - 1] == 'S')
            return -1 * sz;
        else
            return sz;
    }
}

int main()
{  _;

    string in1, in2;
    int cases;
    int s1, s2;
    int calc1, calc2;

    cin >> cases;

    while (cases--)
    {
        // scanf("%s %s", &in1, &in2);
        // L M S
        cin >> in1 >> in2;
        s1 = in1.size();
        s2 = in2.size();
        calc1 = calc(in1, s1);
        calc2 = calc(in2, s2);

        if(calc1 == calc2) cout << "=" << endl;
        if(calc1 > calc2) cout << ">" << endl;
        if(calc1 < calc2) cout << "<" << endl;
    }
    return 0;
}