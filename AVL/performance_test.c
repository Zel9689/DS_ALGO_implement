#include <stdio.h>
#include <stdlib.h>
#include "../lib/binary_tree/binary_tree.h"
#include "../lib/binary_tree/binary_tree_2dp.h"
#include <time.h>

int main()
{
    printf("啟用AVL\n");
    enable_AVL();
    Tree_T *t = init(0);
    clock_t start, end;
    start = clock();
    for(int i=1; i<=10000; i++){
        insert(t, i);
        end = clock();
        printf("%.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);   
    }

    printf("關閉AVL\n");
    disable_AVL();
    Tree_T *t2 = init(0);
    start = clock();
    for(int i=1; i<=10000; i++){
        insert(t2, i);
        end = clock();
        printf("%.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);   
    }

    return 0;
}