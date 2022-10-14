#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

int main()
{
    int cases, i, j;
    int qtdWheels;
    int wheels[101];
    int wheelsValues[101];

    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &qtdWheels);
        for (i = 0; i < qtdWheels; i++)
        {
            scanf("%d", &wheelsValues[i]);
        }
        for (i = 0; i < qtdWheels; i++)
        {
            int actualIn;
            char moveActual[11];
            scanf("%d %s", &actualIn, moveActual);

            for (j = 0; j < actualIn; j++)
            {

                if (moveActual[j] == 'U')
                {
                    if (wheelsValues[i] == 0)
                    {
                        wheelsValues[i] = 9;
                    }
                    else
                    {
                        wheelsValues[i]--;
                    }
                }
                else
                {
                    if (wheelsValues[i] == 9)
                    {
                        wheelsValues[i] = 0;
                    }
                    else
                    {
                        wheelsValues[i]++;
                    }
                }
            }

            printf("%d ", wheelsValues[i]);
        }
        printf("\n");
    }
    return 0;
}