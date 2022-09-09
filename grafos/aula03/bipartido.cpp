#include <bits/stdc++.h>
#define tam 10000
#define noGroup -1

using namespace std;

int visited[tam];
int distances[tam];
int colors[tam];

void resetColors(){
    for(int i = 0; i < tam; i++){
        colors[i] = noGroup;
    }
}


int main(int argc, char const *argv[])
{
    cout << colors[10] << endl;
    return 0;
}
