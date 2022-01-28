#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"..\INCLUDE\Sorting.h"

void selectionSortRec(int *arr, int n, int j, int i,int index)
{
    if (i < n-1)
    {
        if (j<n)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
            selectionSortRec(arr, n, j+1, i, index);
            return;  

        }
        swap(&arr[i],&arr[index]);
        selectionSortRec(arr, n, i+2, i+1,i+1);
    }
}

void selectionSort(int *arr, int n)
{
    int i,j,index;
    for(i=0; i<n; i++)
    {
        index=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[index] > arr[j])
            {
                index=j;
            }
        }
        swap(&arr[i],&arr[index]);
    }
}

void bubleSort(int *arr, int n)
{
    int i,j,flag;
    for(i=0; i<n; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)return;
    }  
}

void swap(int *n1, int *n2)
{
    int temp;
    temp = (*n1);
    (*n1) = (*n2);
    (*n2) = temp;
}

void printArr(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("|%d| ",arr[i]);
    }
}

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