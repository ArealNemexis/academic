#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node * newNode(int value){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));

    new->value = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int main(int argc, char const *argv[])
{
    struct Node * root;
    root = newNode(50);
    
    return 0;
}


/*--------- arvore binária implementada utilizando ponteiros ---------
* 
*
*
*
*
*
*
*
*
*
*
*
*
*
*/