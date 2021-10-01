/* test if binary_tree_2dp works */
#include "binary_tree_2dp.h"

int main()
{
    Node_T *root = init();
    insert(root, 0);
    insert(root, -5);
    insert(root, 3);
    insert(root, -7);
    insert(root, -1);
    binary_tree_2dp(root);
    return 0;
}