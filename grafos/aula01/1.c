#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node * next;
}Node;

Node * aloc_node(int value){
    Node * new = (Node*)malloc(sizeof(Node));

    new->value = value;
    new->next = NULL;

    return new;
}

void insert_list(Node * list, int i){
    if(list == NULL){
        return;
    }

    Node * aux;
    aux = list;
    while(aux->next != NULL){
        aux = aux->next;
    }

    aux->next = aloc_node(i);
}

void connect_nodes(int origin, int destiny, Node ** graph){
    insert_list(graph[origin], destiny);
    insert_list(graph[destiny], origin);
}

void print_list_adj(Node * list){
    Node * aux;
    aux = list;
    while(aux != NULL){
        printf("%d -> ", aux->value);
        aux = aux->next;
    }

}

int main(int argc, char const *argv[])
{
    int n, v;
    int origin, destiny;
    Node ** grafo_lista_adjacencias;
    int  grafo_matrix_adjacencias[30][30];

    printf("Digite quantidade de nos\n");
    scanf("%d", &n);

    printf("Digite quantidade de vertices\n");
    scanf("%d", &v);
    grafo_lista_adjacencias = (Node**)malloc(sizeof(Node*)*n);
    
    for(int i = 0; i < n;i++){
        grafo_lista_adjacencias[i] = aloc_node(i);
        for(int j = 0; j < n; j++){
            grafo_matrix_adjacencias[i][j] = 0;
            if(i == j){
                grafo_matrix_adjacencias[i][j] = 1;
            }
        }
    }

    // printf("Matriz adjacencias\n");
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", grafo_matrix_adjacencias[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for(int i = 0; i < v; i++){
        scanf("%d %d", &origin, &destiny);
        grafo_matrix_adjacencias[origin-1][destiny-1] = 1;
        grafo_matrix_adjacencias[destiny-1][origin-1] = 1;
        connect_nodes(origin-1, destiny-1, grafo_lista_adjacencias);
    }
    
    printf("\n\n\n\nMatriz adjacencias\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", grafo_matrix_adjacencias[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nlista adjacencia\n");

    for(int i = 0; i < n;i++){
        printf("%d: ", i);
        print_list_adj(grafo_lista_adjacencias[i]);
        printf("\n");
    }

    return 0;
}
