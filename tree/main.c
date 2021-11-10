#include <stdio.h>
#include <stdlib.h>
#include "../lib/tree/tree.h"

// 在| |內的數字為同一個node的child，由上而下按照順序為Level0 - Level4
// |0|
// |1, 2, 3, 4|
// |none|21, 22|none|41|
// |none|221|none|none|none|
// |none|2211|none|none|none|

int main()
{
    Node_T *root = init(0);

    Node_T *n1 = insert(root, 1);
    Node_T *n2 = insert(root, 2);
    Node_T *n3 = insert(root, 3);
    Node_T *n4 = insert(root, 4);

    Node_T *n21 = insert(n2, 21);
    Node_T *n22 = insert(n2, 22);
    Node_T *n41 = insert(n4, 41);

    Node_T *n221 = insert(n22, 221);

    Node_T *n2211 = insert(n221, 2211);

    print_edge(root);
    print_edge(n2);
    print_edge(n4);
    print_edge(n22);
    print_edge(n221);

    printf("height of root  = %d\n", getHeight(root));

    search(root, 0);
    search(root, 3);
    search(root, 41);
    search(root, 221);
    search(root, 2211);

    destroy(root);
    return 0;
}