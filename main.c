
#include "dynarr.h"
#include "bag.h"
#include "deque.h"
#include "hashTable.h"
#include "queue.h"
#include "set.h"
#include "stack.h"
#include "heap.h"
#include "matrix.h"


void dynarrTest(){
	printf("---DYNNARR TEST--- \n");
	dynarr arr;
	initDynarr(&arr, 2);

	for (int i = 0; i < 10; i++){
		dynarrAdd(&arr, i);
	}
	dynarrPrint(&arr);
	printf("Removed 5 \n");
	dynarrRemove(&arr, 5);
	dynarrPrint(&arr);
}

void bagTest(){
	printf("---BAG TEST--- \n");
	dynarr arr;
	initDynarr(&arr, 2);
	for (int i = 0; i < 10; i++){
		bagAdd(&arr, i);
		
	}
	dynarrPrint(&arr);
	printf("\n Contains 5: %d\n", bagContains(&arr, 5));
	bagRemove(&arr, 5);
	printf("After remove: %d\n", bagContains(&arr, 5));
	dynarrPrint(&arr);
}


void heapTest(){
	printf("---HEAP TEST--- \n");
	dynarr arr;
	initDynarr(&arr, 2);
	heapAdd(&arr, 5);
	heapAdd(&arr, 2);
	heapAdd(&arr, 1);
	heapAdd(&arr, 10);

	dynarrPrint(&arr);
 	int max = arr.size;
	for (int i = 0; i < max; i++){
		TYPE val = heapPop(&arr);
	
	
		printf("%d: %d\n", i, val);
	}
	dynarrPrint(&arr);
		
}

void matrixTest(){
	printf("---Matrix TEST--- \n");
	matrix m;
	mInit(&m, 5, 5);
	mFill(&m, 5, 5, 1);
	mPrint(&m);
}

int main(){
	bagTest();
	dynarrTest();
	heapTest();
	matrixTest();
}
