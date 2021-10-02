#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_2dp.h"

static int height_of_tree = 0;
static int depth_of_node = -1;

static void _binary_tree_2dp_inorder(Node_T*);

void binary_tree_2dp(Tree_T *t)
{
    if(t->root == NULL){
        printf("The tree is null\n");
        return;
    }
    height_of_tree = t->root->height;
    _binary_tree_2dp_inorder(t->root);
    printf("\n");
}

static void _binary_tree_2dp_inorder(Node_T *node)
{
    depth_of_node++;
    if(node == NULL){
        depth_of_node--;
        return;
    }
    _binary_tree_2dp_inorder(node->left);
    printf(">");
    for(int i=0; i<(height_of_tree - depth_of_node); i++){
        printf("    ");
    }
    printf("%4d", node->val);
    if(depth_of_node == 0)  printf(" --[root]");
    printf("\n");
    _binary_tree_2dp_inorder(node->right);
    depth_of_node--;
}