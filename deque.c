#include "deque.h"


void initDeque(deque* arr, int cap){
	assert(cap > 0);
	
	arr->arr = (TYPE*) malloc(sizeof(TYPE) * cap);

	assert(arr->arr != NULL);

	arr->capacity = cap;
	arr->start = 0;
	arr->size = 0;


}

void _doubleCapacityDeque(deque* arr){

	TYPE* oldData = arr->arr;
	int oldStart = arr->start;
	int oldCap = arr->capacity;
	int oldSize = arr->size;

	initDeque(arr, 2 * oldCap);

	for (int i = 0; i < oldSize; i++){
		arr->arr[i] = oldData[(oldStart) % oldCap];
		oldStart++;
	}
	

	arr->size = oldSize;


	free(oldData);
}

void dequeAddFront(deque* arr, TYPE value){
	assert(arr != NULL);

	/*check capacity*/
	if (arr->size == arr->capacity) _doubleCapacityDeque(arr);
	
	/*reduce start*/
	arr->start--;

	/*calculate wrapping if needed*/
	if (arr->start < 0) arr->start += arr->capacity;

	/*set val and increment size*/
	arr->arr[arr->start] = value;

	arr->size++;
}

void dequeAddBack(deque* arr, TYPE value){
	/*calculate the back, then set the value and increment size*/
	/*check capacity*/
	if (arr->size == arr->capacity) _doubleCapacityDeque(arr);
	
	int backIndex = (arr->start + arr->size) % arr->capacity;
	arr->arr[backIndex] = value;
	arr->size++;
}

TYPE dequeRemoveFront(deque* arr){
	/*set and increment the start*/
	TYPE val = arr->arr[arr->start];
	arr->start++;
	return val;
	
}

TYPE dequeRemoveBack(deque* arr){
	/*save the back value*/
	int backIndex = (arr->start + arr->size) % arr->capacity;
	TYPE val = arr->arr[backIndex];

	/*decrement size to treat the back as junk*/
	arr->size--;

	return val;
}

TYPE dequeFront(deque* arr){
	return arr->arr[arr->start];
}

TYPE dequeBack(deque* arr){
	int backIndex = (arr->start + arr->size) % arr->capacity;
	return arr->arr[backIndex];
}

void dequePrint(deque* arr){
	int i = 0;
	int absI = 0;
	while (i < arr->size){
		absI = (i + arr->start) % arr->capacity;	
		printf("%d, ", arr->arr[absI]);

		i++;
		
	}
	printf("\n");
}

