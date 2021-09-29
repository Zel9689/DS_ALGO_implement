#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ({ \
    typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a > _b ? _a : _b; \
})

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

    _updateNodes(node);
    _AVL(ptr);
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
    

    Node_t *ptr = replace;
    if(ptr == NULL){
        ptr = node->parent;
    }else if(ptr->left != NULL){
        ptr = ptr->left;
        while(ptr->right != NULL) ptr = ptr->right;
    }

    _updateNodes(ptr);
    _AVL(ptr);
    free(node);
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

int _getHeight(Node_t *node)
{
    if(node == NULL)
        return -1;
    if(node->left == NULL && node->right != NULL)
        return node->right->height + 1;
    if(node->left != NULL && node->right == NULL)
        return node->left->height + 1;
    return max(node->left->height, node->right->height) + 1;
}

void _updateNodes(Node_t *ptr)
{
    if(ptr == NULL) return;
    do{
        ptr->height = _getHeight(ptr);
        ptr->bf     = _getHeight(ptr->left) - _getHeight(ptr->right);
        ptr = ptr->parent;
    }while(ptr != NULL);
}

void _leftRotation(Node_t *node)
{
    Node_t *r_sub = node->right;
    
    if(node->parent != NULL){
        if(node->parent->left == node)  node->parent->left = r_sub;
        if(node->parent->right == node)  node->parent->right = r_sub;
    }
    r_sub->parent = node->parent;

    node->right = r_sub->left;
    r_sub->left->parent = node;

    r_sub->left = node;
    node->parent = r_sub;

    _updateNodes(node);
}

void _rightRotation(Node_t *node)
{
    Node_t *l_sub = node->left;
    
    if(node->parent != NULL){
        if(node->parent->left == node)  node->parent->left = l_sub;
        if(node->parent->right == node)  node->parent->right = l_sub;
    }
    l_sub->parent = node->parent;

    node->left = l_sub->right;
    l_sub->right->parent = node;

    l_sub->right = node;
    node->parent = l_sub;

    _updateNodes(node);
}

void _AVL(Node_t *node)
{
    if(node == NULL) return;

    if(node->bf < -1){
        // RR
        if(node->right->right != NULL){
            _leftRotation(node);
        }
        // RL
        else{
            _rightRotation(node->right);
            _leftRotation(node);
        }
    }
    else if(node->bf > 1){
        // LL
        if(node->left->left != NULL){
            _rightRotation(node);
        }
        // LR
        else{
            _leftRotation(node->left);
            _rightRotation(node);
        }
    }
    node = node->parent;
    _AVL(node);
}