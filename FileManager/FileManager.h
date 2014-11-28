/**
 * \file FileManager.h
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud
 * tmpNote : http://stackoverflow.com/questions/11699596/how-to-set-errno-value
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include "../Type_Bool.h"

#ifndef FILE_MANAGER
#define FILE_MANAGER

#define NEW_NAME_LIM_LEN 100

/**
 * \brief Tests if the file associated to a path exists.
 * The user must to give the file path like ~/TP/main.c
 * 
 * An errno is set accordingly.
 * \param path The path of the file. 
 * \return Bool :  TRUE : If the file exist.
 *                FALSE : If the file doesn't exist.
 */
Bool FileExist(char const * path);

/**
 * \brief Copies a file
 * It copies a fileName named newFileName to a new file named newFileName.
 * If the given newFileName does not already exist, the function tries to rename it 100 times like "name(i)").
 * 
 * Errors are returned if fileName is not able to be opened in read mode
 * \return Bool : TRUE : The file has been copied successfully
 *                FALSE : An error has been encountered.
 *                        The file has not been copied.
 *
 */
Bool copyFile(char const * fileName, char const * newFileName);

/**
 * \brief Write data in path
 *
 * \return Bool : TRUE : File has been written successfully
 *		  FALSE : Either there is a wrong parameter or a problem has been encountered
 *
 */
Bool writeFile(char const * path, char const * data);

#endif