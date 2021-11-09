#include <stdio.h>
#include <stdlib.h>
#include "../lib/tree/tree.h"

int main()
{
    Node_T *root = init(123);
    Node_T* node5 = insert(root, 5);
    insert(root, 7);
    Node_T* node9 = insert(root, 9);
    insert(root, 11);
    insert(node9, 555);
    insert(node9, 777);
    insert(node9, 999);
    print_edge(root);
    print_edge(node5);
    print_edge(node9);






    return 0;
}