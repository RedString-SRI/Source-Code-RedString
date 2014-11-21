#ifndef STRUCT_TEXT_DESCRIPTOR
#define STRUCT_TEXT_DESCRIPTOR

typedef struct{
  int id;
  Mode WritingMode;
  ...
}TextDescriptor;

#endif

#ifndef STRUCT_TERM
#define STRUCT_TERM

typedef struct{
  char * word;
  int occur;
}Term;

#endif
