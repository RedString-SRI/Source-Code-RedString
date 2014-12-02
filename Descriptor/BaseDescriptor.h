
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


// Initializes a list with a null pointer p
void initList(BaseDescriptor * base);

// Prints every elements of the list, just using this for debugging
void printList(BaseDescriptor base);

// Checks if the the list is empty
Bool listIsEmpty(BaseDescriptor base);

// Add a descriptor into the base
void addDescriptor(BaseDescriptor * base, void * structDescriptor, FileType type);

// Remove the descriptor with the same id as the one in the parameter
void remove(BaseDescriptor * base);

// The user has to give elements to stack into the BaseDescriptor
void writeList(BaseDescriptor * base, FileType type);

#endif
