/**
 * \file generic_stack.c
 * \brief a generic-element stack
 * \author Maxime Sanmartin
 */
#include "generic_stack.h"

//-------------------------------------------------------------------------------------
void printElement(void * e, char type){
	switch(type){
		case 's' : printf("%s\n", (char *)e);
		break;
		case 'i' : printf("%d\n", *((int *)e));
		break;
		case 'l' : printf("%ld\n", *((long *)e));
		break;
		// If you need other type, just add another case
	}
}

//-------------------------------------------------------------------------------------
void initStack(Stack * s){
	*s = NULL;
}

//-------------------------------------------------------------------------------------
void printStack(Stack s, char type){
	if(stackIsEmpty(s))
		/** Error **/;
	else{
        Stack saux = s;
        printf("The stack is:\n");
		while(saux != NULL){
			printElement(saux->element, type);
			saux = saux->next;
		}
	}
}

//-------------------------------------------------------------------------------------
Bool stackIsEmpty(Stack s){
    return(s == NULL);
}

//-------------------------------------------------------------------------------------
void stack(Stack * s, void * e){
	Stack ptr_add = (Stack) malloc(sizeof(struct cell));
	if(ptr_add==NULL)
		/** Error **/;
	else{
		ptr_add->element = e;
		ptr_add->next = *s;
        *s = ptr_add;
	}
}

//-------------------------------------------------------------------------------------
void * unstack(Stack * s){
    Stack saux = *s;
    void * e = (*s)->element;
    *s = saux->next;
    free(saux);
    return(e);
}
