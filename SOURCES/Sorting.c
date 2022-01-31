#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"..\INCLUDE\Sorting.h"
#include"..\INCLUDE\linkedList.h"


/*
void selectionSort(list* list, int choice)
{
    int n = list->numOfNodes;
    int goSwap = 0;
    int i,j,k,pos=0;
    node* index = list->start;
    node* temp = index;
    printf("\nEntered selection sort\n");
    for(i=0; i< (n-1); i++)
    {  
        goSwap = 0;

        temp = list->start;
        pos = 0;
        while (pos < i)
        {
            temp = temp->next;
            pos++;
        }
        index = temp;       //initialize the index of the smallest elememt to the i element

        //for(j=i; j < (n-1); j++)
        while( temp != 0)
        {
            pos = 0;
            if(choice == 1)     //salary sort
            {
                printf("\nchecking for changing index");
                if( (temp != 0) && ((temp->emp->salary) > (temp->next->emp->salary)) )
                {
                    printf("\nchanged\n");
                    index = (temp->next);
                    goSwap = 1;
                }
                temp = (temp->next);
                pos++;
            }
        }
        temp = list->start;
        k = 0;
        while (k < pos)
        {
            temp = temp->next;
            k++;
        }
        if(goSwap == 1)
        {
            swap(list, temp, index );
        }
    }
}*/


void selectionSortNew(list* list, int choice)
{
    int n = list->numOfNodes;
    int i,j,goSwap,pos;
    node* index;
    node* temp;
    for( i = 0; i < (n-1); i++)
    {
        goSwap = 0;

        index = list->start;
        pos = 0;
        while (pos < i)
        {
            index = index->next;
            pos++;
        }   
        temp = index->next;

        for(j = i; j < (n-1); j++)
        {
            if(choice == salarySort)
            {
                if((index->emp->salary) > (temp->emp->salary))
                {
                    index = temp;
                    goSwap = 1;
                }
                if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            }
            else if(choice == alphabeticalSort)
            {   
                printf("\nEntered alpha sort\n");
                printf("%s\n",temp->emp->name);
                printf("%s\n",index->emp->name);
                if( strcmp(index->emp->name,temp->emp->name) > 0 )
                {
                    printf("Condition true\n");
                    index = temp;
                    goSwap = 1;
                }
                if (temp->next != NULL)
                {
                    temp = temp->next;
                } 
            }
            else
            {
                printf("\nWrong choice\n");
                getch();
                return;
            }
        }

        temp = list->start;
        pos = 0;
        while (pos < i)
        {
            temp = temp->next;
            pos++;
        }   

        if(goSwap == 1)
        {
            swapNew(list, temp, index);
        }
    }
}


void bubbleSort(list* list, int choice)
{
    int i,j=0,flag,pos=1;
    int n = list->numOfNodes;
    node* temp = list->start;
    for(i=0; i<(n-1); i++)
    {
        flag=0;
        for(j=0; j < (n-i-1); j++)
        {            
            if(choice == 1)     //salary sort
            {
                if( (temp != 0)  &&  ((temp->emp->salary) > (temp->next->emp->salary)) )
                {
                    swapNew(list, temp, (temp->next) );
                    flag=1;
                }
                else
                {
                    temp = temp->next;        
                }
            }
        }
        temp = list->start;
        if(flag==0)return;
    }  
}

void swap(list* list, node* n1, node* n2)
{
    
    node* temp;
    node* n1Next = n1->next;
    node* n1Prev = n1->previous;
    node* n2Next = n2->next;
    node* n2Prev = n2->previous;
    int n = list->numOfNodes;
    int cnt = 0;

    if(list->numOfNodes == 2)       //only two elements
    {
        list->start = n2;
        list->end = n1;

        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1;
        printSimple(list);
    }
    else if( (n1 == (list->start) ) && (n2 == (list->end)) )      //first and last element
    {
        printf("\nSwapping first and last\n");
        
        n1->next->previous = n2;
        n2->previous->next = n1;

        n2->next = n1->next;
        n1->previous = n2->previous;
 
        n2->previous = n1Prev;
        n1->next = n2Next;

        list->start = n2; 
        list->end = n1;

        printSimple(list);
    }
    else if(n1 == (list->start))        //swap the first element
    {
        printf("\nSwapping first and general\n");
        n2->next->previous = n1;
        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1; 
        list->start = n2;  
        printSimple(list);
    }
    else if(n2 == (list->end))      //swap the last element
    {
        printf("\nSwapping general and last\n");
        n1->previous->next = n2;
        n1->next = n2->next;
        n2->previous = n1->previous;
        n1->previous = n2;
        n2->next = n1; 
        list->end = n1;       
        printSimple(list);
    }
    else 
    {
        temp = n1;
        while(temp != n2)
        {
            cnt++;
            temp = temp->next;
        }
        
        n1->previous->next = n2;
        n1->next->previous = n2;
        n2->previous->next = n1;
        n2->next->previous = n1;

        if(cnt == 1)
        {
            n1->next = n2Next;
            n1->previous = n2;
            n2->next = n1;
            n2->previous = n1Prev;
        }
        else
        {
            n1->next = n2Next;
            n1->previous = n2Prev;
            n2->next = n1Next;
            n2->previous= n1Prev;
        }

        /*
        if (list->numOfNodes == 4)     //4 element swap
        {
            printf("\nSwapping 4 elemets\n");
            getch();
        
            n1->previous->next = n2;
            n2->next->previous = n1;
            n2->previous = n1Prev;
            n2->next = n1;
            n1->next = n2Next;
            n1->previous = n2;
            printSimple(list);

        }
        else if (list->numOfNodes == 5)       //5 element swap
        {
            printf("\nSwapping 5 elemets\n");
            getch();

            n1->previous->next = n2;
            n1->next->previous = n2;
            n2->next->previous = n1;
            n2->previous->next = n1;

            n1->next = n2Next;
            n1->previous = n2Prev;
            n2->next = n1Next;
            n2->previous = n1Prev;


            printSimple(list);  
        }
        else        //general swap 6 elements and above
        {
            printf("\nSwapping general\n");
            getch();
            n1->previous->next = n2;
            n1->next->previous = n2;
            n2->next->previous = n1;
            n2->previous->next = n1;
            n1->next = n2Next;
            n1->previous = n2Prev;
            n2->next = n1Next;
            n2->previous = n1Prev;
            printSimple(list);
        }
        */
    }
    printf("\ndone swapping\n");
}

void swapNew(list* list, node* n1, node* n2)
{
    int temp1,temp2;
    char temp3[25];

    printf("\nstr1->%s\n",n1->emp->name);
    printf("\nstr2->%s\n",n2->emp->name);

    temp1 = n1->emp->salary;
    temp2 = n1->emp->code;
    strcpy(temp3, n1->emp->name);

    printf("\nstr1->%s\n",temp3);

    n1->emp->salary = n2->emp->salary;
    n1->emp->code = n2->emp->code;
    strcpy(n1->emp->name, n2->emp->name);

    n2->emp->salary = temp1;
    n2->emp->code = temp2;
    strcpy(n2->emp->name,temp3);

    printf("\n%s\n",n1->emp->name);
    printf("\n%s\n",n2->emp->name);

    printSimple(list);
}



/*
void mergeSort(int *A, int n)
{
    int mid,i,*L,*R;
    if(n<2)return;
    mid=n/2;
    L=(int*)malloc(mid*sizeof(int));
    R=(int*)malloc((n-mid)*sizeof(int));
    for(i=0;i<mid;i++)L[i]=A[i];
    for(i=mid;i<n;i++)R[i-mid]=A[i];
    mergeSort(L,mid);
    mergeSort(R,n-mid);
    merge(A,L,mid,R,(n-mid));
    free(L);
    free(R);
}

void merge(int*A, int*L, int leftCount, int*R, int rightCount)
{
    int i,j,k;
    i=0;j=0;k=0;
    while( i<leftCount && j<rightCount )
    {
        if(L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i<leftCount) A[k++] = L[i++];
    while(j<rightCount) A[k++] = R[j++];
}
*/
