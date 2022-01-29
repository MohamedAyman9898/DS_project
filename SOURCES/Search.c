#include<stdio.h>
#include<conio.h>
#include"..\INCLUDE\Search.h"

int linSearch(list* list, int key)
{
    node* temp = list->start;
    while( (temp) && ((temp->emp->code) != key) )
    {
        temp = temp->next;
    }
    return temp;
}

int binSearch(list* list, int key)
{
    int low=1,high=(list->numOfNodes),mid;
    node* temp = list->start;
    int pos = 1;
    while(low<=high)
    {
        mid = (high+low)/2;
        while(pos != mid)
        {
            temp = temp->next;
            pos++;
        }
        if( (temp->emp->code) == key )
        {
            return temp;
        }
        else if ( (temp->emp->code) > key )
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return 0;
}

int recSearchLin(int *arr, int key, int size, int i)
{
    if( i == size)return -1;
    if(arr[i] == (key) )return i;
    else return recSearchLin(arr, key, size, i+1);
}

int recSearchBin(int* arr, int key, int high, int low)
{
    int mid = (high+low)/2;
    if (low > high)return -1;
    if ( arr[mid] == key )return mid;
    else if (arr[mid] > key ) return recSearchBin(arr, key, mid-1, low);
    else return recSearchBin(arr, key, high, mid+1);
}
