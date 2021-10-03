#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#define max(a, b) ({ \
    typeof (a) _a = (a); \
    typeof (b) _b = (b); \
    _a > _b ? _a : _b; \
})
#define MACRO_AVL(root, node) (_AVL(root, root, node))
static Node_T* _search(Node_T *node, int);
static Node_T* _get_parent(Node_T *node, int);
static struct root_and_node _insert(Node_T *root, int);
static Node_T* _del(Node_T *root, int);
static void _destroy(Node_T *root);
static void _sort(Node_T *root);
static void _updateNodes(Node_T *root, Node_T *node);
static Node_T* _leftRotation(Node_T *root, Node_T *node);
static Node_T* _rightRotation(Node_T *root, Node_T *node);
static Node_T* _AVL(Node_T *root, Node_T *abs_root, Node_T *node);
static int _run_avl = 0;
struct root_and_node{Node_T *root; Node_T *node;};
/*--------------API for Users--------------*/
void enable_AVL()
{
    _run_avl = 1;
}
void disable_AVL()
{
    _run_avl = 0;
}
Tree_T* init(int val)
{
    Tree_T *t = malloc(sizeof(Tree_T));
    Node_T *root = malloc(sizeof(Node_T));
    t->root = root;
    root->left = 0;
    root->right = 0;
    root->val = val;
    root->data = 0;
    root->height = 0;
    root->bf = 0;
    return t;
}
Node_T* search(Tree_T *t, int val)
{
    if(t == NULL) return NULL;
    return _search(t->root, val);
}
Node_T* get_parent(Tree_T *t, int val)
{
    if(t == NULL) return NULL;
    return _get_parent(t->root, val);
}
/* Return the inserted node */
Node_T* insert(Tree_T *t, int val)
{
    if(t == NULL) return NULL;
    return _insert(t->root, val).node;
}
void del(Tree_T *t, int val)
{
    if(t == NULL) return;
    t->root = _del(t->root, val);
}
void destroy(Tree_T *t)
{
    if(t == NULL) return;
    _destroy(t->root);
    free(t);
    t->root = NULL;
}
void sort(Tree_T *t)
{
    if(t == NULL) return;
    _sort(t->root);
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

/*--------------Private Method--------------*/
static Node_T* _search(Node_T *node, int val)
{
    Node_T *ptr = node;
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

static Node_T* _get_parent(Node_T *node, int val)
{
    Node_T *ptr = node;
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

static struct root_and_node _insert(Node_T *root, int val)
{
    Node_T *node = NULL;
    if(_search(root, val) == NULL){
        node = malloc(sizeof(Node_T));
        Node_T *parent = _get_parent(root, val);
        node->val = val;
        if(val < parent->val)   parent->left = node;
        else                    parent->right = node;

        _updateNodes(root, node);
        if(_run_avl)
            root = MACRO_AVL(root, node);
    }
    struct root_and_node x;
    x.root = root; x.node = node;
    return x;
}

static Node_T* _del(Node_T *root, int val)
{
    /* 至少要交接3個屬性: parent的left or right, left, right
       如果替代node是左樹中最大node，則還要再刪除一個替代node的parent的left or right */
    Node_T *node = _search(root, val);
    Node_T *parent = _get_parent(root, val);
    if(node == NULL)    return root;
    Node_T *replace; /* replace會取代被刪除的node */
    if(node->left != NULL){
        /* 尋找左樹最大node */
        replace = node->left;
        while(replace->right != NULL)   replace = replace->right;
        /* 確認replace是否為左樹第一個node、避免node互指 */
        if(node->left != replace){
            // tmp is parent of replace node
            Node_T *tmp = node->left;
            while(tmp->right->right != NULL)   tmp = tmp->right;
            tmp->right = NULL;

            replace->left = node->left;
        }
        replace->right = node->right;
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
        if(_run_avl)
            root = MACRO_AVL(root, parent);
    }else{
        _updateNodes(root, replace);
        if(_run_avl)
            root = MACRO_AVL(root, replace);
    }
    
    free(node);
    return root;
}

static void _destroy(Node_T *ptr)
{
    if(ptr == NULL) return;
    _destroy(ptr->left);
    _destroy(ptr->right);
    free(ptr);
}

static void _sort(Node_T *ptr)
{
    if(ptr == NULL) return;
    _sort(ptr->left);
    printf("val: %d, height: %d, balance_factor: %d\n", ptr->val, ptr->height, ptr->bf);
    _sort(ptr->right);
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
    Node_T *parent = _get_parent(root, node->val);
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
    Node_T *parent = _get_parent(root, node->val);
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

/* ptr is the same as abs_root, and the recursive will change ptr every call, 
   since we need a original one to pass in Rotations, we need to pass a copy in */
static Node_T* _AVL(Node_T *ptr, Node_T *abs_root, Node_T *node)
{
    if(node->val < ptr->val)    _AVL(ptr->left, abs_root, node);
    if(node->val > ptr->val)    _AVL(ptr->right, abs_root, node);

    if(ptr->bf < -1){
        // RL
        if(ptr->right->bf > 0){
            abs_root = _rightRotation(abs_root, ptr->right);
            abs_root = _leftRotation(abs_root, ptr);
        }
        // RR
        else{
            abs_root = _leftRotation(abs_root, ptr);
        }
    }
    else if(ptr->bf > 1){
        // LR
        if(ptr->left->bf < 0){
            abs_root = _leftRotation(abs_root, ptr->left);
            abs_root = _rightRotation(abs_root, ptr);
        }
        // LL
        else{
            abs_root = _rightRotation(abs_root, ptr);
        }
    }

    return abs_root;
}