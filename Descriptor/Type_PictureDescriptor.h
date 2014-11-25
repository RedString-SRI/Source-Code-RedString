
#include "Type_WritingMode.h"

#ifndef TYPE_PICTURE_DESCRIPTOR
#define TYPE_PICTURE_DESCRIPTOR

struct{
  int id;
  Mode writingMode;
  int nbcomp ; /*d is the picture's number of components*/
  int nbquantif ; /*n is the number of bits picked for the quantification*/
  int *histogram; // Will be an array of size : 2^(d*n)

}PictureDescriptor;

#endif
