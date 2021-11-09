#ifndef _TREE_H
#define _TREE_H

typedef struct Node Node_T;
struct Node{
    Node_T** children;
    int val;
    int edge;
};

Node_T* init(int);
Node_T* insert(Node_T*, int);
/**
 * @brief recursively search node with val under specific node.
 * @param target_node
 * @param val
 * @return Node_T* 
 */
Node_T* search(Node_T*, int);
void print_edge(Node_T*);
int getHeight(Node_T*); // Definition of Height is count from 0
void destroy(Node_T*);

#endif