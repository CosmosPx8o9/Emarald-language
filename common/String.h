#ifndef STRING_H
#define STRING_H
#include <stddef.h>

typedef struct {
	char* chars;
	size_t start;
	size_t lgth;
	size_t top;
} string;

int str_init(string*, const char*);
int str_free(string*);
int str_append(string*, const char*);

#endif
