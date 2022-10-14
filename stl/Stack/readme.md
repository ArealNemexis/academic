# Stack (Pilha)

Pilha é uma estrutura de dados que pode ser logicamente considerada como uma estrutura linear representada por uma pilha real.

É possivel imaginar um porto maritimo cheio de container em**pilha**dos, onde o acesso a cada container depende do mesmo está no topo da pilha. Portanto o principio dessa estrutura é a inserção e remoção de containers feita no topo da estrutura.

Esse principio é chamado de LIFO (**L**ast **I**n **F**irst **O**ut), onde a tradução seria: *ultimo a entrar primeiro a sair*.

## Aplicações da Stack
<hr>

### Avaliação de Expressão Matemática
A estrutura de dados da pilha é usada para avaliar uma expressão matemática fornecida. Por exemplo, considere a seguinte expressão

**5 * (6 + 2) - 12/4**



Como o parêntese tem a precedência mais alta entre os operadores aritméticos,  (6 +2) = 8  será avaliado primeiro. Agora, a expressão se torna 

**5 * 8 - 12/4**

/ e *  têm precedência igual e sua associatividade é da esquerda para a direita. Portanto, comece avaliando a expressão da esquerda para a direita.

**5 * 8 = 40**  e  **12/4 = 3**

Agora, a expressão se torna

**40 - 3** 

E o valor retornado após a operação de subtração é **37**.


### Execução de programas

Chamada de **Call Stack**, uma linguagem de programação pode ter implementada uma pilha para a chamada de execuções de subrotinas dentro de um programa, assim controlando o fluxo do mesmo. 
