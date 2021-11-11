#include <stdio.h>
#include <stdlib.h>
#include "../lib/linked_list/linked_list.h"

int main()
{
    printf("[init list with val: 1]\n");
    Node_T *list = init(1);
    print(list);
    
    printf("[pop list]\n");
    pop(list);
    print(list);
    
    printf("[append 1]\n");
    append(list, 1);
    print(list);    

    printf("[insert -1 to index 0]\n");
    insert(list, 0, -1);
    print(list);
    
    printf("[insert 0 to index 1]\n");
    insert(list, 1, 0);
    print(list);
    
    printf("[insert 2 to index 3]\n");
    insert(list, 3, 2);
    print(list);

    printf("[insert 3 to index 5]\n");
    insert(list, 5, 3);
    print(list);
    
    printf("[search for a node has val 3]\n");
    Node_T *n = search(list, 3);
    printf("address of searched node: %p\n\n", n);

    printf("[search and delete a node has val 0]\n");
    n = search(list, 0);
    del(list, n);
    print(list);

    printf("[reverse list]\n");
    reverse(list);
    print(list);

    return 0;
}