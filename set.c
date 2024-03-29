#include "dynarr.h"


void setAdd(dynarr* arr, TYPE value){
	/*check if the value is already in the set*/
	for (int i = 0; i < arr->size; i++){
		/*if so, return*/
		if (arr->arr[i] == value){
			return;
		}
	}
	
	/*otherwise add the value*/
	dynarrAdd(arr, value);
}

TYPE setRemove(dynarr* arr, TYPE value){
	/*find the value in the array*/
	for (int i = 0; i < arr->size; i++){
		if (arr->arr[i] == value){
			return dynarrRemove(arr, i);
		}
	}
	
}

int setContains(dynarr* arr, TYPE value){
	for (int i = 0; i < arr->size; i++){
		if (arr->arr[i] == value){
			return 1;
		}
	}
	return 0;
}

/*adds set2 to set1*/
void setUnion(dynarr* set1, dynarr* set2){
	for (int i = 0; i < set2->size; i++){
		setAdd(set1, set2->arr[i]);
	}
}

/*replaces set1*/
void setIntersection(dynarr* set1, dynarr* set2){
	for (int i = 0; i < set1->size; i++){
		if (!setContains(set2, set1->arr[i])){
			setRemove(set1, set1->arr[i]);
		} 
	}
}

/*replaces set1*/
void setDifference(dynarr* set1, dynarr* set2){
	for (int i = 0; i < set1->size; i++){
		if (setContains(set2, set1->arr[i])){
			setRemove(set1, set1->arr[i]);
		} 
	}
}
