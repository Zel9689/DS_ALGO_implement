#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

// 我不知道root到底需不需要先初始化？
// 應該不用，除了insert之外的函式都會用search，search就會回傳NULL，初始化的工作在insert做就好
// 要，有root後這些函式才有意義，所以root和函式應該包在一個struct初始化
static member_t *root = NULL;

member_t* search(int num)
{
    member_t *m = root;
    while(1){
        if(num < m->num)    m = m->left;
        if(num > m->num)    m = m->right;
        if(m == NULL || num == m->num)  break;
    }
    return m;
}
// 我卡在我覺得search跟insert的迴圈很像，想融合在一起，但想不到辦法
// 還有該怎麼決定編號，一開始想自動編號，讓樹的高度越矮越好
member_t* insert(int num, int age, const char *name)
{
    int len = strlen(name) + 1;
    member_t *m_new = malloc(sizeof(member_t));
    m_new->num = num;
    m_new->age = age;
    m_new->name = malloc(len);
    strncpy(m_new->name, name, len);
    if(root == NULL){
        root = m_new;
        return m_new;
    }

    member_t *m = root;
    while(1){
        if(num < m->num){
            if(m->left == NULL){
                m->left = m_new;
                return m_new;
            }else{
                m = m->left;
            }
        }
        else if(num > m->num){
            if(m->right == NULL){
                m->right = m_new;
                return m_new;
            }else{
                m = m->right;
            }
        }
        else    return NULL;
    }
}

int del(int num)
{
    member_t *m = search(num);
    if(m == NULL) return -1;
    
    member_t *m_max = m->left;
    member_t *m_prev;
    while(m_max->right != NULL){
        m_prev = m_max;
        m_max = m_max->right;
    }
    m_prev->right = NULL;
    m_max->left = m->left;
    m_max->right = m->right;
    free(m);
}

void inorder(member_t *m)
{
    if(m == NULL) return;
    inorder(m->left);
    printf("編號: %d  姓名: %s  年齡: %d\n", m->num, m->name, m->age);
    inorder(m->right);
}
void sort()
{
    inorder(root);
}

void postorder(member_t *m)
{
    if(m == NULL) return;
    postorder(m->left);
    postorder(m->right);
    free(m->name);
    free(m);
}
void destroy(){
    postorder(root);
}


// 改成要傳instance進去
// insert不回傳物件回去給main，main只會拿到root instance
// insert後要印東西，自己在function中call print
// 寫parent，程式會比較簡潔
// 寫init創root
// insert中判斷是否有parent 沒有的就是root