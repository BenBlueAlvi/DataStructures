#include "heap.h"
#include <math.h>

void _heapify(dynarr* heap, int startIdx, int max){
	assert(heap);
	assert(startIdx < heap->size);
	int parent = floor((startIdx - 1)/2);
	int left = startIdx * 2 + 1;
	int right = startIdx * 2 + 2;

	
	if (max > right && heap->arr[startIdx] > heap->arr[right]){ /*2 children*/
		/*swap*/
		int idx = 0;
		if (heap->arr[left] < heap->arr[right]){
			idx = left;
		} else {
			idx = right;
		}
		swap(heap, startIdx, idx);
		_heapify(heap, idx, max);
	} 
		
	else if (max> left && heap->arr[startIdx] > heap->arr[left]){ /*down left child*/
		/*swap*/
		swap(heap, startIdx, left);
		_heapify(heap, left, max);
		
	}
	
	return;
	
}

void heapBuild(dynarr* heap){
	int max = heap->size/2 -1;
	for (int i = 0; i < max; i++){
		_heapify(heap, i, heap->size);
	}

}

void heapAdd(dynarr* heap, TYPE value){
	assert(heap);
	int newIdx = heap->size;
	dynarrAdd(heap, value);
	
	int pos = heap->size-1;
	int parent = (pos - 1)/2;
	/*up*/
	while (pos > 0 && heap->arr[pos] < heap->arr[parent]){
		
		swap(heap, parent, pos);
		pos = parent;
		parent = (pos - 1)/2;
		
	}
	
}

void heapRemove(dynarr* heap, TYPE value){
	int idx = search(heap, heap->size, value);
	heap->arr[idx] = heap->arr[heap->size-1];
	
	dynarrRemove(heap, heap->size-1);
	_heapify(heap, idx, heap->size);
}

TYPE heapPop(dynarr* heap){
	TYPE val = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size-1];
	dynarrRemove(heap, heap->size-1);
	if (heap->size > 0) _heapify(heap, 0, heap->size);
	return val;
}

void heapSort(dynarr* heap){
	for (int i = heap->size-1; i >=0; i--){
		TYPE temp = heap->arr[i];
		heap->arr[i] = heap->arr[0];
		heap->arr[0] = temp;
		_heapify(heap, 0, i);
	}
	
}
