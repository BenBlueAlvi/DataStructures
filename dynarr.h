#ifndef DYNARR_H
#define DYNARR_H

#include <stdlib.h>
#include <assert.h>

#define TYPE int

struct dynarr{
	int size;
	int capacity;
	TYPE* arr;

};
typedef struct dynarr dynarr;

void initDynarr(dynarr* newArr, int capacity);

void dynarrFree(dynarr* arr);

void dynarrAdd(dynarr* arr, TYPE value);

void _dynarrDoubleCap(dynarr* arr);

TYPE dynarrRemove(dynarr* arr, int index);

void dynarrInsert(dynarr* arr, int index, TYPE value);

void dynarrPrint(dynarr* arr);

int search(dynarr* arr, int size, TYPE val);

void swap(dynarr* arr, int i, int j);



#endif
