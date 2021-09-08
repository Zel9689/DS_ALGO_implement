#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 10
#endif

#define swap(a, b) while(1){ int tmp = a; a = b; b = tmp; break; }
#define max(a, b) (a >= b)? a:b

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

    // Bubble Sort
    for(int j = 1; j <= SIZE - 1; j++){
        for(int i = 0; i < SIZE - j; i++){
            if(max(A[i], A[i+1]) != A[i+1]){
                swap(A[i], A[i+1]);
            }
        }
    }

    // Print
    for(int i=0; i<SIZE; i++){
        printf("%d ", A[i]);
    }
    return 0;
}