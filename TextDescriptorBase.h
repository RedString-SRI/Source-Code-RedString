#ifndef TEXTDESCRIPTORBASE_H_INCLUDED
#define TEXTDESCRIPTORBASE_H_INCLUDED
#include "TextDescriptor.h"

typedef TextDescriptor * TextDescriptorBase; // TextDescriptorBase is represented by a stack of TextDescriptor, and is a pointer to the first element of the stack

// Initializes a stack with a null pointer p
void initStack(TextDescriptorBase * p);

// Prints every elements of the stack
void printStack(TextDescriptorBase p);

// Checks if the the stack is empty
int stackIsEmpty(TextDescriptorBase p);

// Stack an element into p
void stack(TextBase * p, TextDescriptorBase e);

// unstack the first element
TextDescriptor unstack(TextDescriptorBase * p);

// The user has to give elements to stack into the TextDescriptorBase
void saisirPile(TextDescriptorBase * p);


#endif // TEXTDESCRIPTORBASE_H_INCLUDED
