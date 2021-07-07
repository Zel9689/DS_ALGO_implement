#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 4 //實際空間是LIMIT - 1，會浪費一個空間
int queue[LIMIT] = {0};
int rear = 0;
int front = 0;

bool isFull()
{
    if((rear+1) % LIMIT == front)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if(rear == front)
        return true;
    else
        return false;
}
void state()
{
    int used = rear - front;
    if(used < 0){
        used = used + LIMIT;
    }
    printf("%d / %d - 已使用 / 總共\n\n", used, LIMIT - 1);
}
void enqueue(int n)
{
    if(isFull() == true){
        printf("queue滿了, %d 無法加入\n", n);
    }else{
        rear++;
        rear = rear % LIMIT;
        queue[rear] = n;
        printf("%d 加入 queue\n", n);
    }
    state();
}
void dequeue()
{
    if(isEmpty() == true){
        printf("queue是空的, 無法刪除\n");
    }else{
        front++;
        front = front % LIMIT;
        printf("%d 被移出 queue\n", queue[front]);
    }
    state();
}
void print(int rear, int front)
{
    printf("----> ");
    while(rear != front){
        printf("%d ", queue[rear]);
        rear--;
        rear = (rear + LIMIT) % LIMIT;
    }
    printf("---->\n\n");
}

int main()
{
    while(1)
    {
        char cmd[20] = "";
        int num = 0;
        printf("輸入cmd $ ");
        scanf("%s", &cmd);
        if(strcmp(cmd, "enq") == 0){
            scanf("%d", &num);
            enqueue(num);
        }else if(strcmp(cmd, "deq") == 0){
            dequeue();
        }else if(strcmp(cmd, "print") == 0){
            print(rear, front);
        }else if(strcmp(cmd, "help") == 0 || strcmp(cmd, "h") == 0){
            printf("\
- help -\n\
enq 1  -  把1推進queue\n\
deq     - 將最上層的數字移出queue\n\
print   - 印出目前queue的內容\n\
help, h - 顯示這個訊息\n\n");
        }
    }
    return 0;
}