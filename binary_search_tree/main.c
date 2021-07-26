#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

int main()
{
    while(1){
        int num;
        int age = -1;
        char name[30] = "";
        printf("輸入(編號, 年齡, 姓名)： ");
        scanf("%d %d %s", &num, &age, &name);
        if(num == -1) break;
        member_t *m = insert(num, age, name);
        printf("編號: %d  姓名: %s  年齡: %d 已輸入。\n", m->num, m->name, m->age);
        printf("編號輸入-1跳出\n\n");
    }
    sort();
    return 0;
}