
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

typedef enum {TEXT, IMAGE, SOUND} fileType;

typedef struct descriptor{
  void element;
  struct descriptor * next;
} *DescriptorBase; // DescriptorBase is represented by a stack of generic Descriptors, and is a pointer to the first element of the stack

// Initializes a stack with a null pointer p
void initStack(DescriptorBase * p);

// Prints every elements of the stack
void printStack(DescriptorBase p);

// Checks if the the stack is empty
Bool stackIsEmpty(DescriptorBase p);

// Stack an element into p
void stack(DescriptorBase * p, void e, fileType t);

// unstack the first element
void unstack(DescriptorBase * p);

// The user has to give elements to stack into the DescriptorBase
void writeStack(DescriptorBase * p, fileType t);

#endif // DESCRIPTORBASE_H_INCLUDED
