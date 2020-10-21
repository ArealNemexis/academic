# N linhas com M elementos para uma matriz

Suponhamos que um problema diga que informará na primeira linha N e M, e que nas proximas N linhas informará M elementos separados por espaço.

> 3 3

> 1 2 5

> 4 6 7

> 10 8 3

Em [C++](c.cpp) é possivel declarar a matrix com o tamanho máximo da entrada, e depois preencher e navegar utilizando os ranges n,m. Não é o que economiza mais memória, mas funciona, tome cuidado com segmentation fault.

Em [Python 3](p.py) é sempre mais tranquilo trabalhar com essas estruturas, porém é bem menos performatico que em C++.