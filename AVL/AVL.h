#ifndef _AVL_H
#define _AVL_H

typedef struct Node_s Node_t;
struct Node_s{
    Node_t *left;
    Node_t *right;
    Node_t *parent;
    int val;
    int height;
    int bf;         /* Balance Factor = Left node Height - Right node Height*/
};

typedef struct Tree_s Tree_t;
struct Tree_s{
    Node_t *root;
};

Tree_t* create(void);
Node_t* search(Tree_t*, int);
int insert(Tree_t*, int);
int del(Tree_t*, int);
void destroy(Tree_t*);
void print(Tree_t*);

void _destroy(Node_t*);
void _print(Node_t*);
int _getHeight(Node_t*);
void _updateNodes(Node_t*);

void _leftRotation(Node_t*);
void _rightRotation(Node_t*);

void _AVL(Node_t*);
#endif