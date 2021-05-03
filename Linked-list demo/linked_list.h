#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct List List;
List * list_init(void);
void append(List *, int);
int insert(List *, int, int);
void del(List *, int);
void pop(List *);
List * search(List *, int);
void print_list(List *);
void free_list(List *);

#endif