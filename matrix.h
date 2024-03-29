#ifndef MATRIX_H
#define MATRIX_H

#include "dynarr.h"

typedef struct matrix{
	int wCap;
	int hCap;
	int w;
	int h;
	TYPE** data;
	

} matrix;

void mInit(matrix* m, int wCap, int hCap);

void mAddCol(matrix* m, dynarr* a);
void mAddRow(matrix* m, dynarr* a);
void mResize(matrix* m, int w, int h);
void mFill(matrix* m, int w, int h, TYPE v);
void mSet(matrix* m, int w, int h, TYPE v);
TYPE mGet(matrix* m, int w, int h);
void mPrint(matrix* m);
#endif
