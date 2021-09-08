#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 10
#endif

void merge(int *A, int front, int mid, int end)
{
    int tmp[end - front + 1];
    for(int i=0; i<end - front + 1; i++){
        tmp[i] = A[i];
    }
    int ptr1 = front;
    int ptr2 = mid + 1;
    while(ptr1 <= mid && ptr2 <= end){
        if(tmp[ptr1] < tmp[ptr2]){
            A[front] = tmp[ptr1];
            ptr1++;
        }else{
            A[front] = tmp[ptr2];
            ptr2++;
        }                
        front++;
    }
    while(ptr1 <= mid)  A[front++] = tmp[ptr1++];
    while(ptr2 <= end)  A[front++] = tmp[ptr2++];
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
    for(int i=0; i<SIZE; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    mergesort(A, 0, SIZE - 1);

    // Print
    for(int i=0; i<SIZE; i++){
        printf("%d ", A[i]);
    }
    return 0;
}