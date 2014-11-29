
#ifndef TYPE_BASE_DESCRIPTOR
#define TYPE_BASE_DESCRIPTOR

typedef struct Descriptor{
  void * element;
  struct Descriptor * next;
} *BaseDescriptor; // DescriptorBase is represented by a stack of generic Descriptors, and is a pointer to the first element of the stack

#endif
