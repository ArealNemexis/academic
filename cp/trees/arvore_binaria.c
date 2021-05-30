#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left, *right;
} node;

typedef struct bTree
{
    struct node *root;
} bTree;

node *new_node(int value)
{
    node *new = (node *)malloc(sizeof(node));

    new->value = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}
bTree *new_bTree()
{
    bTree *new = (bTree *)malloc(sizeof(bTree));
    new->root = NULL;
    return new;
}

void insert(bTree *t, int value)
{

    if (t->root == NULL)
    {
        node * new = new_node(value);
        t->root = new;
    }
    else
    {
        node *previous, *actual = t->root;

        while (actual != NULL)
        {
            previous = actual;

            if (actual->value == value)
            {
                return;
            }
            else if (actual->value < value)
            {
                actual = actual->right;
            }
            else
            {
                actual = actual->left;
            }
        }

        node *new = new_node(value);

        if (previous->value < value)
        {
            previous->right = new;
        }
        else
        {
            previous->left = new;
        }
    }
}

void inOrder(node *n)
{
    if (n == NULL)
    {
        return;
    }

    inOrder(n->left);

    printf("%d ", n->value);

    inOrder(n->right);
}

int main()
{
    // node * root = new_node(1);
    // insert2(root, 2);
    // insert2(root, 3);
    // insert2(root, 4);
    // insert2(root, 5);

    // inOrder(root);
    bTree *tst = new_bTree();

    insert(tst, 1);
    insert(tst, 2);
    insert(tst, 3);
    insert(tst, 4);
    insert(tst, 5);

    inOrder(tst->root);

    printf("\n");

    return 0;
}
