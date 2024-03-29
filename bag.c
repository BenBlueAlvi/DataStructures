#include "bag.h"

void bagAdd(dynarr* bag, TYPE value){
	dynarrAdd(bag, value);
}

TYPE bagRemove(dynarr* bag, TYPE value){
	for (int i = 0; i < bag->size; i++){
		if (bag->arr[i] == value){
			return dynarrRemove(bag, i);
		}
	}
	
}

int bagContains(dynarr* bag, TYPE value){
	for (int i = 0; i < bag->size; i++){
		if (bag->arr[i] == value){
			return 1;
		}
	}
	return 0;
}
