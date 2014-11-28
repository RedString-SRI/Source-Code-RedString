/**
 * \file Configurator.h
 * \brief A file configurator system
 * \author Morgan Chabaud \n
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "../Type_Bool.h"

#ifndef CONFIGURATOR
#define CONFIGURATOR

Bool loadKeyValueParameters(char ** const param, int numParam, char * key[], char * value[]);
/// Info: This function puts parameters (those given to the program) from pParam to pKey and pValue
///       on condition that for each pKey, there is a pValue <(2n + 1 parameters).
///       The function deletes the first and the second parameter (executable and configFile).
///       It needs to have pKey and pValue already allocated (with a correct size...) before calling the function.

/**
 * \brief Compares the first word of a line
 * 
 * It compares the first word of line to key.
 * 
 * \return TRUE : key is at the begining of line \n
 * FALSE : key is NOT at the begining of line
 */
Bool matchKey (char const * line, char const * key);

/**
 * \brief Looks for a line containing a key in a file
 * 
 * Looks for the first line begining with key in the file linked to fileDescriptor.
 * \param fileDescriptor : The file you want to search into
 * \param key : The first word of a line you want to be returned
 * \return The line associated to key in the file or NULL if there
 * is no line in the file begining with key.
 */
char* matchedLineKey (int pFileDescriptor, char const * pKey);

/**
 * \brief Gives the value of the line (specific line)
 * 
 * From a line like "Key : value", the function returns the value. \n
 * Note that it just returns the string after spaces and one separator. \n
 * A separator (':' for example) could be given.
 * 
 * \param line : The line you want to have the value
 * \param separator : An optional separator between key and value can exists.
 * Give ' ' if you haven't one.
 * \return Returns the value associated to the line key or NULL if
 * an error has occured
 */
char* matchedValueLine (char const * line, char separator);

/**
 * \brief Reads the next line of a file
 * 
 * Reads the next line of the file pointed by fileDescriptor.
 * 
 * \return Either the next line or a char '\0' if an error has occurred
 */
char* readLine (int fileDescriptor);

/**
 * \brief Indicates a position ignoring spaces
 * 
 * From str and a position, it returns the next position (meaning after the spaces) \n
 * Ex : ignoreSpaces("This    chain", 4) return 8. So the begining of "chain".
 * \return The position of the next caracter (from the position given) excluding only spaces
 */
int ignoreSpaces(char const * str, int position);

#endif

