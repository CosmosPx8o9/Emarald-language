#include "String.h"
#include <stdio.h>
#include <stdlib.h>

size_t get_len(const char* str) {
	if (!str) return 0;
	size_t index = 0;
	for (; str[index] != '\0'; ++index) {}
	return index;
}

int str_init(string* init, const char* str) {
	if (!init || !str) return 25;

	init->start = 0;
	init->top = get_len(str);
	init->lgth = init->top * 2;
	init->chars = malloc(init->lgth * sizeof(char));
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
	if (!init || !str) return 25;
	for (size_t i = 0; str[i] != '\0'; ++i, init->top++) {
		if (init->top >= init->lgth) {
			int new_lgth = init->lgth * 2;
			char* temp = realloc(init->chars, new_lgth * sizeof(char));
			if (!temp) return 26;
			init->chars = temp;
			init->lgth = new_lgth;
		}
		init->chars[init->top] = str[i];
	}
	init->chars[init->top] = '\0';
	return 0;
}
