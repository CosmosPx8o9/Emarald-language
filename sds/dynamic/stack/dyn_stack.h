#ifndef STACK_H
#define STACK_H

typedef struct {
	void** pointers;
	int ceiling;
	int bottom; 
	int top;
} dyn_stack;

stack* dyn_stack_init();
void dyn_stack_push(dyn_stack**, void*);
void* dyn_stack_pop(dyn_stack*);

#endif
