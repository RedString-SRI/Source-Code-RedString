

#include "Type_PictureDescritor.h"

#ifndef PICTURE_DESCRIPTOR
#define PICTURE_DESCRIPTOR

/*Initialize a new picture's descriptor*/
void initPictureDescriptor(PictureDescriptor *pd);

/**
 * Take the first line of the text file about the linked image.
 */
void getSizePicture(FILE *fileIMG, PictureDescriptor *descriptIMG);

/**
 * Take the Nsize next lines which are the linked red matrix of the image...
 */
void getMatrixRED(FILE *fileIMG, PictureDescriptor *descriptIMG);

/**
 * ... the next Nsize lines, the linked green matric ...
 */
void getMatrixGREEN(FILE *fileIMG, PictureDescriptor *descriptIMG);

/**
 * and the next Nsize lines, the matrix of blue of the linked image.
 */
void getMatrixBLUE(FILE *fileIMG, PictureDescriptor *descriptIMG);

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
