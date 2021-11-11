#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List_T* init(int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    List_T *l = calloc(1, sizeof(List_T));
    l->head = n;
    return l;
}

void append(List_T *l, int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    Node_T *p = l->head;
    while(p->next != NULL) p = p->next;
    p->next = n;
}

void insert(List_T *l, int pos, int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    if(pos > 0){
        Node_T *p = l->head;
        for(int i = 0; i < pos - 1; i++){
            if(p == NULL) return;
            p = p->next;
        }
        Node_T *tmp = p->next;
        p->next = n;
        n->next = tmp;
    }
    else if(pos == 0){
        Node_T *tmp = l->head;
        l->head = n;
        n->next = tmp;
    }
}

void del(List_T *l, Node_T *n)
{
    if(l->head == n){
        l->head = l->head->next;
        free(n);
        return;
    }
    Node_T *prev;
    for(Node_T *p = l->head; p != NULL; prev = p, p = p->next){
        if(n == p){
            prev->next = p->next;
            free(p);
        }
    }
}

void pop(List_T *l)
{
    Node_T *tmp = NULL;
    Node_T *p = l->head;
    while(p->next != NULL){
        tmp = p;
        p = p->next;
    }
    if(tmp == NULL)
        l->head = NULL;
    else
        tmp->next = NULL;
    free(p);
}

Node_T* search(List_T *l, int val)
{
    for(Node_T *p = l->head; p != NULL; p = p->next){
        if(p->val == val)
            return p;
    }
}

static Node_T* _reverse(Node_T *n)
{
    if(n->next == NULL) return;
    _reverse(n->next);
    // 倒數第二個node開始可以進來
    n->next->next = n;
}

void reverse(List_T *l)
{
    Node_T *last = l->head;
    while(last->next != NULL)   last = last->next;
    l->head = _reverse(l->head);
    l->head->next = NULL;
    l->head = last;
}

void print(List_T *l)
{
    Node_T *p = l->head;
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

void destroy(List_T *l)
{
    Node_T *p = l->head;
    while(p != NULL){
        Node_T *tmp = p;
        p = p->next;
        printf("node val: %d has been destroyed.\n", tmp->val);
        free(tmp);
    }
    free(l);
}
