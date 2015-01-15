/**
 * \file Indexer.h
 * \brief The main manager for indexing files
 * \author Morgan Chabaud \n
 */

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <dirent.h>


#include "Type_FileType.h"
#include "Type_BaseDesc.h"
#include "BaseDesc.h"
#include "SoundDesc.h"
#include "generic_stack.h"

#ifndef INDEXER
#define INDEXER


extern int globs_maxPathLength;

typedef struct{
	Stack pathFile;	// Stack is a structure pointer
	FileType fileType;
}FilePathStack;

typedef struct{
	FilePathStack textPathStack;
	FilePathStack picturePathStack;
	FilePathStack soundPathStack;
}PathStacks;

/**
 * \brief Index all indexable files in dirPath recursively
 *  
 * This functions takes an "infinite" number  of dirPath to indexable
 * \param dirPath The directory where you have indexable files
 * \param .... Others directories where you have indexable files
 */
void indexation(char const * dirPath, ...);

/**
 * \brief Update the stack of files given with indexable files of a directory
 *  
 * \param dirPath The directory where you have indexable files
 * \param pathStack It keeps the indexable file name
 */
void updateIndexableFile(char * dirPath, PathStacks * pathStack);

/**
 * \brief Supposed to return the date
 * 
 * Note: Doesn't work yet
 * \return the date with a specific format
 */
int getDate();

/**
 * \brief Index the file given with a FilePathStack
 * 
 * Note: Redundancy not taken in account
 * \param filePathStack The Stacks of indxable file names
 */
void indexFiles(FilePathStack const * filePathStack);


#endif
