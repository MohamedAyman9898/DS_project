#ifndef SEARCH_HEADER
#define SEARCH_HEADER

#include<stdio.h>
#include<conio.h>
#include"..\INCLUDE\linkedList.h"

int linSearch(list* list, int key);
int binSearch(list* list, int key);
int recSearchLin(int* arr, int key, int size, int i);
int recSearchBin(int* arr, int key, int size, int low);

#endif
