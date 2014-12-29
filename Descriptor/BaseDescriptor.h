/**
 * \file BaseDescriptor.h
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#ifndef BASEDESCRIPTOR_H_INCLUDED
#define BASEDESCRIPTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Text/TextDescriptor.h"
#include "Picture/PictureDescriptor.h"
#include "Sound/SoundDescriptor.h"
#include "../Type_Bool.h"
#include "Type_FileType.h"
#include "Type_BaseDescriptor.h"

#ifndef BASE_DESCRIPTOR
#define BASE_DESCRIPTOR

/**
 * \brief begin a chained list of descriptors
 *
 * Initializes a list with a null pointer p
 * \param a BaseDescriptor's file type base to init the list
 */
void initList(BaseDescriptor * base);

/**
 * \brief Prints on the output every descriptor of the base
 *
 * Prints every elements of the list, just using this for debugging
 * \param a BaseDescriptor's file type to print
 */
void printList(BaseDescriptor base);

/**
 * \brief Checks if the the list is empty
 *
 * Return TRUE if the list is empty
 * \param a BaseDescriptor's file type to check
 */
Bool listIsEmpty(BaseDescriptor base);

/**
 * \brief Add a descriptor into the base
 *
 * Add a descriptor at the end of the list and at the end of the file BaseDescriptor
 * \param a BaseDescriptor's file type update
 * \param a structDescriptor to add
 * \param a type for the descriptor
 */
void addDescriptor(BaseDescriptor *base, void * structDescriptor, FileType type);

/**
 * \brief Initialize a BaseDescriptor from a file
 *
 * Create a list with all of the descriptors from the file BaseDescriptor
 * \param a fileType to choose
*/
BaseDescriptor initBaseDescriptor(FileType fileType);

/**
 * \brief Initialize a ListBaseDescriptor from a file
 *
 * Create an ordered list of file-descriptor-date structure
 * param a fileType to choose
*/
ListeBaseDesc initListBaseDescriptor(FileType fileType);

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
void remove(BaseDescriptor * base);

/**
 * \brief The user has to give elements to stack into the BaseDescriptor, only for debugging
 *
 * add elements to the list from the input
 * \param the base to write
 * \param the type to choose
*/
void writeList(BaseDescriptor * base, FileType type);

#endif // BASEDESCRIPTOR_H_INCLUDED
