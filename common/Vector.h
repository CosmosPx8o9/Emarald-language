
// SPDX-License-Identifier: MIT
// Copyright (C) 2026 cosmosPx8o9
// Created 26.07.2026
// Last edited 11.08.2026

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include "Error.h"

typedef struct {
	unsigned char* bytes;
	size_t size;
	size_t ceiling;
	size_t top;
} vector;

em_error v_init(vector*, size_t);
em_error v_free(vector*);

vector* v_from(size_t);
em_error v_destroy(vector**);

em_error v_reserve(vector*, size_t);

em_error v_push(vector*, void*);
em_error v_pop(vector*, void*);
em_error v_set(vector*, void*, size_t) 
em_error v_back(vector*, void*);
em_error v_get(vector*, size_t, void*);

size_t v_top(vector*);
bool v_empty(vector*);

#endif
