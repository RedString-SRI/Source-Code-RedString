/**
 * \file generic_stack.c
 * \brief a generic-element stack
 * \author Maxime Sanmartin
 */
#include "generic_stack.h"

void printElement(void * e, char fileType){}

void writeFile(FILE * file, void * e, char fileType){}

//-------------------------------------------------------------------------------------
void initStack(Stack * s){
	*s = NULL;
	system("touch text.txt");
}

//-------------------------------------------------------------------------------------
void printStack(Stack s, char fileType){
	if(s == NULL)
		/** Error **/;
	else{
        Stack saux = s;
        printf("The stack is:\n");
		while(saux != NULL){
			printElement(saux->element, fileType); // The user has to implement this for the type he wants to use
			saux = saux->next;
		}
	}
}

//-------------------------------------------------------------------------------------
Bool stackIsEmpty(Stack s){
    return(s == NULL);
}

//-------------------------------------------------------------------------------------
void stack(Stack * s, void * e, char fileType){
	Stack ptr_add = (Stack) malloc(sizeof(struct cell));
	if(ptr_add==NULL)
		/** Error **/;
	else{
		ptr_add->element = e;
		ptr_add->next = *s;
        *s = ptr_add;
	}
	FILE * file = fopen("test.txt", "w");
	if(file==NULL)
		/** Error **/;
	else{
		rewind(file);
		writeFile(file, e, fileType); // The user has to implement this for the type he wants to use
		fclose(file);
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
