#ifndef SET_H
#define SET_H

#include "dynarr.h"

void setAdd(dynarr* arr, TYPE value);
TYPE setRemove(dynarr* arr, TYPE value);
int setContains(dynarr* arr, TYPE value);

void setUnion(dynarr* set1, dynarr* set2);
void setIntersection(dynarr* set1, dynarr* set2);
void setDifference(dynarr* set1, dynarr* set2);

#endif
