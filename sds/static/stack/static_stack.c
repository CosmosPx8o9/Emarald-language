#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>

static_stack* static_stack_init(int id) {
	static_stack* init = malloc(sizeof(static_stack));
	if (init == NULL) {
		printf("Failed init static stack\n");
		printf("[info]: id %d\n", id);
		return NULL;
	}
	
	init->ceiling = STATIC_STACK_CEILING;
	init->bottom  = 0;
	init->top   = 0;
	init->id = id;
	return init;
}

void static_stack_push(static_stack* init, void* pointer) {
	if (init == NULL) return;

	if (init->top > STATIC_STACK_CEILING) {
		printf("static Stack overflow!\n");
		printf("[info]: id %d\n", init->id);
		return;
	}

	init->pointers[init->top] = pointer;
	init->top++;
}

void* static_stack_pop(static_stack* init) {
	if (init == NULL) return NULL;

	if (init->top == init->bottom) {
		printf("static Stack underflow!\n");
		printf("[info]: id %d\n", init->id);
		return NULL;
	}
	init->top--;
	return init->pointers[init->top];
}
