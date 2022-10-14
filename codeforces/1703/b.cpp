#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int cases;
    char actual[101];
    int sizeActual;

    scanf("%d", &cases);

    while (cases--)
    {
        map<char, unsigned int> freq;
        map<char, unsigned int>::iterator it;

        scanf("%d", &sizeActual);
        scanf("%s", actual);

        for (int i = 0; i < sizeActual; i++)
        {
            if (freq.find(actual[i]) != freq.end())
            {
                freq[actual[i]]++;
            }
            else
            {
                freq[actual[i]] = 1;
            }
        }
        int count = 0;
        for (it = freq.begin(); it != freq.end(); it++)
        {
            count += it->second + 1;
        }

        cout << count << endl;
    }
}