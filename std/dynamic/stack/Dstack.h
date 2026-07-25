#ifndef DSTACK_H
#define DSTACK_H

typedef struct {
	void** pointers;
	int ceiling;
	int bottom; 
	int top;
} dstack;

int init_debug(dstack** target, const char*, int, const char*);

int push_debug(dstack*, void*, const char*, int, const char*);

int pop_debug(dstack*, void**, const char*, int,  const char*);

#define dstack_init(target) init_debug(target, __FILE__, __LINE__, __func__)

#define dstack_push(init, pointer) push_debug(init, pointer, __FILE__, __LINE__, __func__)

#define dstack_pop(init, pointer) pop_debug(init, pointer, __FILE__, __LINE__, __func__)

#endif
