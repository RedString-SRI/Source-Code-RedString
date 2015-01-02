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

#include "Type_Bool.h"
#include "Type_WritableGlobs.h"
#include "Keyboard.h"

#ifndef CONFIGURATOR
#define CONFIGURATOR

#define CONF_FILE_NAME "parameters.conf"

// TextDescriptor
extern int globs_occurThreshold;
extern int globs_maxTerms;

// SoundDescriptor
extern int globs_windowSize;
extern int globs_nbInterval;
extern double globs_minFrequency;
extern double globs_maxFrequency;

// PictureDescriptor
extern int globs_nbWeightyBits;
extern int globs_compTolerance;

/**
 * \brief Initialise the configurator module
 * 
 * Look into the configuration file, if it is already set, it loads those variables
 * into the global ones. If it is not set, ask the user to type them in, write them
 * int the configuration file and loads them too. \n
 * If the configuration file does not exist, it will create it.
 */
Bool initConfigurator();

/**
 * \brief Ask the user to tape in configuration variables and set & save them straight after
 * 
 * \param confFile The configurator file. Cursor at the begining.
 * Needs to be opened in writing mode
 * \return TRUE : Variables have been set and saved correctly \n
 * FALSE : An error has occurred, variables can't be saved in a
 * configuration file
 */
Bool enterGlobsVariables(FILE* confFile);

/**
 * \brief Initialise global variables
 * 
 * Initialise global variables with globs
 * \param globs The WritableGlobs you want to initialise the global variables with
 */
void setGlobsVariables(WritableGlobs const * globs);

/**
 * \brief Save global variables to the configuration file
 * 
 * Write global variables globs to the configuration file pointed by confFile
 * \param confFile The configuration file to be written
 * \param globs The WritableGlobs that are already initialised
 */
Bool writeGlobs(WritableGlobs const * globs, FILE* confFile);

/**
 * \brief Initialise global variables from the configuration file
 * 
 * Initialise global variables from the configuration file pointed by confFile
 * \param confFile The configuration file to be read
 */
Bool readGlobs(FILE* confFile);

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

