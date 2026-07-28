#ifndef STRING_H
#define STRING_H
#include <stddef.h>
#include <stdbool.h>

typedef struct {
	char* chars;
	size_t start;
	size_t length;
	size_t top;
} string;

size_t str_top(string*);
size_t str_len(string*);
bool str_empty(string*);

const char* str_cstr(string*);
int str_clear(string*);
int str_reserve(string*, size_t);

int str_init(string*, const char*);
int str_free(string*);

int str_append(string*, const char*);
int str_add(string*, char);

int str_pop(string*, size_t);

string* str_from(const char*);
int str_destroy(string**);

#endif
