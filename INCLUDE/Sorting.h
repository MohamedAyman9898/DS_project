#ifndef SORTING_HEADER
#define SORTING_HEADER

void selectionSort(int *arr, int size);
void bubleSort(int *arr, int size);
void selectionSortRec(int *arr, int size, int j, int i, int index);
void mergeSort(int *arr, int n);
void merge(int*A, int*L, int leftCount, int *R, int rightCount);
void swap(int *, int *);
void printArr(int* arr, int n);

#endif
