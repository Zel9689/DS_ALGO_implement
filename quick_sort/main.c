// 37:25
#include <stdio.h>
#define swap(a, b) do{typeof(a) _tmp = a; a = b; b = _tmp;}while(0);

void solve(int* A, int start, int end)
{
    if(start >= end) return;

    int pivot = A[end];
    int first_big = start;
    int search_small = start + 1;

    while(search_small <= end){
        // 找到第一個比pivot大的數字前都繼續平移指標
        if(A[first_big] <= pivot){
            first_big++;
            search_small++;
            continue;
        }
        // 找到比pivot小的數字，和第一個比pivot大的數字進行交換
        if(A[search_small] <= pivot){
            swap(A[first_big], A[search_small]);
            first_big++;
            search_small++;
            continue;
        }
        // 沒找到比較小，指標往後移動
        search_small++;
    }

    // left side
    solve(A, start, first_big - 2);
    // right side
    solve(A, first_big, end);
}

int main()
{
    int A[] = {1, 3, -1, -5, 8, 6, 10, 2, 5, 7};
    solve(A, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", A[i]);
    }
    return 0;
}