#include<stdio.H>
#include<STDLIB.H>
#include<conio.h>
#include<string.h>
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
void selectionSort(list* list, int choice);
void swap(list*, node *, node *);
void printList(list* list);
char *toLower(char* str);

void main(void)
{
    // emp* emp1;
    // emp* emp2;
    // node* node1;
    // node* node2;
    // list list1;
    // list1.numOfNodes=0;
    // emp1 = (emp*)malloc(sizeof(emp));
    // emp2 = (emp*)malloc(sizeof(emp));
    // node1 = (node*) malloc(sizeof(node));
    // node2 = (node*) malloc(sizeof(node));
    // node1->next = node2;
    // node1->previous = 0;
    // node1->emp->salary = 100;
    // node2->next = 0;
    // node2->previous = node1;
    // node2->emp->salary = 50;
    // list1.end = node2;
    // list1.start = node1;

    char str1[] = "Mohamed";
    char str2[] = "Ahmed";
    int r = strcmp(str1,str2);
    printf("%d",r);
    getch();


}

void selectionSort(list* list, int choice)
{
    int n = list->numOfNodes;
    int i,j,pos=0;
    node* index = list->start;
    node* temp = index;
    for(i=0; i<n; i++)
    {  
        temp = list->start;
        pos = 0;
        while (pos < i)
        {
            temp = temp->next;
            pos++;
        }

        for(j=i; j < (n-1); j++)
        {
            if(choice == 1)     //salary sort
            {
                /*printf("\nsorting\n");
                printf("temp->salary:%d\t", temp->emp->salary);
                printf("temp->next->salary:%d", temp->next->emp->salary);
                printf("\ntemp: %p", temp);
                printf("\ntemp next: %p", temp->next);*/

                if( (temp->emp->salary) > (temp->next->emp->salary) )
                {
                    index = (temp->next);
                }
                temp = (temp->next);
            }
        }
        swap(list, temp, index );
    }
}

void swap(list* list, node* n1, node* n2)
{
    if( (n1 == (list->start)) && (n2 == (list->end)) )      //only two elements
    {
        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1; 
        list->start = n2; 
        list->end = n1; 
    }
    else if(n1 == (list->start))        //swap the first element
    {
        n2->next->previous = n1;
        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1; 
        list->start = n2;  
    }
    else if(n2 == (list->end))      //swap the last element
    {
        n1->previous->next = n2;
        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1; 
        list->end = n1;       
    }
    else        //swap general
    {
        n1->previous->next = n2;
        n2->next->previous = n1;
        n1->next = n2->next;        
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1;      
    }
}

void printList(list* list)
{
    node* temp;
    temp = list->start;
    if(temp==0)
    {
        printf("Empty List!\n");
        return;
    }
    printf("ID\tName\t\t\tSalary\n");
    printf("--------------------------------------\n");
    do
    {
        printf("%d", temp->emp->code);
        printf("\t%s", temp->emp->name);
        printf("\t\t\t%d\n\n", temp->emp->salary);
        temp = temp->next;
    } while (temp!=0);
}


char* toLower(char *name)
{
    int len = strlen(name);
    char* temp = malloc((len)*sizeof(char));

    for (int i = 0; i < len; ++i) {
        temp[i] = tolower((unsigned char)name[i]);
    }
    return temp;
}
