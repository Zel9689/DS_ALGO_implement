#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node_T* init(int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    Node_T *head = calloc(1, sizeof(Node_T));
    head->next = n;
    return head;
}

void append(Node_T *h, int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    Node_T *p = h;
    while(p->next != NULL) p = p->next;
    p->next = n;
}

void insert(Node_T *h, int pos, int val)
{
    Node_T *n = calloc(1, sizeof(Node_T));
    n->val = val;
    Node_T *p = h;
    for(int i = 0; i < pos; i++){
        if(p == NULL) return;
        p = p->next;
    }
    if(p == NULL) return;
    n->next = p->next;
    p->next = n;
}

void del(Node_T *h, Node_T *n)
{
    if(h == n) return;
    Node_T *tmp;
    for(Node_T *p = h->next; p != NULL; tmp = p, p = p->next){
        if(p == n){
            tmp->next = tmp->next->next;
            free(p);
            return;
        }
    }
}

void pop(Node_T *h)
{
    Node_T *tmp = NULL;
    Node_T *p = h;
    while(p->next != NULL){
        tmp = p;
        p = p->next;
    }
    if(p == h) return;
    else            tmp->next = NULL;
    free(p);
}

Node_T* search(Node_T *h, int val)
{
    for(Node_T *p = h->next; p != NULL; p = p->next){
        if(p->val == val && p != h)
            return p;
    }
    return NULL;
}

static void _reverse(Node_T *n)
{
    if(n->next == NULL) return;
    _reverse(n->next);
    // 倒數第二個node開始可以進來
    n->next->next = n;
}

void reverse(Node_T *h)
{
    Node_T *last = h->next;
    while(last->next != NULL)   last = last->next;
    _reverse(h->next);
    h->next->next = NULL;
    h->next = last;
}

void print(Node_T *h)
{
    Node_T *p = h->next;
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n\n");
}

void destroy(Node_T *h)
{
    Node_T *p = h;
    while(p != NULL){
        Node_T *tmp = p;
        p = p->next;
        printf("node val: %d has been destroyed.\n", tmp->val);
        free(tmp);
    }
}
