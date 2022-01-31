#ifndef SORTING_HEADER
#define SORTING_HEADER

#include"..\INCLUDE\linkedList.h"
#include<string.h>
#include<ctype.h>

#define salarySort 1
#define alphabeticalSort    2

void bubbleSort(list* list, int choice);
void swap(list*, node *, node *);
void selectionSort(list* list, int choice);
void selectionSortNew(list* list, int choice);
void swapNew(list* list, node* n1, node* n2);

/*
void selectionSortRec(int *arr, int size, int j, int i, int index);
void mergeSort(int *arr, int n);
void merge(int*A, int*L, int leftCount, int *R, int rightCount);
void printArr(int* arr, int n);
*/
#endif
