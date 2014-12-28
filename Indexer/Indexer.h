/**
 * \file Indexer.h
 * \brief The main manager for indexing files
 * \author Morgan Chabaud \n
 */

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "Type_FileType.h"
#include "Type_BaseDescriptor.h"

#ifndef INDEXER
#define INDEXER

typedef int Stack;

typedef struct{
	Stack * pathFile;
	FileType fileType;
}FilePathStack;

typedef struct{
	FilePathStack textPathStack;
	FilePathStack picturePathStack;
	FilePathStack soundPathStack;
}PathStacks;

void indexation(char const * dirPath, ...);

void foo(char *fmt, ...);

void updateIndexableFile(char * dirPath, PathStacks pathStack);

void indexFiles(FilePathStack const * filePathStack);


#endif