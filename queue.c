#include "dynarr.h"

void queueAdd(dynarr* arr, TYPE value){
	dynarrInsert(arr, 0, value);
}

TYPE queueRemove(dynarr* arr){

	return dynarrRemove(arr, arr->size-1);

}
