/**
 * \file BaseDesc.h
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#include "TextDesc.h"*/
#include "PictureDesc.h"
#include "SoundDesc.h"
#include "Type_Bool.h"
#include "Type_FileType.h"
#include "Type_BaseDesc.h"

#ifndef BASE_DESC
#define BASE_DESC

extern int globs_maxPathLength;

/**
 * \brief begin a chained list of descriptors
 *
 * Initializes a list with a null pointer p
 * \param base a BaseDesc's file type base to init the list
 */
void initList(BaseDesc * base);

/**
 * \brief create a new list base cell 
 *
 * Initialize an ordered list base cell
 * \param list a FileDesc to initialize
 */
void initListBase(struct FileDesc * list);

/**
 * \brief Prints on the output every descriptor of the base
 *
 * Prints every elements of the list, just using this for debugging
 * \param base a BaseDesc's file type to print
 * \param type a type for the descriptor
 */
void printList(BaseDesc base, FileType type);

/**
 * \brief Checks if the the list is empty
 *
 * Return TRUE if the list is empty
 * \param base a BaseDesc's file type to check
 */
Bool listIsEmpty(BaseDesc base);

/**
 * \brief Add a descriptor into the base
 *
 * Add a descriptor at the end of the list and at the end of the file BaseDesc
 * \param base a BaseDesc's file type update
 * \param structDesc a structDesc to add
 * \param type a type for the descriptor
 */
void addDesc(BaseDesc *base, void * structDesc, FileType type);

/**
 * \brief Get a descriptor in the base
 *
 * Get the descriptor with the address given in parameter
 * \param base a BaseDesc's base
 * \param address an address
 * \param type a type for the descriptor
 * \return an element descriptor
 */
void * getDesc(BaseDesc base, long address, FileType type);

/**
 * \brief Get a FileDesc in the base
 *
 * Get the FileDesc's pointer with the address given in parameter
 * \param list a ListBaseDesc's list
 * \param address an address
 * \return a ListBaseDesc
 */
ListBaseDesc getFileDesc(ListBaseDesc list, long address);

/**
 * \brief Get the file name in the listBase
 *
 * Get the file name string with the address given in parameter
 * \param list a ListBaseDesc's list
 * \param address an address
 * \return a string
 */
char * getFileName(ListBaseDesc list, long address);

/**
 * \brief Get the address in the listBase
 *
 * Get the address of the descriptor using the indexed file path string
 * \param list a ListBaseDesc's list
 * \param path a path string
 * \return the address
 */
long getAddress(ListBaseDesc list, char * path);

/**
 * \brief Get the desc's id in the listBase
 *
 * Get the address of the descriptor using the indexed file path string
 * \param list a ListBaseDesc's list
 * \param path a path string
 * \return the descriptor's id number
 */
long descExists(ListBaseDesc list, char * path);

/**
 * \brief Initialize a BaseDesc from a file
 *
 * Create a list with all of the descriptors from the file BaseDesc
 * \param fileType a fileType to choose
*/
BaseDesc initBaseDesc(FileType fileType);

/**
 * \brief Initialize a ListBaseDesc from a file
 *
 * Create an ordered list of file-descriptor-date structure
 * \param fileType a fileType to choose
*/
ListBaseDesc initListBaseDesc(FileType fileType);

/**
 * \brief Add a new element in the listBaseDesc
 *
 * add a structure from the path file, the adress and the date
 * \param listBaseDesc a listBaseDesc to update
 * \param path a file path
 * \param address the address of the descriptor
 * \param date the date of indexation
 * \param fileType a fileType to choose
*/
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date, FileType fileType);

/**
 * \brief remove the last descriptor from the base
 *
 * remove the last element from the base list
 * \param base the base to update
 * \param t a fileType to choose
*/
void removeDesc(BaseDesc * base, FileType t);

#endif
