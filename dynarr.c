
#include "dynarr.h"

void initDynarr(dynarr* newArr, int capacity){
	assert(capacity > 0);
	
	/*init values and allocate array*/
	newArr->size = 0;
	newArr->capacity = capacity;
	newArr->arr = (TYPE*) malloc(sizeof(TYPE) * capacity);
	
	/*make sure there's enough memory*/
	assert(newArr->arr != NULL);
}

void dynarrFree(dynarr* arr){
	assert(arr != NULL);

	/*free the array and reset the dynarr's values*/
	free(arr->arr);
	arr->size = 0;
	arr->capacity = 0;
}

void _dynarrDoubleCap(dynarr* arr){
		assert(arr != NULL);
		
		/*save old values*/
		TYPE* oldArr = arr->arr;
		int oldSize = arr->size;

		/*re-init arr with new capacity*/
		initDynarr(arr, arr->capacity * 2);
		
		/*copy old elements over*/
		for (int i = 0; i < oldSize; i++){
			arr->arr[i] = oldArr[i];
		}

		/*copy size over*/
		arr->size = oldSize;

		/*delete old elements*/
		free(oldArr);
}

void dynarrAdd(dynarr* arr, TYPE value){
	assert(arr != NULL);

	/*add new value and increment size*/
	arr->arr[arr->size] = value;
	arr->size++;

	/*check for capacity overflow*/
	if (arr->size >= arr->capacity){

		/*if so, double capacity*/
		_dynarrDoubleCap(arr);
	}
}

TYPE dynarrRemove(dynarr* arr, int index){
	assert(arr != NULL);

	/*save the desired value*/
	TYPE val = arr->arr[index];

	/*starting at index, loop through the array*/
	for (int i = index; i < arr->size - 1; i++){

		/*move the next element back one*/
		arr->arr[i] = arr->arr[i+1]; // <-- note: the last value in the array is duplicated, but because size is decremented it is treated as junk
	}

	/*decrement size*/
	arr->size--;

	return val;
}

void dynarrInsert(dynarr* arr, int index, TYPE value){
	assert(arr != NULL);
	assert(index >= 0);
	assert(index < arr->size);

	arr->size++;

	/*check for capacity overflow*/
	if (arr->size >= arr->capacity){

		/*if so, double capacity*/
		_dynarrDoubleCap(arr);
	}

	for (int i = index; i < arr->size - 1; i++){

		/*move the element forward one*/
		arr->arr[i+1] = arr->arr[i]; // <-- note: the last value in the array is duplicated, but because size is decremented it is treated as junk
	}

	/*insert the element*/
	arr->arr[index] = value;
}

int binarySearch(dynarr* arr, int size, TYPE val){
	int low =0;
	int high = size;
	while (low < high){
		if(arr->arr[(high + low) /2] < val){
			low =(high + low) /2 + 1;
		} else {
			high = (high + low) /2;
		}
	}
	/*return index, or index where val can be inserted*/
	return low;
}

int search(dynarr* arr, int size, TYPE val){
	for (int i = 0; i < size; i++){
		if (arr->arr[i] == val){
			return i;
		}
	}
}

void swap(dynarr* arr, int i, int j){
	TYPE temp = arr->arr[i];
	arr->arr[i] = arr->arr[j];
	arr->arr[j] = temp;
}


void dynarrPrint(dynarr* arr){
	if (arr->size == 0){
		printf("[ <empty> ]\n");
	} else {
		printf("[");
		for (int i = 0; i < arr->size; i++){
			printf("%d ", arr->arr[i]);
		}
		printf("\b]\n");
	}
	
}

