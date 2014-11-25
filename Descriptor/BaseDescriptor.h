
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TextDescriptor.h"
#include "PictureDescriptor.h"
#include "SoundDescriptor.h"
#include "../Type_Bool.h"

#ifndef BASE_DESCRIPTOR
#define BASE_DESCRIPTOR

typedef enum {TEXT, IMAGE, SOUND} fileType;

typedef struct descriptor{
  void element;
  struct descriptor * next;
} *DescriptorBase; // DescriptorBase is represented by a stack of generic Descriptors, and is a pointer to the first element of the stack

//Permit to clear out the buffer : Use to secure datas
void clearBuffer();

//Send an error adapted message
void messageError(int i);

//Check if the path is right
BOOL pathExist(String path);

// Initializes a stack with a null pointer p
void initStack(DescriptorBase * p);

// Prints every elements of the stack
void printStack(DescriptorBase p);

// Checks if the the stack is empty
BOOL stackIsEmpty(DescriptorBase p);

// Stack an element into p
void stack(DescriptorBase * p, void e, fileType t);

// unstack the first element
void unstack(DescriptorBase * p);

// The user has to give elements to stack into the DescriptorBase
void writeStack(DescriptorBase * p, fileType t);

#endif // DESCRIPTORBASE_H_INCLUDED
