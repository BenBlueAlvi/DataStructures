#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "dynarr.h"

void hashTablePut(dynarr* arr, TYPE key, TYPE value);
TYPE hashTableGet(dynarr* arr, TYPE key);

#endif
