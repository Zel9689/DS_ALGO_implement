#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define max(a, b) ({ \
    typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a > _b ? _a : _b; \
})

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
int current_depth = -1;
Node_T* search(Node_T *n, int val)
{
    current_depth++;
    int i = 0;
    if(n->edge != 0 ){
        for(; i < n->edge; i++)
            search(*((n->children) + i), val);
    }
    if(n->val == val)
        printf("Found val %d at Depth %d\n", val, current_depth);
    current_depth--;
}

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
    if(n->edge == 0) return 0;
    int h = 0;
    for(int i = 0; i < n->edge; i++)
        h = max(getHeight(*((n->children) + i)), h);
    return h + 1;
}

void destroy(Node_T *n)
{
    if(n->edge == 0){
        printf("node val %d has been destroyed\n", n->val);
        free(n);
        return;
    }
    for(int i = 0; i < n->edge; i++)
        destroy(*((n->children) + i));
    printf("node val %d has been destroyed\n", n->val);
    free(n->children);
    free(n);
}

