/**
 * \file PictureDesc.h
 * \brief picture desc
 * \author Gabriel.DR
 * \version 0.1
 * \date 10 Janury 2015
 *
 */

#include "Type_PictureDescritor.h"

#ifndef PICTURE_Desc
#define PICTURE_Desc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
  int height;
  int width;
}Dimension;

typedef struct{
  long id;
  Dimension dim;
  float *histogram;
}IMGdesc;


/**
 *\brief Give the size of the picture 
 */
Dimension getSizePicture(FILE *fileIMG);

/**
 *\brief create the picture's desc
 */
void createPictureDesc(FILE *fileIMG);

/**
 *\brief Creat the image's histogramm
*/
void createHistogram(FILE *file ,int bit[], IMGdesc *imgDsc , int size);

/**
 *\brief Print the image's histogramm
*/
void printHistogram(FILE *file);


#endif
