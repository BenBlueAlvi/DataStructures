#ifndef HEAP_H
#define HEAP_H
#include "dynarr.h"


void heapBuild(dynarr* heap);
void heapAdd(dynarr* heap, TYPE value);
void heapRemove(dynarr* heap, TYPE value);
void heapSort(dynarr* heap);
TYPE heapPop(dynarr* heap);

#endif
