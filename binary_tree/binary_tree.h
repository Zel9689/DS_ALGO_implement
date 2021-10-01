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

Node_T* init(int);
Node_T* search(Node_T *root, int);
Node_T* get_parent(Node_T *root, int);
Node_T* insert(Node_T *root, int);
int link_data(Node_T *root, int, void *data);
Node_T* del(Node_T *root, int);
void destroy(Node_T *root);
void sort(Node_T *root);
int getHeight(Node_T*);

static void _updateNodes(Node_T *root, Node_T *node);
static Node_T* _leftRotation(Node_T *root, Node_T *node);
static Node_T* _rightRotation(Node_T *root, Node_T *node);
static Node_T* _AVL(Node_T *root, Node_T *abs_root, Node_T *node);

#endif
