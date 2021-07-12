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
typedef struct member_s member_s;
struct member_s{
    char *name;
    int age;
    char *phone;
    member_s *next;
};

/* hash table API */
int get_index(char*);
void put(char*, int, char*);
member_s* find(char*);
void calc_collision(void);
member_s* normal_find(char*);

#endif