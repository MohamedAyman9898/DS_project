#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

//------------------------------
//+      Global variables      +
//------------------------------
typedef struct employee
{
    int code;
    int salary;
    char name[25];
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
    int numOfNodes;
}list;

//------------------------
//+      Prototypes      +
//------------------------
node* createNode(emp* emp1);
void append(list* list, emp*);
node* search(list* list, int key);
int delete(list* list, int key);
int freeList(list* list);
void printList(list* list);

#endif