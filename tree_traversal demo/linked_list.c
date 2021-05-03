// 在list的index0放值為0的節點，這樣對index0修改時，函式內的處理是一樣的流程
// 不知道如何處理超出範圍的index
#include <stdio.h>
#include <stdlib.h>
#include "./linked_list.h"



List * list_init()
{
    List *null_head = malloc(sizeof(List));
    null_head->num = 0;
    null_head->next = NULL;
    return null_head;
}
void append(List *list, struct Node *num)
{
    List *current = list;
    while (1) // 跑到最後一個鍊結
    {
        if (current->next == NULL)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    }
    current->next = malloc(sizeof(List)); // 尾端加上新鍊結
    current = current->next;
    current->num = num;
    current->next = NULL;
}

int insert(List *list, int index, struct Node *num)
{
    List *current = search(list, index - 1); // 取目標index的前一個鍊結
    // if(current == 1) {
    //     return 1;
    // }
    List *tmp = current->next; // 先保存即將被插隊的鍊結
    current->next = malloc(sizeof(List)); // 創立新的鍊結，並使next指向它
    current = current->next;
    current->num = num;
    current->next = tmp; // 新的鍊結的next指向被插入的鍊結
}

void del(List *list, int index)
{
    List *current = search(list, index - 1); // 取目標index的前一個鍊結
    // if(current == 1) {
    //     return 1;
    // }
    current->next = current->next->next;
}

void pop(List *list)
{
    List *current = list;
    List *tmp;
    while(1) {
        if(current->next == NULL){
            break;
        }else {
            tmp = current; // 保存current的前一個鍊結
            current = current->next;
        }
    }
    tmp->next = NULL; // 把倒數第二個鍊結的next，指向NULL
}

List * search(List *list, int index)
{
    index = index + 1;
    List *target = list;
    for(int i = 0; i < index; i++) {
        target = target->next;
        // if(target == NULL) {
        //     return NULL; // 代表index超出範圍了
        // }
    }
    return target;
}

void print_list(List *list)
{
    int count = -1;
    List *current = list;
    while(1) {
        printf("index: %d, num: %d\n", count, current->num);
        if(current->next == NULL){
            break;
        }else {
            count++;
            current = current->next;
        }
    }
}

void free_list(List *list)
{
    List *tmp;
    while(1) {
        tmp = list->next;
        free(list);
        list = tmp;
        if(list == NULL){
            break;
        }
    }
}