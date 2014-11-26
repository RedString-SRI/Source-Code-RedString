/**
 * \file FileManager.h
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud
 */

#include "../Type_Bool.h"

#ifndef FILE_MANAGER
#define FILE_MANAGER

/**
 * \brief This function copies the file pFileDescriptor in the current directory.
 *		It will be called pNewFileName
 *	
 *	Note: The given pNewFileName must not already exist (the function tries to rename it 100 times like "name(i)")
 *	      and the file associated with pFileDescriptor must be opened in reading
 * \return Bool : TRUE : The file has been copied successfully
 *                FALSE : An error has been encountered.
 *                        The file has not been copied.
 *
 */
Bool copyFile(char const * fileName, char const * newFileName);

/**
 * \fn int saveFile(char const * path, char const * data)
 * \brief This function save pData in pPath
 *
 * \return Bool : TRUE : Parameters have been loaded successfully
 *			 (There is at least one couple pKey, pValue)
 *		  FALSE : Either there is no parameter (key and value) or a problem has been encountered
 *
 */
Bool saveFile(char const * path, char const * data);

#endif
