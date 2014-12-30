#include <stdio.h>
#include "generic_stack.h"

int main(){
	Stack s;
	initStack(&s);
	printStack(s, (void *)'s');
	stack(&s, 'e', (void *)'s');
	return 0;
}
