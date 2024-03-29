#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"..\INCLUDE\linkedList.h"


node* createNode(emp* emp1)
{
    node* temp;
    temp = (node*) malloc(sizeof(node));
    temp->emp = emp1;
    temp->next = temp->previous = 0;
    return temp;
}

void append(list* list, emp* emp)
{
    node* temp;
    temp=createNode(emp);                      //adding the employee as data to node
    if(list->start==0)      //list is empty
    {
        list->start = list->end = temp;
    }
    else        //list have elements
    {
        list->end->next = temp;
        temp->previous = list->end;
        list->end = temp;
    }
    (list->numOfNodes)++;
    printf("#nodes: %d",list->numOfNodes);
    (temp->id) = list->numOfNodes;
    printf("#node ID: %d",temp->id);
    return;
}

node* search(list* list, int key)
{
    node* temp = list->start;
    while( (temp) && ((temp->emp->code) != key) )
    {
        temp = temp->next;
    }
    return temp;
}

int delete(list* list, int key)
{
    node* temp = list->start;
    if( temp == 0)       //empty list
    {
        return 0;
    }

    temp = search(list,key);

    if( temp == 0)       //element not found 
    {
        return 0;
    }
    else
    {
        if( (temp == (list->start)) && (temp == (list->end)) )        //delete the whole list. only 1 element
        {
            list->start = list->end = 0;
            free(temp);
        }
        else if( temp == (list->start) )     //delete first element
        {
            list->start = temp->next;
            temp->next->previous = 0;
            free(temp);
        }
        else if( temp == (list->end) )      //delete last element
        {
            list->end = temp->previous;
            temp->previous->next = 0;
            free(temp);
        }
        else        //delete element in the middle
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            free(temp);
        }
        return 1;
    }
}

int freeList(list* list)
{
    node* temp = list->start;
    if (temp == 0)
    {
        return 0;
    }
    while(temp)
    {
        list->start = temp->next;
        free(temp);
        temp = list->start;
    }
    return 1;
}

void printList(list* list)
{
    node* temp;
    temp = list->start;
    if(temp == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    printf("ID\tName\t\t\tSalary\n");
    printf("--------------------------------------\n");
    do
    {
        //printf("temp(%p) -> %p", (temp), (temp->next) );
        printf("\n%d", temp->emp->code);
        printf("\t%s", temp->emp->name);
        printf("\t\t\t%d\n\n", temp->emp->salary);
        temp = temp->next;
    } while (temp != NULL);
}

void printSimple(list* list)
{
    node* temp;
    temp = list->start;
    printf("\n");
    do
    {
        printf(" %d -> ", temp->emp->salary);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}
