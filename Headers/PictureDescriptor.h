#include "ModeType.h"

#ifndef STRUCT_PICTURE_DESCRIPTOR
#define STRUCT_PICTURE_DESCRIPTOR

typedef struct{
  int id;
  Mode writingMode;
  int nbcomp ; /*d is the picture's number of components*/
  int nbquantif ; /*n is the number of bits picked for the quantification*/
  int *histogram; // Will be an array of size : 2^(d*n)
  
}PictureDescriptor;

/*Initialize a new picture's descriptor*/
void initPictureDescriptor(PictureDescriptor *pd);

/*Change mode*/
void setMode(Mode *m);

/*return mode*/
Mode getMode();

/**/
void setNbcomp(int n);

/*return nbcomp*/
int getNbcomp();

/**/
void setNbquantif(int n);

/*return nbquantif*/
int getNbquantif();

/*Creat the image's histogramm*/
void createHistogramm();

/*Print the image's histogramm*/
void printHistogramm();


#endif
