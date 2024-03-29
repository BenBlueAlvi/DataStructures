#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <assert.h>

#define TYPE int


struct deque{
	TYPE* arr;
	int capacity;
	int size;
	int start;

};

/*backIndex = (start + size) % capacity*/

typedef struct deque deque;

void initDeque(deque* arr, int cap);
void dequeAddFront(deque* arr, TYPE value);
void dequeAddBack(deque* arr, TYPE value);
TYPE dequeRemoveFront(deque* arr);
TYPE dequeRemoveBack(deque* arr);
TYPE dequeFront(deque* arr);
TYPE dequeBack(deque* arr);
void dequePrint(deque* arr);

#endif
