/**
 * \file PictureDesc.h
 * \brief picture desc
 * \author Gabriel.DR
 * \version 0.1
 * \date 30 November 2014
 *
 */

#include "Type_PictureDesc.h"

#ifndef PICTURE_Desc
#define PICTURE_Desc

/*Initialize a new picture's desc*/
void initPictureDesc(PictureDesc *pd);

/**
 *\brief Give the size of the picture 
 */
Dimension getSizePicture(FILE *fileIMG);

/**
 *\brief create the picture's desc
 */
PictureDesc createPictureDesc(FILE *fileIMG);

/**/
void setNbcomp(int n);

/*return nbcomp*/
int getNbcomp();

/**
 *\brief Creat the image's histogramm
*/
void createHistogram(int bit[] , Dimension dim);

/**
 *\brief Print the image's histogramm
*/
void printHistogram(FILE *descriptIMG);


#endif
