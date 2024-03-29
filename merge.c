
#include "deque.h"


//Merge d1 and d2 int O(n) time
deque* merge(deque* d1, deque* d2){
	deque* d3 = malloc(sizeof(deque));
	initDeque(d3, 3);
	int lowSize = 0;
	lowSize = (d1->size > d2->size) ? d1->size : d2->size;

	int i=0, absI = 0;
	int j=0, absJ = 0;

	while (i < d1->size && j < d2->size){
		/*get abs positions*/
		absI = (i + d1->start) % d1->capacity;	
		absJ = (j + d2->start) % d2->capacity;	
	
		/*preform comparisons*/
		if (d1->arr[absI] < d2->arr[absJ]){
			/*add one, and move to next element of d1*/
			dequeAddBack(d3, d1->arr[absI]);
			i++;
		} else if (d1->arr[absI] > d2->arr[absJ]){
			/*add one, and move to next element of d2*/
			dequeAddBack(d3, d2->arr[absJ]);
			j++;
		} else {
			/*add both, and move to next element of both*/
			dequeAddBack(d3, d1->arr[absI]);
			dequeAddBack(d3, d2->arr[absJ]);
			i++;
			j++;
		}
		
	}
	/*add the rest */
	if (i < d1->size){
		for (j; j < d2->size; j++){
			absJ = (j + d2->start) % d2->capacity;	
			dequeAddBack(d3, d2->arr[absJ]);
		}
	} else if (j < d2->size){
		for (i; i < d1->size; j++){
			absI = (i + d1->start) % d1->capacity;	
			dequeAddBack(d3, d1->arr[absI]);
		}
	}
	
	return d3;
	
}	

int main(){
	deque d1;
	deque d2;

	initDeque(&d1, 2);
	initDeque(&d2, 2);

	for (int i = 0; i < 10; i+= 2){
		dequeAddBack(&d1, i+1);
	}

	for (int i = 1; i < 30; i+=1){
		dequeAddBack(&d2, i - 1);
	}
	
	dequePrint(&d1);
	dequePrint(&d2);
	deque* d3 = merge(&d1, &d2);
	dequePrint(d3);
	free(d3->arr);
	free(d3);
	free(d2.arr);
	free(d1.arr);
	
	



}
