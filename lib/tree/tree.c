#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node_T* init(int val)
{
    Node_T* n = calloc(sizeof(Node_T), 1);
    n->val = val;
    return n;
}

Node_T* insert(Node_T *n, int val)
{
    Node_T* child = calloc(sizeof(Node_T), 1);
    child->val = val;

    Node_T** new_children = calloc(sizeof(Node_T*), n->edge+1);
    if(n->edge != 0)
        for(int i = 0; i < n->edge; i++)
            memcpy(new_children+i, (n->children)+i, sizeof(Node_T*));

    *(new_children + n->edge) = child;
    n->children = new_children;
    (n->edge)++;
    
    return child;
}

// Node_T* search(Tree_T *t, Node_T *n, int val)
// {

// }

void print_edge(Node_T *n)
{
    if(n == NULL) return;
    printf("Print Edge of Node\(val: %d):\n", n->val);
    if(n->edge == 0){
        printf("None. It's a leaf.\n\n");
        return;
    }
    Node_T **p = n->children;
    for(int i = 0; i < n->edge; i++, p++){
        printf("%d ", (*p)->val);
    }
    printf("\n\n");
}

int getHeight(Node_T *n)
{
    int h = 0;
    if(n->edge != 0){
        Node_T** p = n->children;
        for(int i = 0; i < n->edge; i++, p++){
            
        }
    }
    return h;
}