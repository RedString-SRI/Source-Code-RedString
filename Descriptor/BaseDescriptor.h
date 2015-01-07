/**
 * \file BaseDesc.h
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#include "Text/TextDescriptor.h"
#include "Picture/PictureDescriptor.h"*/
#include "Sound/SoundDescriptor.h"
#include "../Type_Bool.h"
#include "Type_FileType.h"
#include "Type_BaseDescriptor.h"
#include "../Globals.c"

#ifndef BASE_DESCRIPTOR
#define BASE_DESCRIPTOR

/**
 * \brief begin a chained list of descriptors
 *
 * Initializes a list with a null pointer p
 * \param a BaseDesc's file type base to init the list
 */
void initList(BaseDesc * base);

/**
 * \brief Prints on the output every descriptor of the base
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
 * \brief Add a descriptor into the base
 *
 * Add a descriptor at the end of the list and at the end of the file BaseDesc
 * \param a BaseDesc's file type update
 * \param a structDesc to add
 * \param a type for the descriptor
 */
void addDescriptor(BaseDesc *base, void * structDesc, FileType type);

/**
 * \brief Initialize a BaseDesc from a file
 *
 * Create a list with all of the descriptors from the file BaseDesc
 * \param a fileType to choose
*/
BaseDesc initBaseDesc(FileType fileType);

/**
 * \brief Initialize a ListBaseDesc from a file
 *
 * Create an ordered list of file-descriptor-date structure
 * param a fileType to choose
*/
ListBaseDesc initListBaseDesc(FileType fileType);

/**
 * \brief Add a new element in the listBaseDesc
 *
 * add a structure from the path file, the adress and the date
 * \param a listBaseDesc to update
 * \param a file path
 * \param the address of the descriptor
 * \param the date of indexation
*/
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date);

/**
 * \brief remove the last descriptor from the base
 *
 * remove the last element from the base list
 * \param the base to update
*/
void removeDesc(BaseDesc * base, FileType type);

/**
 * \brief The user has to give elements to stack into the BaseDesc, only for debugging
 *
 * add elements to the list from the input
 * \param the base to write
 * \param the type to choose
*/
void writeList(BaseDesc * base, FileType type);

#endif
