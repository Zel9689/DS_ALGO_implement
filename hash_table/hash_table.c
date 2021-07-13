#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

static uint64_t hash_key(const char* key) {
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}
member_t* bucket[SIZE] = {0};
member_t *normal[SIZE]; //對照組的普通儲存方式
// 根據hash function決定陣列index
int get_index(const char *str_p)
{
    uint64_t hash = hash_key(str_p);
    int index = hash % SIZE;
    return index;
}
// 根據hash的index，在bucket放入member物件
void put(const char *name, int age, const char *phone)
{
    int index = get_index(name); //用名字來取hash值、並轉換成陣列index
    member_t *data = malloc(sizeof(member_t));
    char *n = malloc(sizeof(name));
    char *p = malloc(sizeof(phone));
    strcpy(n, name); strcpy(p, phone);
    data->name = n; data->age = age; data->phone = p;
    if(bucket[index] == NULL)
        bucket[index] = data;
    else
        bucket[index]->next = data;
    //加入對照組的array
    static int i = 0;
    if(i < SIZE)    normal[i] = data;
    i++;
}
// 輸入member名稱，回傳member物件
member_t* find(const char *str)
{
    int index = get_index(str);
    member_t *p = bucket[index];
    while(p != NULL){
        if(strcmp(p->name, str) == 0)   return p; 
        p = p->next;
    }
    return NULL;
}
// 計算碰撞數
void calc_collision()
{
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if(bucket[i] == NULL){
            count++;
        }
    }
    printf("collision: %d / %d\n", count, SIZE);
}
// 對照組的普通查詢
member_t* normal_find(const char *str)
{
    for(int i = 0; i < SIZE; i++)
        if(strcmp(normal[i]->name, str) == 0)   return normal[i];
    return NULL;
}
// 釋放member物件記憶體
void free_member(member_t *M)
{
    free(M->name);
    free(M->phone);
    free(M);
}