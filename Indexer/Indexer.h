/**
 * \file Indexer.h
 * \brief The main manager for indexing files
 * \author Morgan Chabaud \n
 */

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


#include "Type_FileType.h"
#include "Type_BaseDesc.h"
#include "BaseDesc.h"
#include "SoundDesc.h"
#include "generic_stack.h"

#ifndef INDEXER
#define INDEXER


extern int globs_maxPathLength;

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

void updateIndexableFile(char * dirPath, PathStacks * pathStack);

void indexFiles(FilePathStack const * filePathStack);


#endif
