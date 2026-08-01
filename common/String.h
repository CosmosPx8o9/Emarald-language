#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdbool.h>
#include "Vector.h"

typedef struct {
	vector* vec;
} string;

size_t str_len(string);
bool str_empty(string);


const char* str_cstr(string);
em_error str_clear(string);
em_error str_reserve(string, size_t);

em_error str_init(string, const char*);
em_error str_free(string);

em_error str_append(string, const char*);
em_error str_add(string, char);

#endif
