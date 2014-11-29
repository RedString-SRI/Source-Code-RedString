/**
 * \file FileManager.h
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud \n
 * tmpNote : http://stackoverflow.com/questions/11699596/how-to-set-errno-value
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include "Type_Bool.h"

#ifndef FILE_MANAGER
#define FILE_MANAGER

#define NEW_NAME_LIM_LEN 100

Bool pathExists(char const * path);

/**
 * \brief Tests if the file associated to a path exists.
 * 
 * The user must to give the file path like ~/TP/main.c
 * An errno is set accordingly.
 * \param path The path of the file. 
 * \return TRUE : If the file exist.\n
 * FALSE : If the file doesn't exist.
 */
Bool fileExist(char const * path);

/**
 * \brief Copies a file
 * 
 * It copies a fileName named newFileName to a new file named newFileName.\n
 * If the given newFileName does not already exist, the function tries to rename it 100 times like "name(i)").
 * 
 * Errors are returned if fileName is not able to be opened in read mode
 * \return TRUE : The file has been copied successfully \n
 *         FALSE : An error has been encountered. The file has not been copied.
 *
 */
Bool copyFile(char const * newFileName, char const * fileName);

/**
 * \brief Write data in path
 * 
 * It writes data in the file associated to path.
 *
 * \return TRUE : File has been written successfully \n
 * FALSE : Either there is a wrong parameter or a problem has been encountered
 *
 */
Bool writeFile(char const * path, char const * data);

#endif
