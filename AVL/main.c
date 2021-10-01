#include <stdio.h>
#include <stdlib.h>
#include "../binary_tree/binary_tree.h"
#include "../binary_tree/binary_tree_2dp.h"

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
    Node_T* root = init(0);
    root = insert(root, -5);
    root = insert(root, 3);
    root = insert(root, -7);
    root = insert(root, -1);
    root = insert(root, -9);
    binary_tree_2dp(root);
    sort(root);


    // expected output
    //      -7
    //      /\
    //    -9  0
    //       / \
    //      -1  3
    root = del(root, -5);
    binary_tree_2dp(root);
    sort(root);

    return 0;
}