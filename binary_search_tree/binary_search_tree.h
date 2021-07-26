#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

typedef struct member_s member_t;
struct member_s{
    member_t *left;
    member_t *right;
    member_t *parent;
    int key;
    int age;
    char *name;
};
struct result_s{
    member_t *node;
    int pos;
};

// input: key, age, name
// output: intance of bst
member_t* init(int, int, char*);
// input: instance, key of node
// output: result struct{member, position}
struct result_s search(member_t*, int);
// input: instance, key, age, name
// output: success:0 fail:-1
int insert(member_t*, int, int, char*);
// input: instance, key
// output: success:0 fail:-1
int del(member_t*, int);
// input: instance
void sort(member_t*);
// input: instance
void destroy(member_t*);
// input: instance, target key, new age, new name
// output: success:0 fail:-1
int modify(member_t*, int, int, char*);

#endif