#include "Vector.h"
#include <stdlib.h>
#include <string.h>

bool v_empty(vector* init) {
	if (!init) return 0;
	return init->top <= 0;
}

size_t v_top(vector* init) {
	if (!init) return 0;
	return init->top;
}

em_error v_init(vector* init, size_t size_element) {
	if (!init) return ERR_ARG;
	init->ceiling = 8;
	init->size    = size_element;
	init->top     = 0;

	init->bytes = malloc(8 * size_element);
	if (!init->bytes) return ERR_MEM;
	return EM_OK;
}

em_error v_free(vector* init) {
	if (!init||!init->bytes) return ERR_ARG;
	free(init->bytes);
	return EM_OK;
}

vector* v_from(size_t size_element) {
	vector* init = malloc(sizeof(vector));
	if (!init||v_init(init, size_element)) return NULL;
	return init;
}

em_error v_destroy(vector** init) {
	if (!init||!(*init)) return ERR_ARG;

	if ((*init)->bytes) free((*init)->bytes);
	free((*init));
	*init = NULL;
	return EM_OK;
}

em_error v_reserve(vector* init, size_t s_new) {
	if (!init||!init->bytes) return ERR_ARG;
	if (s_new <= init->ceiling) return ERR_FUN;
	unsigned char* temp = realloc(init->bytes, s_new * init->size);
	if (!temp) return ERR_MEM;
	init->bytes = temp;
	init->ceiling  = s_new;
	return EM_OK;
}

em_error v_push(vector* init, void* ptr) {
	if (!init||!init->bytes||!ptr) return ERR_ARG;

	if (init->top >= init->ceiling) {
		size_t s_new = init->ceiling * 2;
		if (v_reserve(init, s_new)) return ERR_MEM;
	}
	void* offest = init->bytes + init->top * init->size;
	memcpy(offest, ptr, init->size);
	init->top++;
	return EM_OK;
}

em_error v_back(vector* init, void* resulf) {
	if (!init || !resulf) return ERR_ARG;
	if (v_empty(init)) return ERR_FUN;

	void* offest = init->bytes + (init->top - 1) * init->size;
	memcpy(resulf, offest, init->size);
	return EM_OK;
}

em_error v_set(vector* init, void* ptr, size_t index) {
	if (!init || !resulf) return ERR_ARG;
	if (index >= init->top) return ERR_FUN;
	void* offest = init->bytes + init->top * init->size;
	memcpy(offest, ptr, init->size);
	return EM_OK;
}

em_error v_pop(vector* init, void* resulf) {
	if (!init || !resulf) return ERR_ARG;
	if (v_empty(init)) return ERR_FUN;

	init->top--;
	void* offest = init->bytes + init->top * init->size;
	memcpy(resulf, offest, init->size);
	return EM_OK;
}

em_error v_get(vector* init, size_t index, void* resulf) {
	if (!init || !resulf) return ERR_ARG;
	if (index >= 0 && index < init->top) {
		void* offest = init->bytes + init->top *init->size;
		memcpy(resulf, offest, init->size);
		return EM_OK;
	}
	return ERR_ARG;
}
