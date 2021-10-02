#include <stdio.h>
#include <stdlib.h>
#include "../binary_tree/binary_tree.h"
#include "../binary_tree/binary_tree_2dp.h"

int main()
{
    Tree_T* t = init(5);
    binary_tree_2dp(t);
    insert(t, -5);
    binary_tree_2dp(t);
    insert(t, 10);
    binary_tree_2dp(t);
    insert(t, 0);
    binary_tree_2dp(t);
    insert(t, 7);
    binary_tree_2dp(t);
    insert(t, -7);
    binary_tree_2dp(t);
    insert(t, -1);
    binary_tree_2dp(t);
    insert(t, -5);
    binary_tree_2dp(t);
    del(t, 7);
    binary_tree_2dp(t);

    return 0;
}