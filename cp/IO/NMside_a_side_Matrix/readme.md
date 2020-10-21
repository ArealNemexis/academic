# N linhas com M elementos para uma matriz

Suponhamos que um problema diga que informará na primeira linha N e M, e que nas proximas N linhas informará M elementos separados por espaço.

> 3 3

> 1 2 5

> 4 6 7

> 10 8 3

Em C++ é possivel declarar a matrix com o tamanho máximo da entrada, e depois preencher e navegar utilizando os ranges n,m. Não é o que economiza mais memória, mas funciona, tome cuidado com segmentation fault.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    int matrix[1000][1000];
    int n,m;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    cout << n << " " << m << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```


Em Python 3 é sempre mais tranquilo trabalhar com essas estruturas, porém é bem menos performatico que em C++.

```Python
n,m = map(int,input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

print(n,m)
for line in matrix:
    print(*line)
```