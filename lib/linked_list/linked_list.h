#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct Node Node_T;
struct Node{
    int val;
    Node_T *next;
};

typedef struct List List_T;
struct List{
    Node_T *head;
};

List_T* init(int val);
void append(List_T*, int val);
void insert(List_T*, int pos, int val);
void del(List_T*, Node_T*);
void pop(List_T*);
Node_T* search(List_T*, int val);
void reverse(List_T*);
void print(List_T*);
void destroy(List_T*);

#endif