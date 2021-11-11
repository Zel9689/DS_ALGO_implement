#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct Node Node_T;
struct Node{
    int val;
    Node_T *next;
};

Node_T* init(int val);
void append(Node_T*, int val);
void insert(Node_T*, int pos, int val);
void del(Node_T*, Node_T*);
void pop(Node_T*);
Node_T* search(Node_T*, int val);
void reverse(Node_T*);
void print(Node_T*);
void destroy(Node_T*);

#endif