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

void insert(struct Node* root, int value){
    struct Node* prev;
    struct Node* actual = root;
    
    prev = NULL;
    

    while(actual){
        prev = actual;

        if(actual->value == value){
            return;
        }
        else if(value < actual->value){
            actual = actual->left;
        }
        else{
            actual = actual->right;
        }
    }

    struct Node * new = newNode(value);
    
    if(!root){
        root = new;
    }
    else if(value < prev->value){
        prev->left = new;
    }else{
        prev->right = new;
    }
}

int main(int argc, char const *argv[])
{
    struct Node * root;
    root = newNode(50);
    
    insert(root, 49);
    insert(root, 51);

    printf("\t%d\n", root->value);
    printf("%d", root->left->value);
    printf("\t\t%d\n", root->right->value);
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