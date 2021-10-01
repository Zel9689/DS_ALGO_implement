#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "../binary_tree_2d_printer/binary_tree_2dp.h"
Tree_t *t;

int main()
{
    // structure 
    //          0
    //         / \
    //       -5   3
    //       /\
    //     -7 -1
    //    /
    //  -9

    // expected output
    //      -5
    //      /\
    //    -7  0
    //    /  / \
    //  -9  -1  3
    t = create();
    insert(t, 0);
    insert(t, -5);
    insert(t, 3);
    insert(t, -7);
    insert(t, -1);
    insert(t, -9);

    binary_tree_2dp(t->root);
    print(t);

    return 0;
}