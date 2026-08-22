

#include "String.h"
#include <stdlib.h>

#define NOT_INIT !init.vec||!init.vec->bytes

size_t length_get(const char* text) {
	size_t index = 0;
	for (; text[index] != '\0'; index++) {}
	return index;
}

bool str_empty(string init) {
	return v_empty(init.vec);
}

size_t str_len(string init) {
	return v_top(init.vec);
}

const char* str_cstr(string init) {
	if (NOT_INIT) return NULL;
	return (const char*)init.vec->bytes;
}

em_error str_clear(string init) {
	if (NOT_INIT) return ERR_ARG;
	init.vec->top = 0;
	init.vec->bytes[init.vec->top] = '\0';
	return EM_OK;
}

em_error str_reserve(string init, size_t new_size) {
	return v_reserve(init.vec, new_size);
}

em_error str_add(string init, char letter) {
	if (NOT_INIT) return ERR_ARG;
	em_error code;
	if ((code = v_push(init.vec, &letter))) return code;
	init.vec->bytes[init.vec->top] = '\0';
	return EM_OK;
}

em_error str_append(string init, const char* text) {
	if (NOT_INIT||!text) return ERR_ARG;
	size_t len = length_get(text);
	for (int i = 0; i < len; ++i) {
		em_error code;
		if ((code = v_push(init.vec, (void*)&text[i]))) return code;
	}
	init.vec->bytes[init.vec->top] = '\0';
	return EM_OK;
}

em_error str_init(string init, const char* text) {
	em_error code;
	size_t len = length_get(text);
	if ((code = v_init(init.vec, sizeof(char)))) return code;
	if ((code = v_reserve(init.vec, init.vec->ceiling * 2))) return code;

	return str_append(init, text);
}

em_error str_free(string init) {
	em_error code;
	code = v_free(init.vec);
	init.vec = NULL;
	return code;
}
