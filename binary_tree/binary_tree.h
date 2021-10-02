#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct Node Node_T;
struct Node{
    Node_T *left;
    Node_T *right;
    int val;
    void *data;
    int height;
    int bf;         /* Balance Factor = Left node Height - Right node Height*/
};

typedef struct Tree Tree_T;
struct Tree{
    Node_T *root;
};

void enable_AVL(void);
void disable_AVL(void);
Tree_T* init(int);
Node_T* search(Tree_T *t, int);
Node_T* get_parent(Tree_T *t, int);
void insert(Tree_T *t, int);
void del(Tree_T *t, int);
void destroy(Tree_T *t);
void sort(Tree_T *t);
int getHeight(Node_T*);
int link_data(Node_T *root, int, void *data);

#endif
