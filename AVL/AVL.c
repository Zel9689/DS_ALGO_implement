#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

Tree_t* create()
{
    Tree_t* t = malloc(sizeof(Tree_t));
    t->root = NULL;
    return t;
}

Node_t* search(Tree_t* t, int val)
{
    if(t->root == NULL) return NULL;
    Node_t* ptr = t->root;
    while(ptr != NULL){
        if(val ==  ptr->val){
            return ptr;
        }
        if(val < ptr->val){
            ptr = ptr->left;
            continue;
        }
        if(val > ptr->val){
            ptr = ptr->right;
            continue;
        }
    }
    return NULL;
}

int insert(Tree_t* t, int val)
{
    int run = 1;
    Node_t* node = malloc(sizeof(Node_t));
    node->val = val;
    if(t->root == NULL){
        t->root = node;
        run = 0;
    }
    Node_t* ptr = t->root;
    while(run){
        if(val == ptr->val){
            return -1;
        }
        if(val < ptr->val){
            if(ptr->left == NULL){
                ptr->left = node;
                break;
            }
            ptr = ptr->left;
        }
        if(val > ptr->val){
            if(ptr->right == NULL){
                ptr->right = node;
                break;
            }
            ptr = ptr->right;
        }
    }

    _updateHeight(t, node);
    _updateBF(t, node);
    return 0;
}

int del(Tree_t* t, int val)
{
    Node_t* node = search(t, val);
    if(node == NULL)    return -1;
    Node_t *replace;
    if(node->left != NULL){
        replace = node->left;
        while(replace->right != NULL)   replace = replace->right;
        if(node->left != replace){
            replace->left = node->left;
            node->left->parent = replace;
        }
        replace->right = node->right;
        node->right->parent = replace;
    }
    else if(node->right != NULL){
        replace = node->right;
    }
    else{
        replace = NULL;
    }

    if(replace != NULL)
        replace->parent = node->parent;
    if(node->parent->left == node)
        node->parent->left = replace;
    else
        node->parent->right = replace;
    free(node);

    Node_t *forUpdate = replace;
    if(forUpdate->left != NULL){
        forUpdate = forUpdate->left;
        while(forUpdate->right != NULL) forUpdate = forUpdate->right;
    }
    _updateHeight(t, forUpdate);
    _updateBF(t, forUpdate);
    return 0;
}

void destroy(Tree_t *t)
{
    _destroy(t->root);
}

void _destroy(Node_t *ptr)
{
    if(ptr == NULL) return;
    _destroy(ptr->left);
    _destroy(ptr->right);
    free(ptr);
}

void print(Tree_t *t)
{
    _print(t->root);
}

void _print(Node_t* ptr)
{
    if(ptr == NULL) return;
    _print(ptr->left);
    printf("val: %d, height: %d, balance_factor: %d", ptr->val, ptr->height, ptr->bf);
    _print(ptr->right);
}



