#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#define STATIC_STACK_CEILING 64

typedef struct {
	void* pointers[STATIC_STACK_CEILING];
	int ceiling;
	int bottom;
	int top;
	int id;
} static_stack;

static_stack* static_stack_init(int);
void static_stack_push(static_stack*, void*);
void* static_stack_pop(static_stack*);

#endif
