#ifndef DESCRIPTORBASE_H_INCLUDED
#define DESCRIPTORBASE_H_INCLUDED

typedef void * DescriptorBase; // DescriptorBase is represented by a stack of generic Descriptors, and is a pointer to the first element of the stack

// Permite to create a logic variable
enum BOOL={FALSE,TRUE};

//Check if the path is right
BOOL pathExist(String path);

// Initializes a stack with a null pointer p
void initStack(DescriptorBase * p);

// Prints every elements of the stack
void printStack(DescriptorBase p);

// Checks if the the stack is empty
BOOL stackIsEmpty(DescriptorBase p);

// Stack an element into p
void stack(TextBase * p, DescriptorBase e);

// unstack the first element
void unstack(DescriptorBase * p);

// The user has to give elements to stack into the DescriptorBase
void writeStack(DescriptorBase * p);

#endif // DESCRIPTORBASE_H_INCLUDED
