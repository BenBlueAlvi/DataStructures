#include "tree.h"

/*
		 A				
		/ \
	   B   C
	  / \ / \
	 D  E F  G



	[A, B, C, D, E, F, G]

	First Child:
		2 * index + 1
	Second Child:
		2 * index + 2



*/


/*use node = 0 and child = -1 for root*/
/*for just node, use child = -1*/
void treeAddChild(dynarr* arr, int node, int child, TYPE value){
	/*check for if tree contains vals*/
	if (arr->size <= node * 2 + 1 + child){
		/*add in placeholder vals*/
		for (int i = 0; i < node * 2 + 1 + child - (arr->size-1); i++){
			printf("fill \n");
			dynarrAdd(arr, 0);
		}
	}

	/*set the value*/
	if (arr->size == 0){
		dynarrAdd(arr, value);
	} else {
		arr->arr[node * 2 + child + 1] = value;
	}
	
}

void treeSet(dynarr* arr, int node, TYPE value){
	treeAddChild(arr, node, -1, value);
}

TYPE treeGetChild(dynarr* arr, int node, int child){
	return arr->arr[node * 2 + child + 1];
}

void _halfPrint(dynarr* arr, int size, int n){
	if (size == 0){
		return;
	} else {
		size/=2;
		printf("size: %d\n", size);
		int i = 0;
		for (i = 0; i < size; i++){
			printf(" ");
		}
		printf("%d", arr->arr[n]);
		for (i = 0; i < size; i++){
			printf(" ");
		}
		printf("\n");
		++n;
		_halfPrint(arr, size, n);
	}
}

void treePrint(dynarr* arr){
	int maxSize = arr->size;
	int layers = -1;
	while (maxSize != 0){
		layers++;
		
		maxSize -= pow(2, layers);
	}
	layers++;
	printf("layers: %d\n", layers);

	maxSize = pow(2, layers-1);
	printf("maxSize: %d\n", maxSize);
	_halfPrint(arr, maxSize, 0);
}


