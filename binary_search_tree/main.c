#include <stdio.h>
#include <stdlib.h>
#include "../binary_tree/binary_tree.h"
#include "../binary_tree/binary_tree_2dp.h"

typedef struct Member Member_T;
struct Member{
    int age;
    char *name;
    char *occupation;
};

Member_T* member_init(int age, char *name, char *occupation)
{
    Member_T *m = malloc(sizeof(Member_T));
    m->age = age;
    m->name = name;
    m->occupation = occupation;
    return m;
}

int main()
{
    /* create tree with member data */
    printf("[Initialize Tree]\n");
    Tree_T* t = init(20);
    t->root->data = member_init(23, "John", "Student");

    Node_T* n = insert(t, 10);
    n->data = member_init(23, "Amy", "Student");

    n = insert(t, 46);
    n->data = member_init(26, "Alice", "Accountant");

    n = insert(t, 1);
    n->data = member_init(23, "Raver", "Engineer");

    n = insert(t, 18);
    n->data = member_init(40, "Jason", "Freelancer");

    n = insert(t, 30);
    n->data = member_init(54, "Robert", "Teacher");

    /* try to insert a duplicate number */
    n = insert(t, 20);

    /* sort and print 2d*/
    sort(t);
    binary_tree_2dp(t);

    /* search node 18 and print info */
    printf("[Search node 18 and print info]\n");
    n = search(t, 18);
    printf("Node: %d\nAge: %d\nName: %s\nOccupation: %s\n\n",\
        n->val, \
        ((Member_T*)n->data)->age, \
        ((Member_T*)n->data)->name, \
        ((Member_T*)n->data)->occupation);

    /* delete node 46 */
    printf("[Delete node 46]\n");
    del(t, 46);
    binary_tree_2dp(t);

    /* delete root */
    printf("[Delete root]\n");
    del(t, 20);
    binary_tree_2dp(t);

    /* get parent of node 1 */
    printf("[Get parent of node 1]\n");
    n = get_parent(t, 1);
    printf("Node: %d\nAge: %d\nName: %s\nOccupation: %s\n\n",\
        n->val, \
        ((Member_T*)n->data)->age, \
        ((Member_T*)n->data)->name, \
        ((Member_T*)n->data)->occupation);

    /* get Height of node 10 */
    printf("[Get Height of node 10]\n");
    int h = getHeight(n);
    printf("Height: %d\n\n", h);

    /* destroy Tree */
    printf("[Destroy Tree and Print]\n");
    destroy(t);
    binary_tree_2dp(t);

    return 0;
}