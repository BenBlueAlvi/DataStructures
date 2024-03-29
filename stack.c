#include "stack.h"

void initStack(dynarr* stack, int capacity){
	initDynarr(stack, capacity);

}

void stackPush(dynarr* stack, TYPE value){
	dynarrAdd(stack, value);
}

TYPE stackPop(dynarr* stack){

	return dynarrRemove(stack, stack->size-1);
}

TYPE stackTop(dynarr* stack){
	
	return stack->arr[stack->size-1];
}
