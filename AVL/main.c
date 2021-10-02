/* !!編譯時要Define AVL才會啟用AVL的程式碼!! */
#include <stdio.h>
#include <stdlib.h>
#include "../binary_tree/binary_tree.h"
#include "../binary_tree/binary_tree_2dp.h"
#include <time.h>

int main()
{
    for(int i=0; i<2; i++){
    Tree_T *t = init(5);
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
    printf("刪除node:7，AVL state:%d\n", i);
    del(t, 7);
    binary_tree_2dp(t);
    sort(t);
    printf("\n\n");
    enable_AVL();
    }
    return 0;
}