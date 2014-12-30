#include "generic_stack.h"

int main(){
	Stack s;
	initStack(&s);
	printStack(s, 'i');
	stack(&s, (void *)3);
	printStack(s, 'i');
	return 0;
}
