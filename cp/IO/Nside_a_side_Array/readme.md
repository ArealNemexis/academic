# N Variaveis lado a lado para um Array

Suponhamos que um problema informe um N e que na proxima linha ele informe N elementos separados por espaço.

> 5

> 1 2 3 4 5

Ao analisar o problema você percebe que precisa guardar os elementos em um Array.

Em Python 3, você não precisa declarar o tamanho para as estruturas de dados embutidas, então basta utilizar o split() com o map() e converter para a estrutura list.

```python
n = int(input())
array = list(map(int, input().split()))

print(*array)
```

Em C++, estruturas como vector e array precisam de um tamanho na declaração. É possivel declarar previamente e depois utilizar a função resize() para mudar o tamanho, não é muito interessante pois o resize() tem complexidade _O(n)_. Então você pode declarar com o tamanho maximo possivel de N que o problema pode informar ou receber N e criar o tamanho exato.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];

    for(int i = 0; i < n; i++)
        cin >> array[i];

    for(int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
```