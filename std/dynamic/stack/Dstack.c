#include "Dstack.h"
#include <stdio.h>
#include <stdlib.h>

int init_debug(dstack** target, const char* file, int line, const char* func) {
#
	int status = NO_ERR;
	if (target == NULL) {
		status = ER_ARG;
		goto error;
	}

	dstack* init = malloc(sizeof(dstack));
	if (init == NULL) {
		status = ER_MEM;
		goto error;
	}

	init->ceiling = 8;
	init->bottom  = 0;
	init->top     = 0;
	init->pointers = malloc(init->ceiling * sizeof(void*));
	
	if (init->pointers == NULL) {
		status = ER_MEM;
		goto err_pointers;
	}

	(*target) = init;
	return 0;

err_pointers:
	free(init);

end:
#if DEBUGMODE
	write_log(WARNING, status);
	printf("[TRACE]: Location: %s() | %s : line %d\n", func, file, line);
#endif
	return status;

}

int push_debug(dstack* init, void* pointer, const char* file, int line, const char* func) {
	int status = 0;
	
	if (init == NULL) {
		status = EINVAL;
		goto error;
	}
	
	if (init->top > init->ceiling) {
		int new_ceiling = init->ceiling * 2;
		void** temp = realloc(init->pointers, new_ceiling * sizeof(void*));
		
		if (temp == NULL) {
			status = ENOMEM;
			goto error;
		}
		
		init->pointers = temp;
		init->ceiling = new_ceiling;
	}
	init->pointers[init->top] = pointer;
	init->top++;
	return 0;


error:
#if DEBUGMODE
	printf("[ERROR]: Error output: %s\n", strerror(status));
	printf("[TRACE]: Location: %s() | %s : line %d\n", func, file, line);
#endif
	return status;
}

int pop_debug(dstack* init, void** pointer, const char* file, int line, const char* func ) {
	int status = 0;

	if (init == NULL) {
		status = EINVAL;
		goto error;
	}
	
	if (init->top  == init->bottom) {
		status = EAGAIN;
		goto error;
	}
	init->top--;
	(*pointer) = init->pointers[init->top];
	return 0;

error:
#if DEBUGMODE
	printf("[ERROR]: Output : %s\n", strerror(status));
	printf("[TRACE]: Location : %s() | %s : line %d\n", func, file, line);
#endif
	return status;
}
