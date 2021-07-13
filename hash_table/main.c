#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"
#include <sys/time.h>

int main()
{
    // 塞入padding member資料
    char num[SIZE + 1] = "";
    for(int i = 1; i <= SIZE; i++){
        char fakename[20] = "Member";
        sprintf(num, "%d", i);
        strcat(fakename, num);
        put(fakename, i, "0000000000");
    }
    calc_collision();
    put("John", 23, "0920000000");
    put("Alice", 26, "0935000000");
    put("Amy", 23, "0966000000");
/* ---------------------benchmark------------------------ */
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    for(int i = 1; i <= SIZE; i++){
        char fakename[] = "Member";
        sprintf(num, "%d", i);
        strcat(fakename, num);
        find(fakename);
    }
    gettimeofday(&t1, NULL);
    printf("Hash Table搜尋%d次： %.2g seconds\n", SIZE, t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));
    
    gettimeofday(&t0, NULL);
    for(int i = 1; i <= SIZE; i++){
        char fakename[] = "Member";
        sprintf(num, "%d", i);
        strcat(fakename, num);
        normal_find(fakename);
    }
    gettimeofday(&t1, NULL);
    printf("普通陣列搜尋%d次： %.2g seconds\n", SIZE, t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));
/* ---------------------benchmark------------------------ */
    while(1){
        printf("輸入Member名稱$ ");
        char m[50] = "";
        scanf("%s", &m);
        member_t *M = find(m);
        if(M == NULL)
            printf("沒有找到該Member！\n\n");
        else
            printf("member名稱: %-12s年齡: %-3d\t手機: %-10s\n\n", M->name, M->age, M->phone);
    }
    return 0;
}