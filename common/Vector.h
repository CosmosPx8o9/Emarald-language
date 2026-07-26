#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
	void** pointers;
	int bottom;
	int ceiling;
	int top;
} vector;

int v_init(vector**, int, int);
int v_free(vector**);

int v_push(vector*, void*);
int v_pop(vector*, void**);
int v_back(vector*, void**);
int v_get(vector*, int, void**);

int v_size(vector*);
char v_empty(vector*);

#endif
