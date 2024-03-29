#ifndef QUEUE_H
#define QUEUE_H

#include "dynarr.h"

void queueAdd(dynarr* arr, TYPE value);

TYPE queueRemove(dynarr* arr);

#endif
