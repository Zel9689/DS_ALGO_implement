#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#ifndef DEBUG
#define SIZE 100
#endif

/* hash function */
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
typedef unsigned long long uint64_t;
static uint64_t hash_key(const char*);

/* member struct */
typedef struct member_s member_t;
struct member_s{
    char *name;
    int age;
    char *phone;
    member_t *next;
};

/* hash table API */
int get_index(const char*);
void put(const char*, int, const char*);
member_t* find(const char*);
void calc_collision(void);
member_t* normal_find(const char*);
void free_member(member_t*);

#endif