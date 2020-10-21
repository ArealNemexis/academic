# N variaveis lado a lado.

Suponhamos que um problema informe um N e diga que nas proximas N linhas recebera 3 variaveis separadas por espaço.

> 3

> 3 2 1

> 6 8 2

> 27 36 589

Além disso ele pede que para cada linha você devolva a sequencia ao contrário.

> 1 2 3

> 2 8 6

> 589 36 27

Tanto em Python como em C++ serão necessários laços de repetição.
Veja os codigos.

Python 3
```python
for _ in range(int(input())):
    a,b,c = map(int, input().split())

    print(c,b,a)
```

C++
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;

    cin >> n;
    while(n--){
        cin >> a >> b >> c;

        cout << c << " " << b << " " << a << "\n";
    }

    return 0;
}
```