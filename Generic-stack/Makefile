generic_stack.o : generic_stack.c generic_stack.h
	gcc -c -o generic_stack.o generic_stack.c
	
tst-generic_stack.o : tst-generic_stack.c
	gcc -c -o tst-generic_stack.o tst-generic_stack.c
	
tst-generic_stack : tst-generic_stack.o generic_stack.o
	gcc -o tst-generic_stack generic_stack.o tst-generic_stack.o
