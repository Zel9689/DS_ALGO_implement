#ifndef _binary_search_tree_h

#define _binary_search_tree_h

typedef struct member_s member_t;
struct member_s{
    member_t* left;
    member_t* right;
    int num;
    int age;
    char *name;
};
// input: num of member; return member
member_t* search(int);
// input: num of member, age, name; return member
member_t* insert(int, int, const char*);
// input: num of member; return -1 代表失敗
int del(int);
// input: num of member, age
void modify_age(int, int);
// input: num of member, name
void modify_name(int, const char*);
// print inorder traversal
void sort(void);
void destroy(void);




#endif