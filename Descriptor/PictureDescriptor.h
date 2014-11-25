

#include "Type_PictureDescritor.h"

#ifndef PICTURE_DESCRIPTOR
#define PICTURE_DESCRIPTOR

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
