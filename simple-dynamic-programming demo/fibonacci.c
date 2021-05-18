// dynamic programming simple example
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool flag[6] = {true, true}; // 這個數字是否被算過的flag
int table[6] = {1, 1}; // 對應答案的table
int f(int n)
{
    if(flag[n]) {
        return table[n]; // 如果已經算過了就回傳
    }
    else {
        // 沒有算過就先存進table，立flag，回傳
        table[n] =  f(n-1) + f(n-2);
        flag[n] = true;
        return table[n];
    }  
}
int main(void)
{
    int ans = f(5);
    printf("%d", table[5]);
    return 0;
}

// 1 1 2 3 5 8