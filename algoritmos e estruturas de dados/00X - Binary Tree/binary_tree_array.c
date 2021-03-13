#include <stdio.h>
#include <stdlib.h>
#define tam 33
int * tree;

int left(int index){
    return 2*index;
}

int right(int index){
    return (2*index)+1;
}

int parent(int index){
    // if(index != -1){
    //     return index/2;
    // }
    // else{
    //     return 0;
    // }

    return (index != -1) ? index/2 : 0; 
}

int main(int argc, char const *argv[])
{
    tree = (int *)malloc(sizeof(int)*tam);

    for(int i = 0; i < tam; i++){
        tree[i] = -1; // limpando lixo de memoria
    }

    

    return 0;
}

/* --------- arvore binária implementada utilizando array ---------
* -1 significa null nessa implementação
* indice zero não é utilizado
* root = tree[1]
* nó a esquerda é o indice(p) multiplicado por 2, ou seja 2p
* nó a direita é o indice(p) multiplicado por 2 e somado 1, ou seja 2p + 1
* se um nó ocupa o indice p e p != -1, então seu pai está no indice p/2
* 
*
* ---- vantagens ----
* simples implementação
* simples manipulação
* bom para tamanhos de conjuntos de dados fixos
*
*
* ---- desvantagens ----
* tamanho fixo
* muito custoso computacionalmente aumentar o tamanho
* ruim para tamanhos de conjuntos de dados volateis (realloc custoso)
*
*
*
*
*/
