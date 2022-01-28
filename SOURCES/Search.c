#include<stdio.h>
#include<conio.h>
#include"..\INCLUDE\Search.h"

int linSearch(int *arr, int key, int size)
{
    int i;
    for(i=0;i<size; i++)
    {
        if(key == arr[i]) return i;
    }
    return -1;
}

int binSearch(int* arr, int key, int size)
{
    int low=0,high=(size-1),mid;
    while(low<=high)
    {
        mid = (high+low)/2;
        if( arr[mid] == key )return mid;
        else if ( arr[mid] > key )high=mid-1;
        else low=mid+1;
    }
    return -1;
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
