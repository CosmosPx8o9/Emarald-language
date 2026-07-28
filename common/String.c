#include "String.h"
#include <stdio.h>
#include <stdlib.h>

size_t get_len(const char* str) {
	if (!str) return 0;
	size_t index = 0;
	for (; str[index] != '\0'; ++index) {}
	return index;
}

size_t str_top(string* init) {
	if (!init) return 0;
	return init->top;
}

size_t str_len(string* init) {
	if (!init) return 0;
	return init->length;
}

bool str_empty(string* init) {
	if (!init) return false;
	return init->top == 0;
}

const char* str_cstr(string* init) {
	if (!init||!init->chars) return NULL;
	return init->chars;
}

int str_clear(string* init) {
	if (!init||!init->chars) return 25;
	init->top = 0;
	init->chars[init->top] = '\0';
	return 0;
}

int str_reserve(string* init, size_t new_size) {
	if (!init||!init->chars) return 25;
	if (new_size <= init->length) return 30;

	char* temp = realloc(init->chars, new_size * sizeof(char));
	if (!temp) return 26;

	init->chars = temp;
	init->length = new_size;
	return 0;
}

int str_init(string* init, const char* str) {
	if (!init || !str) return 25;

	init->start = 0;
	init->top = get_len(str);
	init->length= init->top * 2;
	init->chars = malloc(init->length * sizeof(char));
	if (!init->chars) return 26;

	for (size_t i = 0; i < init->top; ++i) {
		init->chars[i] = str[i];
	}
	init->chars[init->top] = '\0';
	return 0;
}

int str_free(string* init) {
	if (!init || !init->chars) return 25;
	free(init->chars);
	return 0;
}

int str_append(string* init, const char* str) {
	if (!init || !str || !init->chars) return 25;
	for (size_t i = 0; str[i] != '\0'; ++i, init->top++) {
		if (init->top >= init->length) {
			int new_lgth = init->length * 2;
			char* temp = realloc(init->chars, new_lgth * sizeof(char));
			if (!temp) return 26;
			init->chars = temp;
			init->length= new_lgth;
		}
		init->chars[init->top] = str[i];
	}
	init->chars[init->top] = '\0';
	return 0;
}

int str_pop(string* init, size_t count) {
	if (!init||!init->chars||!count) return 25;

	if (init->top < count) {
		init->top = 0;
		init->chars[init->top] = '\0';
		return 0;
	}
	init->top = init->top - count;
	init->chars[init->top] = '\0';
	return 0;
}

string* str_from(const char* str) {
	if (!str) return NULL;

	string* init = malloc(sizeof(string));
	if (!init) return NULL;

	if (str_init(init, str)) return NULL;
	return init;
}

int str_destroy(string** init) {
	if (!init||!(*init)||!(*init)->chars) return 25;

	free((*init)->chars);
	free((*init));
	*init = NULL;
	return 0;
}
