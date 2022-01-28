#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

//------------------------------
//+      Global variables      +
//------------------------------
typedef struct employee
{
    int code,salary;
    char* name;
}emp;

typedef struct node
{
    struct employee *emp;
    struct node* next;
    struct node* previous;
}node;

typedef struct linkedlist
{
    struct node *start;
    struct node *end;
}list;

//------------------------
//+      Prototypes      +
//------------------------
node* createNode(emp* emp1);
void append(list* list, emp*);
node* search(list* list, int key);
int delete(list* list, int key);
int freeList(list* list);

#endif