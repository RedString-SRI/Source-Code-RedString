/**
 * \file PictureDescriptor.h
 * \brief picture descriptor
 * \author Gabriel.DR
 * \version 0.1
 * \date 30 November 2014
 *
 */

#include "Type_PictureDescritor.h"

#ifndef PICTURE_DESCRIPTOR
#define PICTURE_DESCRIPTOR

/*Initialize a new picture's descriptor*/
void initPictureDescriptor(PictureDescriptor *pd);

/**
 *\brief Give the size of the picture 
 */
Dimension getSizePicture(FILE *fileIMG);

/**
 *\brief create the picture's descriptor
 */
PictureDescriptor createPictureDescriptor(FILE *fileIMG);

/**/
void setNbcomp(int n);

/*return nbcomp*/
int getNbcomp();

/**
 *\brief Permite to know how many high bits functions need to read
*/
void setNbquantif(int n);

/**
*\brief return nbquantif
*/
int getNbquantif();

/**
 *\brief Creat the image's histogramm
*/
void createHistogram(int bit[] , Dimension dim , int quantif);

/**
 *\brief Print the image's histogramm
*/
void printHistogram(FILE *descriptIMG);


#endif
