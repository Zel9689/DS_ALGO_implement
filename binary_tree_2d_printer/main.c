/* test if binary_tree_2dp works */
#include "binary_tree_2dp.h"

int main()
{
    Tree_t *t = create();
    insert(t, 0);
    insert(t, -5);
    insert(t, 3);
    insert(t, -7);
    insert(t, -1);
    binary_tree_2dp(t->root);
    return 0;
}