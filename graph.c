#include "matrix.h"

void graphInit(matrix* m, int verts){
	mInit(m, verts, verts);
	mFill(m, verts, verts, 0);
}

void graphAddVert(matrix* m){
	mResize(m, m->w + 1, m->h+1);
	mFillRow(m, m->h - 1, 0);
	mFillCol(m, m->w - 1, 0);
}

/*adds an edge from v1 to v2*/
void graphAddDirEdge(matrix* m, int v1, int v2, int wieght){
	mSet(m, v1, v2, wieght);
}

void graphAddUnDirEdge(matrix* m, int v1, int v2, int wieght){
	mSet(m, v1, v2, wieght);
	mSet(m, v2, v1, wieght);
}

/*replaces all weights with 1*/
void toBinary(matrix* m){
	for (int i = 0; i < m->w; i++){
		for (int j = 0; j < m->h; j++){
			if (m->data[i][j]){
				m->data[i][j] = 1;
			}
		}
	}
}

/*O(n^3)*/
void toReachability(matrix* m){
	for (int i = 0; i < m->w; i++){
		for (int j = 0; j < m->h; j++){
			if (m->data[i][j]){
				for (int k = 0; k < m->h; k++){
					m->data[i][j] |= m->data[i][k] & m->data[k][j];
				}
			}
		}
	}
}

int _allVisited(int* visit, int size){
	for (int i = 0; i < size; i++){
		if (!visit[i]){
			return 0;
		}
	}
	return 1;
}

int _findMin(int* visted, TYPE* dist, size){
	int low = 10000
	for (int i = 0; i < size; i++){
		if (!visted[i] && dist[i] < low){
			low = dist[i];
		}
			
	}
}	

int* Dijkstras(matrix* m, int start){
	TYPE dist[m->w];
	int visited[m->w];
	int prev[m->w];
	
	/*init*/
	for (int i = 0; i < m->w; i++){
		visited[i] = 0;
		dist[i] = m->data[source][i] ?  m->data[source][i] : 10000; //set to the value if it exists, else inf
	}

	while(!_allVisited(visited, m->w)){
		int min = _findMin(visited, dist, m->w); /*get smallest neighbor*/
		visited[min] = 1; /*visit it*/
		for (int i = 0; i < size; i++){ /*update neighbors*/
			if (!visited[i] && m->data[min][i]){ /*if it isn't visted and exists*/
				TYPE update = dist[min] + m->data[min][i]; /*calculate total dist*/
				if (update < dist[i]){ /*if the new is less than what it was*/
					dist[i] = update; /*update it*/
					previous[i] = min; /*add to prev*/
				}
			}
		}
	}


	return prev
}
