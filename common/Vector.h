#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
	unsigned char* bytes;
	size_t size;
	size_t ceiling;
	size_t top;
} vector;

int v_init(vector*, size_t);
int v_free(vector*);

vector* v_from(size_t);
int v_destroy(vector**);

int v_reserve(vector*, int);

int v_push(vector*, void*);
int v_pop(vector*, void*);
int v_back(vector*, void*);
int v_get(vector*, int, void*);

size_t v_top(vector*);
bool v_empty(vector*);

#endif
