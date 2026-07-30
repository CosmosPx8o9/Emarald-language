#include "Vector.h"
#include <stdlib.h>
#include <string.h>

bool v_empty(vector* init) {
	if (!init) return 0;
	return init->top <= 0;
}

size_t v_top(vector* init) {
	if (!init) return 25;
	return init->top;
}

int v_init(vector* init, size_t size_element) {
	if (!init) return 25;
	init->ceiling = 8;
	init->size    = size_element;
	init->top     = 0;

	init->bytes = malloc(8 * size_element);
	if (!init->bytes) return 26;
	return 0;
}

int v_free(vector* init) {
	if (!init||!init->bytes) return 25;
	free(init->bytes);
	return 0;
}

vector* v_from(size_t size_element) {
	vector* init = malloc(sizeof(vector));
	if (!init||v_init(init, size_element)) return NULL;
	return init;
}

int v_destroy(vector** init) {
	if (!init||!(*init)) return 26;

	if ((*init)->bytes) free((*init)->bytes);
	free((*init));
	*init = NULL;
	return 0;
}

int v_reserve(vector* init, int s_new) {
	if (!init||!init->bytes) return 25;
	if (s_new <= init->ceiling) return 30;
	unsigned char* temp = realloc(init->bytes, s_new * init->size);
	if (!temp) return 26;
	init->bytes = temp;
	init->ceiling  = s_new;
	return 0;
}

int v_push(vector* init, void* ptr) {
	if (!init||!init->bytes||!ptr) return 25;

	if (init->top >= init->ceiling) {
		int s_new = init->ceiling * 2;
		if (v_reserve(init, s_new)) return 26;
	}
	void* offest = init->bytes + init->top * init->size;
	memcpy(offest, ptr, init->size);
	init->top++;
	return 0;
}

int v_back(vector* init, void* resulf) {
	if (!init || !resulf) return 25;
	if (v_empty(init)) return 30;

	void* offest = init->bytes + (init->top - 1) * init->size;
	memcpy(resulf, offest, init->size);
	return 0;
}

int v_pop(vector* init, void* resulf) {
	if (!init || !resulf) return 25;
	if (v_empty(init)) return 30;

	init->top--;
	void* offest = init->bytes + init->top * init->size;
	memcpy(resulf, offest, init->size);
	return 0;
}

int v_get(vector* init, int index, void* resulf) {
	if (!init || !resulf) return 25;
	if (index >= 0 && index < init->top) {
		void* offest = init->bytes + init->top *init->size;
		memcpy(resulf, offest, init->size);
		return 0;
	}
	return 25;
}
