#include <stdio.h>
#include <string.h>
#define LIMIT 5

int stack[LIMIT] = {0};
int top = 0; //指的是尚未寫入的

void state()
{
    printf("[%d / %d - 已使用 / 總共]\n\n", top, LIMIT);
}
void push(int n)
{
    if(top != LIMIT){
        stack[top] = n;
        printf("%d 已經push進stack\n", n);
        top++;
    }else{
        printf("stackoverflow! %d 無法push\n", n);
    }
    state();
}
void pop()
{
    if(top != 0){
        top--;
        printf("%d 已經pop出stack\n", stack[top]);
    }else{
        printf("stackunderflow! 無法pop\n");
    }
    state();
}
void print()
{
    printf("目前stack內容：\n---> ");
    for(int i = 0; i < top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    state();
}
int main()
{
    while(1)
    {
        char cmd[10] = "";
        int num = 0;
        printf("輸入cmd $ ");
        scanf("%s", &cmd);
        if(strcmp(cmd, "push") == 0){
            scanf("%d", &num);
            push(num);
        }else if(strcmp(cmd, "pop") == 0){
            pop();
        }else if(strcmp(cmd, "print") == 0){
            print();
        }else if(strcmp(cmd, "help") == 0 || strcmp(cmd, "h") == 0){
            printf("\
- help -\n\
push 1  - 把1推進stack\n\
pop     - 將最上層的數字移出stack\n\
print   - 印出目前stack的內容\n\
help, h - 顯示這個訊息\n");
        }
    }
    return 0;
}