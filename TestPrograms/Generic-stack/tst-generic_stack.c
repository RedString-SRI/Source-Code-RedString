#include "generic_stack.h"

int main(){
	Stack s;
	int a = 3;
	initStack(&s);
	printStack(s, 'i');
	stack(&s, &a);
	printStack(s, 'i');
	printf("%d", *((int *)unstack(&s)));
	return 0;
}
