/**
 * \file PictureDesc.h
 * \brief picture desc
 * \author Gabriel.DR
 * \version 0.1
 * \date 30 November 2014
 *
 */

#include "Type_PictureDescritor.h"

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

/**
 * \brief Print a img desc in console
 * 
 * \param desc The desc to be displayed
 */
void printIMGDesc(IMGDesc desc);

/**
 * \brief Write a IMG desc to a file
 * 
 * Write desc to file (at the current position), so file
 * needs to be opened in the approriate writing mode
 * \param file The file you want to be written
 * \param desc The desc which is going to be
 * appended to the file
 */
void writeIMGDesc(FILE* file, IMGDesc* desc);

/**
 * \brief Read a sound desc from a file
 * 
 * Read a sound desc from a file (at the current position)
 * and returns it, so the file needs to be opened in
 * the approriate reading mode
 * \param file The file you want to be read
 * \return The desc which is going to store the read one
 */
IMGDesc readIMGDesc(FILE* file);
#endif
