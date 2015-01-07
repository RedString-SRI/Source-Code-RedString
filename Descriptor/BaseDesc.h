/**
 * \file BaseDesc.h
 * \brief A list of descs
 * \author Maxime Sanmartin \n
 */

#ifndef BASEDesc_H_INCLUDED
#define BASEDesc_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Text/TextDesc.h"
#include "Picture/PictureDesc.h"
#include "Sound/SoundDesc.h"
#include "../Type_Bool.h"
#include "Type_FileType.h"
#include "Type_BaseDesc.h"

#ifndef BASE_Desc
#define BASE_Desc

/**
 * \brief begin a chained list of descs
 *
 * Initializes a list with a null pointer p
 * \param a BaseDesc's file type base to init the list
 */
void initList(BaseDesc * base);

/**
 * \brief Prints on the output every desc of the base
 *
 * Prints every elements of the list, just using this for debugging
 * \param a BaseDesc's file type to print
 */
void printList(BaseDesc base);

/**
 * \brief Checks if the the list is empty
 *
 * Return TRUE if the list is empty
 * \param a BaseDesc's file type to check
 */
Bool listIsEmpty(BaseDesc base);

/**
 * \brief Add a desc into the base
 *
 * Add a desc at the end of the list and at the end of the file BaseDesc
 * \param a BaseDesc's file type update
 * \param a structDesc to add
 * \param a type for the desc
 */
void addDesc(BaseDesc *base, void * structDesc, FileType type);

/**
 * \brief Initialize a BaseDesc from a file
 *
 * Create a list with all of the descs from the file BaseDesc
 * \param a fileType to choose
*/
BaseDesc initBaseDesc(FileType fileType);

/**
 * \brief Initialize a ListBaseDesc from a file
 *
 * Create an ordered list of file-Desc-date structure
 * param a fileType to choose
*/
ListeBaseDesc initListBaseDesc(FileType fileType);

/**
 * \brief Add a new element in the listBaseDesc
 *
 * add a structure from the path file, the adress and the date
 * \param a listBaseDesc to update
 * \param a file path
 * \param the address of the desc
 * \param the date of indexation
*/
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date);

/**
 * \brief remove the last desc from the base
 *
 * remove the last element from the base list
 * \param the base to update
*/
void remove(BaseDesc * base);

/**
 * \brief The user has to give elements to stack into the BaseDesc, only for debugging
 *
 * add elements to the list from the input
 * \param the base to write
 * \param the type to choose
*/
void writeList(BaseDesc * base, FileType type);

#endif // BASEDesc_H_INCLUDED
