#include <stdio.h>
#include <stdlib.h>
#define Height 3
#define Amount ((1 << Height) - 1)
#define swap(a, b) ({typeof(a) tmp = a; a = b; b = tmp;})
#define L_CHILD(index) (index * 2 + 1)
#define R_CHILD(index) (index * 2 + 2)
#define PARENT(index) ((index - 1) / 2)

// val == 0 當作空節點
int Tree[Amount] = {0};

// 向上bubble
void heapify_up(int index)
{
    while(Tree[index] < Tree[PARENT(index)]){
        swap(Tree[index], Tree[PARENT(index)]);
        index = PARENT(index);
    }
}

// 向下bubble
void heapify_down(int index)
{
    // 節點比左節點或右節點還大
    while(Tree[index] > Tree[L_CHILD(index)] || Tree[index] > Tree[R_CHILD(index)]){
        if(Tree[L_CHILD(index)] == 0 && Tree[R_CHILD(index)] == 0){
            break;
        }
        else if(L_CHILD(index) >= Amount){
            break;
        }
        else if(Tree[R_CHILD(index)] == 0 || (Tree[L_CHILD(index)] < Tree[R_CHILD(index)] && Tree[L_CHILD(index)] != 0)){
            swap(Tree[index], Tree[L_CHILD(index)]);
            index = L_CHILD(index);
        }
        else if(Tree[L_CHILD(index)] == 0 || (Tree[L_CHILD(index)] > Tree[R_CHILD(index)] && Tree[R_CHILD(index)] != 0)){
            swap(Tree[index], Tree[R_CHILD(index)]);
            index = R_CHILD(index);
        }
    }
}

// 回傳指定節點的index
int search(int val)
{
    for(int i = 0; i < Amount; i++){
        if(Tree[i] == val)
            return i;
    }
    return -1;
}

void insert(int val)
{
    int i;
    for(i = 0; i < Amount; i++){
        if(Tree[i] == 0){
            Tree[i] = val;
            heapify_up(i);
            break;
        }
    }
}

void del(int val)
{
    int del_i = search(val);
    if(del_i == -1) return;

    int null_i;
    for(null_i = 0; null_i < Amount; null_i++){
        if(Tree[null_i] == 0){
            break;
        }
    }

    Tree[del_i] = Tree[null_i - 1];
    Tree[null_i - 1] = 0;

    heapify_down(del_i);
}

void sort()
{
    while(Tree[0] != 0){
        printf("%d ",Tree[0]);
        del(Tree[0]);
    }
    printf("\n\n");
}

void print()
{
    for(int i = 0; i < Amount; i++){
        printf("%d ", Tree[i]);
    }
    printf("\n\n");
}

int main()
{
    printf("陣列index0為root，由左至右、由上至下依序排放進陣列\n\n");
    printf("插入20\n");
    insert(20);
    print();

    printf("插入10\n");
    insert(10);
    print();

    printf("插入25\n");
    insert(25);
    print();

    printf("插入12\n");
    insert(12);
    print();

    printf("插入5\n");
    insert(5);
    print();

    printf("插入8\n");
    insert(8);
    print();

    printf("插入15\n");
    insert(15);
    print();

    printf("刪除100(不存在)\n");
    del(100);
    print();

    printf("刪除20\n");
    del(20);
    print();

    printf("刪除5\n");
    del(5);
    print();

    printf("由小到大Sorting(Heap Tree將會被清空)\n");
    sort();

    return 0;
}