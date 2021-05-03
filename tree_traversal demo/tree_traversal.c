#include <stdio.h>
#include <stdlib.h>
#include "./linked_list.h"
// tree節點分佈
//       0
//      / \
//     1   2
//    / \   \
//   3   4   5
//  / \     / \
// 6   7   8   9

/* 直接用打的建tree，回傳root指標 */
struct Node * construct_tree()
{
    struct Node *root = malloc(sizeof(struct Node));
    root->value = 0;
    root->left = malloc(sizeof(struct Node));
    root->left->value = 1;
    root->right = malloc(sizeof(struct Node));
    root->right->value = 2;
    root->left->left = malloc(sizeof(struct Node));
    root->left->left->value = 3;
    root->left->right = malloc(sizeof(struct Node));
    root->left->right->value = 4;
    root->right->right = malloc(sizeof(struct Node));
    root->right->right->value = 5;
    root->left->left->left = malloc(sizeof(struct Node));
    root->left->left->left->value = 6;
    root->left->left->right = malloc(sizeof(struct Node));
    root->left->left->right->value = 7;
    root->right->right->left = malloc(sizeof(struct Node));
    root->right->right->left->value = 8;
    root->right->right->right = malloc(sizeof(struct Node));
    root->right->right->right->value = 9;
    return root;
}
/* preorder traversal */
void pre_traversal(struct Node *p)
{
    if(p == NULL){
        return;
    }
    printf("%d", p->value);
    pre_traversal(p->left);
    pre_traversal(p->right);
}
/* inorder traversal */
void in_traversal(struct Node *p)
{
    if(p == NULL){
        return;
    }
    in_traversal(p->left);
    printf("%d", p->value);
    in_traversal(p->right);
}
/* postorder traversal */
void post_traversal(struct Node *p)
{
    if(p == NULL){
        return;
    }
    post_traversal(p->left);
    post_traversal(p->right);
    printf("%d", p->value);
}
/* levelorder traversal */
void level_traversal(struct Node *root)
{
    List *queue = list_init(); // create a queue
    append(queue, root); // enqueue
    while(search(queue, 0) != NULL){ // 一直做，直到queue是空的
        struct Node *p = search(queue, 0)->num; // 將指標指向queue的front node(先進入的)
        if(p->left != NULL)
            append(queue, p->left); // 如果該node有left child就enqueue
        if(p->right != NULL)
            append(queue, p->right); // 如果該node有right child就enqueue
        del(queue, 0); // dequeue
        printf("%d", p->value); // 印出被dequeue掉的node
    }
}
/* preorder traversal implement in stack */
void pre_traversal_stack(struct Node *root)
{
    List *stack = list_init(); // create a stack
    insert(stack, 0, root); // push
    while(search(stack, 0) != NULL){ // 一直做，直到stack是空的
        struct Node *p = search(stack, 0)->num; // 指標指到top
        del(stack, 0); // pop
        printf("%d", p->value); // 印出被pop的node
        if(p->right != NULL)
            insert(stack, 0, p->right); // 如果該node有right child就push
        if(p->left != NULL)
            insert(stack, 0, p->left); // 如果該node有left child就push
    }
}
int main()
{
    struct Node *root = construct_tree();
    printf("Preorder: ");
    pre_traversal(root);
    printf("\n");
    printf("Inorder: ");
    in_traversal(root);
    printf("\n");
    printf("Postorder: ");
    post_traversal(root);
    printf("\n");
    printf("Level: ");
    level_traversal(root);
    printf("\n");
    printf("Preorder\(stack): ");
    pre_traversal_stack(root);
    printf("\n");
    return 0;
}

/* 輸出結果 */
// Preorder: 0136742589
// Inorder: 6371402859
// Postorder: 6734189520
// Level: 0123456789
// Preorder(stack): 0136742589