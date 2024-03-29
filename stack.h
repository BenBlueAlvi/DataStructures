#ifndef STACK_H
#define STACK_H

#include "dynarr.h"

void initStack(struct dynarr* stack, int capacity);
void stackPush(struct dynarr* stack, TYPE value);
TYPE stackPop(struct dynarr* stack);
TYPE stackTop(struct dynarr* stack);

#endif
