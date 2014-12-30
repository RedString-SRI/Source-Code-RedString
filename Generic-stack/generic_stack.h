/**
 * \file generic_stack.h
 * \brief a generic-element stack
 * \author Maxime Sanmartin
 */
#ifndef GENERIC_STACK_H_INCLUDED
#define GENERIC_STACK_H_INCLUDED

#include "../Type_Bool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \struct cell
 * \struct Descriptor
 * \brief A generic element a pointer to the next structure
 *
 * This structure is used to manage temporary files
*/
typedef struct cell{
	void * element;
	struct cell * next;
} * Stack;

void printElement(void * e, char type);

/**
 * \brief Initialize a stack
 *
 * Create an element stack
 * \param a stack to update
*/
void initStack(Stack * s);

/**
 * \brief Print on the output the stack. Just for debbugging
 *
 * Print every element of the stack from the last to first element stacked
 * \param a stack to print
*/
void printStack(Stack s, char type);

/**
 * \brief check if the stack is empty
 *
 * Look at the stack if there is an element
 * \param a stack to check
 * \return TRUE : the stack is empty
 *	else FALSE
*/
Bool stackIsEmpty(Stack s);

/**
 * \brief stack an element into the stack
 *
 * Add an element at the top of the stack
 * \param a stack to update
 * \param an element to add
*/
void stack(Stack * s, void * e);

/**
 * \brief unstack
 *
 * Remove the last element added to the stack
 * \param a stack to update
 * \return the element removed
*/
void * unstack(Stack * s);


#endif // GENERIC_STACK_H_INCLUDED
