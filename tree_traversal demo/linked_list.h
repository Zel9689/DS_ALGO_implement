#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct Node{
    struct Node *left;
    struct Node *right; 
    int value;   
};
typedef struct List List;
struct List
{
    struct Node *num;
    List *next;
};
List * list_init(void);
void append(List *, struct Node *);
int insert(List *, int, struct Node *);
void del(List *, int);
void pop(List *);
List * search(List *, int);
void print_list(List *);
void free_list(List *);

#endif