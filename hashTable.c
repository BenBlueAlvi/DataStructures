#include "hashTable.h"

void hashTablePut(dynarr* arr, TYPE key, TYPE value){
	/*check to see if the key already exists*/
	for (int i = 0; i < arr->size - 1; i += 2){
		/*if so, update the value*/
		if (arr->arr[i] == key){
			arr->arr[i+1] = value;
			return;
		}
	}
	/*otherwise add the values*/
	dynarrAdd(arr, key);
	dynarrAdd(arr, value);
	
	
}

TYPE hashTableGet(dynarr* arr, TYPE key){
	/*search for key*/
	for (int i = 0; i < arr->size - 1; i += 2){
		/*return value when found*/
		if (arr->arr[i] == key){
			return arr->arr[i+1];
		}
	}
	
}
