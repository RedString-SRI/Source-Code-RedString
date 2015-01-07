#include "generic_stack.h"

int main(){
	Stack s;
	int a = 3;
	initStack(&s);
	printStack(s, 'i');
<<<<<<< HEAD
	stack(&s, &a);
=======
	stack(&s, a);
>>>>>>> d038f7f201e76b0d659409da9316e73394c66b4f
	printStack(s, 'i');
	printf("%d", *((int *)unstack(&s)));
	return 0;
}
