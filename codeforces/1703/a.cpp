#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    char in[4];
    char compareStr[4];
    scanf("%d", &cases);

    while (cases--)
    {

        scanf("%s", in);
        in[3] = '\0';

        for (int i = 0; i < 3; i++)
        {
            compareStr[i] = tolower(in[i]);
        }
        compareStr[3] = '\0';

        if (strcmp(compareStr, "yes") == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}