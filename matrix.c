#include "matrix.h"


void mInit(matrix* m, int wCap, int hCap){
	
	m->data = (TYPE**) malloc(sizeof(TYPE*) * wCap);
	for (int i = 0; i < wCap; i++){
		m->data[i] = (TYPE*) malloc(sizeof(TYPE) * hCap);
	}
	m->h = 0;
	m->w = 0;
	m->wCap = wCap;
	m->hCap = hCap;
}

void _mReCap(matrix* m, int newW, int newH){

	TYPE** oldArr = m->data;
	int oldW = m->w;
	int oldH = m->h;

	mInit(m, newW, newH);

	for (int i = 0; i < oldW; i++){
		for (int j = 0; j < oldH; j++){
			m->data[i][j] = oldArr[i][j];
		}
	}
	m->h = oldH;
	m->w = oldW;
}

void mAddCol(matrix* m, dynarr* a){
	assert(m->h == a->size);
	if (m->w > m->wCap){
		_mReCap(m, m->wCap*2, m->hCap);
	}
	m->w++;
	for (int i = 0; i < m->h; i++){
		m->data[m->w-1][i] = a->arr[i];
	}
}

void mAddRow(matrix* m, dynarr* a){
	assert(m->w == a->size);
	if (m->h > m->hCap){
		_mReCap(m, m->wCap, m->hCap*2);
	}
	m->h++;
	for (int i = 0; i < m->w; i++){
		m->data[i][m->h-1] = a->arr[i];
	}
}

void mResize(matrix* m, int w, int h){
	if (w > m->wCap && h > m->hCap){
		_mReCap(m, w, h);
	} else if (h > m->hCap){
		_mReCap(m, m->wCap, h);
	} else {
		_mReCap(m, w, m->hCap);
	}
	m->w = w;
	m->h = h;
}

void mFill(matrix* m, int w, int h, TYPE v){
	mResize(m, w, h);

	for (int i = 0; i < m->w; i++){
		for (int j = 0; j < m->h; j++){
			m->data[i][j] = v;
		}
	}
	
}

void mFillCol(matrix* m, int w, TYPE v){
	
	for (int j = 0; j < m->h; j++){
		m->data[w][j] = v;
	}
}

void mFillRow(matrix* m, int h, TYPE v){
	
	for (int j = 0; j < m->h; j++){
		m->data[j][h] = v;
	}
}

void mPlus(matrix* m, TYPE v){
	for (int i = 0; i < m->w; i++){
		for (int j = 0; j < m->h; j++){
			m->data[i][j] -= v;
		}
	}
}

void mMinus(matrix* m, TYPE v){
	for (int i = 0; i < m->w; i++){
		for (int j = 0; j < m->h; j++){
			m->data[i][j] -= v;
		}
	}
}

void mSet(matrix* m, int w, int h, TYPE v){
	m->data[w][h] = v;
}

TYPE mGet(matrix* m, int w, int h){
	return m->data[w][h];
}

void mPrint(matrix* m){
	for (int i = 0; i < m->h; i++){
		printf("[ ");
		for (int j = 0; j < m->w; j++){
			printf("%d ",m->data[j][i]);
		}
		printf("]\n");
	}
}
