
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TextDescriptor.h"
#include "PictureDescriptor.h"
#include "SoundDescriptor.h"
#include "Type_Bool.h"
#include "Type_BaseDescriptor.h"

#ifndef BASE_DESCRIPTOR
#define BASE_DESCRIPTOR


// Initializes a stack with a null pointer p
void initStack(BaseDescriptor * p);

// Prints every elements of the stack
void printStack(BaseDescriptor p);

// Checks if the the stack is empty
Bool stackIsEmpty(BaseDescriptor p);

// Stack an element into p
void stack(BaseDescriptor * p, void e, fileType t);

// unstack the first element
void unstack(BaseDescriptor * p);

// The user has to give elements to stack into the BaseDescriptor
void writeStack(BaseDescriptor * p, fileType t);

#endif
