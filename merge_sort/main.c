#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 10
#endif

// front, mid, end為陣列A的index
void merge(int *A, int front, int mid, int end)
{
    // 將要比較的數值寫到tmp陣列
    int tmp_len = end - front + 1;
    int tmp[tmp_len];
    for(int i=0; i<tmp_len; i++){
        tmp[i] = A[front + i];
    }

    // 兩組數據比較，較小的就提交到陣列A，ptr++
    int ptr1 = 0; //第一組數據的ptr
    int ptr2 = (0 + (tmp_len - 1)) / 2 + 1; // 頭尾相加除以2得中間值，得到第二組數據的ptr
    while(ptr1 <= (0 + (tmp_len - 1)) / 2 && ptr2 <= tmp_len - 1){
        if(tmp[ptr1] < tmp[ptr2]){
            A[front] = tmp[ptr1];
            ptr1++;
        }else{
            A[front] = tmp[ptr2];
            ptr2++;
        }                
        front++;
    }
    // 將剩下沒跑完的數據全部提交到陣列A
    while(ptr1 <= (0 + (tmp_len - 1)) / 2)  A[front++] = tmp[ptr1++];
    while(ptr2 <= tmp_len - 1)              A[front++] = tmp[ptr2++];
}

void mergesort(int *A, int front, int end)
{
    if(front == end)    return;
    int mid = (front + end) / 2;
    mergesort(A, front, mid);
    mergesort(A, mid + 1, end);
    merge(A, front, mid, end);
}

int main()
{
    // 自動產生亂數
    srand(time(NULL));
    int A[SIZE] = {0};
    for(int i=0; i<SIZE; i++){
        int sign = (rand()%2);
        if(sign == 0)   sign = -1;
        else            sign = 1;
        A[i] = ((rand()%100)+1) * sign;
    }

    // Print
    printf("source: ");
    for(int i=0; i<SIZE; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    mergesort(A, 0, SIZE - 1);

    // Print
    printf("sorted: ");
    for(int i=0; i<SIZE; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}