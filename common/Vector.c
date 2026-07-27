#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>

char v_empty(vector* init) {
	if (!init) return 0;
	return init->top == init->bottom;
}

int v_size(vector* init) {
	if (!init) return 25;
	return init->top;
}

int v_init(vector** target, int botm, int size) {
	if (!target) return 25;

	vector* init = malloc(sizeof(vector));
	if (!init) return 26;

	init->pointers = malloc(size * sizeof(void*));
	if (!init->pointers) { free(init); return 26;}

	init->ceiling = size;
	init->bottom  = botm;
	init->top     = botm;

	*target = init;
	return 0;
}

int v_free(vector** init) {
	if (!init || !(*init)) return 25;
	if ((*init)->pointers) free((*init)->pointers);
	free(*init);
	*init = NULL;
	return 0;
}

int v_push(vector* init, void* ptr) {
	if (!init) return 25;

	if (init->top + 1 > init->ceiling) {
		void** temp;
		printf("Realloc inded %d\n", init->top);
		int s_new = init->ceiling * 2;
		temp = realloc(init->pointers, s_new *sizeof(void*));
		if (!temp) return 26;

		init->pointers = temp;
		init->ceiling = s_new;
	}

	printf("Write to %d\n", init->top);
	init->pointers[init->top] = ptr;
	init->top++;
	return 0;
}

int v_back(vector* init, void** resulf) {
	if (!init || !resulf) return 25;
	if (v_empty(init)) return 30;

	*resulf = init->pointers[init->top - 1];
	return 0;
}

int v_pop(vector* init, void** resulf) {
	if (!init || !resulf) return 25;
	if (v_empty(init)) return 30;

	init->top--;
	*resulf = init->pointers[init->top];
	return 0;
}

int v_get(vector* init, int index, void** resulf) {
	if (!init || !resulf) return 25;
	if (index > init->bottom && index < init->top) {
		*resulf = init->pointers[index];
		return 0;
	}
	return 25;
}
