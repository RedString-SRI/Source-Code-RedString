
#include "Type_WritingMode.h"

#ifndef TYPE_PICTURE_DESCRIPTOR
#define TYPE_PICTURE_DESCRIPTOR

typedef struct{
  int height;
  int width;
}Dimension;

typedef struct{
  int id;
  Dimension size[2];
  Mode writingMode;
  int nbcomp ; /*d is the picture's number of components*/
  int *histogram; // Will be an array of size : 2^(d*n)

}PictureDescriptor;

#endif
