#ifndef SEARCH_HEADER
#define SEARCH_HEADER

#include<stdio.h>
#include<conio.h>

int linSearch(int* arr, int key, int size);
int binSearch(int* arr, int key, int size);
int recSearchLin(int* arr, int key, int size, int i);
int recSearchBin(int* arr, int key, int size, int low);

#endif
