#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#define max(a, b) ({ \
    typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a > _b ? _a : _b; \
})
#define MACRO_AVL(root, node) (_AVL(root, root, node))
Node_T* init(int val)
{
    Node_T *root = malloc(sizeof(Node_T));
    root->val = val;
    return root;
}

Node_T* search(Node_T *root, int val)
{
    Node_T *ptr = root;
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

Node_T* get_parent(Node_T *root, int val)
{
    Node_T *ptr = root;
    Node_T *parent = NULL;
    while(ptr != NULL){
        if(val ==  ptr->val){
            return parent;
        }
        if(val < ptr->val){
            parent = ptr;
            ptr = ptr->left;
            continue;
        }
        if(val > ptr->val){
            parent = ptr;
            ptr = ptr->right;
            continue;
        }
    }
    return parent;
}

Node_T* insert(Node_T *root, int val)
{
    if(search(root, val) != NULL)   return NULL;
    Node_T *node = malloc(sizeof(Node_T));
    Node_T *parent = get_parent(root, val);
    node->val = val;
    if(val < parent->val)   parent->left = node;
    else                    parent->right = node;

    _updateNodes(root, node);
    #ifdef AVL
    root = MACRO_AVL(root, node);
    #endif
    return root;
}

Node_T* del(Node_T *root, int val)
{
    Node_T *node = search(root, val);
    Node_T *parent = get_parent(root, val);
    if(node == NULL)    return NULL;
    Node_T *replace; /* replace會取代被刪除的node */
    /* 有左節點就將replace令為左樹最大node */
    if(node->left != NULL){
        replace = node->left;
        while(replace->right != NULL)   replace = replace->right;
        /* 避免node互指 */
        replace->right = node->right;
        if(node->left != replace)   replace->left = node->left;
    }else{
        /* 否則replace令為右節點 */
        replace = node->right;
    }
    
    /* 代表刪除的node是root，要回傳新root回去 */
    if(parent == NULL){
        root = replace;
    }else{
        /* 使被刪除node的parent指向replace */
        if(val < parent->val)   parent->left = replace;
        else                    parent->right = replace;
    }

    /* 更新node屬性和調用AVL */
    if(replace == NULL){
        _updateNodes(root, parent);
        #ifdef AVL
        root = MACRO_AVL(root, parent);
        #endif
    }else{
        _updateNodes(root, replace);
        #ifdef AVL
        root = MACRO_AVL(root, replace);
        #endif
    }
    
    free(node);
    return root;
}

void destroy(Node_T *ptr)
{
    if(ptr == NULL) return;
    destroy(ptr->left);
    destroy(ptr->right);
    free(ptr);
}

void sort(Node_T *ptr)
{
    if(ptr == NULL) return;
    sort(ptr->left);
    printf("val: %d, height: %d, balance_factor: %d\n", ptr->val, ptr->height, ptr->bf);
    sort(ptr->right);
}

int getHeight(Node_T *node)
{
    if(node == NULL)
        return -1;
    if(node->left == NULL && node->right != NULL)
        return node->right->height + 1;
    if(node->left != NULL && node->right == NULL)
        return node->left->height + 1;
    if(node->left == NULL && node->right == NULL)
        return 0;
    return max(node->left->height, node->right->height) + 1;
}

static void _updateNodes(Node_T *root, Node_T *node)
{
    Node_T *ptr = root;
    if(node->val < ptr->val)    _updateNodes(ptr->left, node);
    if(node->val > ptr->val)    _updateNodes(ptr->right, node);
    ptr->height = getHeight(ptr);
    ptr->bf     = getHeight(ptr->left) - getHeight(ptr->right);
}

static Node_T* _leftRotation(Node_T *root, Node_T *node)
{
    Node_T *r_sub = node->right;
    Node_T *parent = get_parent(root, node->val);
    node->right = r_sub->left;
    r_sub->left = node;
    if(parent != NULL){
        if(parent->left == node)  parent->left = r_sub;
        else                      parent->right = r_sub;
    }else{
        root = r_sub; /* new root */
    }

    _updateNodes(root, node);
    return root;
}

static Node_T* _rightRotation(Node_T *root, Node_T *node)
{
    Node_T *l_sub = node->left;
    Node_T *parent = get_parent(root, node->val);
    node->left = l_sub->right;
    l_sub->right = node;

    if(parent != NULL){
        if(parent->left == node)  parent->left = l_sub;
        else                      parent->right = l_sub;
    }else{
        root = l_sub; /* new root */
    }

    _updateNodes(root, node);
    return root;
}

#ifdef AVL

/* ptr is the same as abs_root, and the recursive will change ptr every call, 
   since we need a original one to pass in Rotations, we need to pass a copy in */
static Node_T* _AVL(Node_T *ptr, Node_T *abs_root, Node_T *node)
{
    if(node->val < ptr->val)    _AVL(ptr->left, abs_root, node);
    if(node->val > ptr->val)    _AVL(ptr->right, abs_root, node);

    if(ptr->bf < -1){
        // RR
        if(ptr->right->right != NULL){
            abs_root = _leftRotation(abs_root, ptr);
        }
        // RL
        else{
            abs_root = _rightRotation(abs_root, ptr->right);
            abs_root = _leftRotation(abs_root, ptr);
        }
    }
    else if(ptr->bf > 1){
        // LL
        if(ptr->left->left != NULL){
            abs_root = _rightRotation(abs_root, ptr);
        }
        // LR
        else{
            abs_root = _leftRotation(abs_root, ptr->left);
            abs_root = _rightRotation(abs_root, ptr);
        }
    }

    return abs_root;
}

#endif