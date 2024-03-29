#ifndef TREE_H
#define TREE_H

#include <math.h>

#include "dynarr.h"

void treeAddChild(dynarr* arr, int node, int child, TYPE value);
void treeSet(dynarr* arr, int node, TYPE value);
TYPE treeGetChild(dynarr* arr, int node, int child);
void treePrint(dynarr*);

#endif
