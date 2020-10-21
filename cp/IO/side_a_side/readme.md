# Variáveis lado a lado.

Suponhamos que o problema informe 4 variaveis seguidas uma da outra separadas por espaço. 

Chamaremos essas variaveis de X,Y,W e Z.

> 3 4 6 12

Devido a atribuição multipla, em Python 3 podemos utilizar o input().split(), que dividirá nossa entrada onde houver um espaço. E para converter a entrada para um tipo especifico podemos utilizar um map.

```python
x, y, w, z = map(int, input().split())

print(f'x:{x} y:{y} w:{w} z:{z}')
```

Já em C++ o cin ajuda fazendo o trabalho do .split(), além de dividir onde houver um espaço ele também divide onde há uma quebra de linha.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y,w,z;

    cin >> x >> y >> w >> z;

    cout << "x:" << x << " y:" << y << " w:" << w << " z:" << z << "\n";
    return 0;
}
```
