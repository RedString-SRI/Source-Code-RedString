
#include "Type_WritingMode.h"

#ifndef TYPE_PICTURE_Desc
#define TYPE_PICTURE_Desc

typedef struct{
  int height;
  int width;
}Dimension;

typedef struct{
  int id;
  Dimension size;
  int nbcomp ; /*d is the picture's number of components*/
  int *histogram; // Will be an array of size : 2^(d*n)

}IMGDesc;

#endif
