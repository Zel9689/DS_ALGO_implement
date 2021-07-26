#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

int main()
{
    int i = 0;
    member_t *bst = init(20, 23, "John");

    i++;
    if(insert(bst, 10, 23, "Amy") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 46, 26, "Alice") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 1, 23, "Raver") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 18, 40, "Jason") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 30, 54, "Robert") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 10, 54, "Test") == 0); // key collision
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 12, 10, "Kid") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 19, 3, "Baby") == 0);
    else    printf("%d failed\n", i);

    i++;
    if(insert(bst, 35, 33, "Ellen") == 0);
    else    printf("%d failed\n", i);

    sort(bst);
    printf("-----------------\n");
    del(bst, 10);
    sort(bst);
    printf("-----------------\n");
    del(bst, 1);
    sort(bst);
    printf("-----------------\n");
    del(bst, 12);
    sort(bst);
    printf("-----------------\n");
    del(bst, 46);
    sort(bst);
    printf("-----------------\n");
    del(bst, 20); // can't del root of bst
    sort(bst);
    printf("-----------------\n");
    modify(bst, 35, 100, "OLDMAN");
    sort(bst);
    printf("-----------------\n");
    destroy(bst);
    return 0;
}