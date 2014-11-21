#include "ModeType.h"

#ifndef STRUCT_PICTURE_DESCRIPTOR
#define STRUCT_PICTURE_DESCRIPTOR

typedef struct{
  int id;
  Mode writingMode;
  int nbcomp ; /*d is the picture's number of components*/
  int nbquantif ; /*n is the number of bits picked for the quantification*/
  int histogram[2^(d*n)] ;
  
}PictureDescriptor;

#endif
