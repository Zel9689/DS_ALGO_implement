#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

member_t* init(int key, int age, char *name)
{
    member_t* m = malloc(sizeof(member_t));
    m->left = NULL;
    m->right = NULL;
    m->parent = NULL;
    m->key = key;
    m->age = age;
    int name_len = strlen(name) + 1;
    m->name = malloc(name_len);
    strncpy(m->name, name, name_len);
    return m;
}

struct result_s search(member_t *m, int key)
{
    int pos;
    while(1){
        if(key == m->key){
            pos = 0;
            break;
        }

        if(key < m->key){
            if(m->left == NULL){
                pos = 1;
                break;
            }else{
                m = m->left;
            }
        }
        
        if(key > m->key){
            if(m->right == NULL){
                pos = 2;
                break;
            }else{
               m = m->right;
            }
        }
    }
    struct result_s result = {node:m, pos:pos};
    return result;
}

int insert(member_t *r, int key, int age, char *name)
{
    struct result_s result = search(r, key);
    if(result.pos == 0) return -1;

    member_t *m = init(key, age, name);
    if(result.pos == 1){
        m->parent = result.node;
        result.node->left = m;
    }
    if(result.pos == 2){
        m->parent = result.node;
        result.node->right = m;
    }
    return 0;
}
// new_kid takes old_kid's parent away
void kids_changer(member_t *new_kid, member_t *old_kid)
{
    int pos;
    new_kid->parent = old_kid->parent;
    if(old_kid->key < old_kid->parent->key)
        old_kid->parent->left = new_kid;
    else
        old_kid->parent->right = new_kid;
}
int del(member_t *m, int key)
{
    if(key == m->key)   return -1;
    struct result_s result = search(m, key);
    if(result.pos != 0) return -1;
    
    m = result.node;
    if(m->left != NULL){
        member_t *max_m = m->left;
        while(max_m->right != NULL)    max_m = max_m->right;
        
        if(max_m != m->left){
            max_m->parent->right = NULL;
            max_m->left = m->left;
            m->left->parent = max_m;
        }
        if(m->right != NULL){
            max_m->right = m->right;
            m->right->parent = max_m; // what if he has no right node
        }
        kids_changer(max_m, m);
        
        
    }
    else if(m->right != NULL){
        kids_changer(m->right, m);
    }
    else{
        if(m->key < m->parent->key) m->parent->left = NULL;
        else                        m->parent->right = NULL;
    }
    free(m->name);
    free(m);
}

void sort(member_t *m)
{
    if(m == NULL)
        return;
    sort(m->left);
    printf("編號: %d  姓名: %s  年齡: %d\n", m->key, m->name, m->age);
    sort(m->right);
}

void destroy(member_t *m)
{
    if(m == NULL)
        return;
    destroy(m->left);
    destroy(m->right);
    free(m->name);
    free(m);
}

int modify(member_t *m, int key, int age, char *name)
{
    struct result_s result = search(m, key);
    if(result.pos != 0) return -1;
    if(key == m->key) return -1;
    m = result.node;
    member_t *new_m = init(key, age, name);
    kids_changer(new_m, m);
    new_m->left = m->left;
    new_m->right = m->right;
    free(m->name);
    free(m);
}
