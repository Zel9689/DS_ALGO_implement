// 已知bug，insert和delete不能用index 0，但我不知道怎麼辦
// 不知道如何處理超出範圍的index
#include <stdio.h>
#include <stdlib.h>
typedef struct List List;
struct List
{
    int num;
    List *next;
};
List *search(List *, int);
void append(List *, int);
int insert(List *, int, int);
void delete (List *, int);
void pop(List *);
void free_list(List *);

void append(List *list, int num)
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

int insert(List *list, int index, int num)
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

void delete (List *list, int index)
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

List *search(List *list, int index)
{
    List *target = list;
    for(int i = 0; i < index; i++) {
        target = list->next;
        // if(target == NULL) {
        //     return NULL; // 代表index超出範圍了
        // }
    }
    return target;
}

void print_list(List *list)
{
    int count = 0;
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

int main()
{
    List *a = malloc(sizeof(List)); // create a list named "a"
    a->num = 500;
    a->next = NULL;
    printf("#### 存了第一筆資料:500 ####\n");
    print_list(a);

    append(a, 24);
    printf("#### append一筆資料:24 ####\n");
    print_list(a);

    insert(a, 1, 300);
    printf("#### insert一筆資料:300到index1的地方 ####\n");
    print_list(a);

    pop(a);
    printf("#### pop尾端一筆資料 ####\n");
    print_list(a);

    append(a, 100);
    printf("#### append一筆資料:100 ####\n");
    print_list(a);

    delete(a, 1);
    printf("#### delete一筆在index1的資料 ####\n");
    print_list(a);

    free_list(a);
    return 0;
}

/*
輸出結果：
#### 存了第一筆資料:500 ####
index: 0, num: 500
#### append一筆資料:24 ####
index: 0, num: 500
index: 1, num: 24
#### insert一筆資料:300到index1的地方 ####
index: 0, num: 500
index: 1, num: 300
index: 2, num: 24
#### pop尾端一筆資料 ####
index: 0, num: 500
index: 1, num: 300
#### append一筆資料:100 ####
index: 0, num: 500
index: 1, num: 300
index: 2, num: 100
#### delete一筆在index1的資料 ####
index: 0, num: 500
index: 1, num: 100
*/