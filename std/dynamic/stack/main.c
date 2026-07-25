#include <stdio.h>
#include "Dstack.h"
#include <stdlib.h>

int main(void) {
	dstack* q = NULL;
	int err;
	void *value;
	if ((err = dstack_init(&q))) exit(err);

	dstack_push(q, &err);
	for (int i = 0; i < 10; ++i) {
		dstack_pop(q, &value);
	}
	free(q->pointers);
	free(q);
}
