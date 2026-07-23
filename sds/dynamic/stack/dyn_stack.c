#include "dyn_stack.h"
#include <stdio.h>
#include <stdlib.h>

dyn_stack* dyn_stack_init() {
	stack* init = malloc(sizeof(dyn_stack));
	init->ceiling = 8;
	init->bottom = 0;
	init->top = 0;
	init->pointers = malloc(init->ceiling * sizeof(void*));
	return init;
}

void dyn_stack_push(dyn_stack** initial, void* pointer) {
	stack* init = *initial;
	if (init == NULL) return;

	if (init->top > init->ceiling) {
		int new_ceiling = init->ceiling * 2;
		stack* temp = realloc(init, new_ceiling * sizeof(void*));
		if (temp == NULL) {
			printf("[Warning]: Unable to expand stack, stack overflow!\n");
			return;
		}
		init = temp;
		init->ceiling = new_ceiling;
		(*initial) = init;
	}
	init->pointers[init->top] = pointer;
	init->top++;
}

void* dyn_stack_pop(dyn_stack* init) {
	if (init == NULL) return NULL;
	if (init->top - 1 < init->bottom) {
		printf("[Warning]: Stack underflow!\n");
		return NULL;
	}
	init->top--;
	return init->pointers[init->top];
}
