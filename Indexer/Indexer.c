/**
 * \file Indexer.c
 * \brief The main manager for indexing files
 * \author Morgan Chabaud \n
 */

#include "Indexer.h"


/** Following declarations are made for testing **/
typedef int TextDesc;
typedef int PictureDesc;

TextDesc * createTextDesc(FILE* file)
{
	return NULL;
}

PictureDesc * createPictureDesc(FILE* file)
{
	return NULL;
}
/** Previous declarations are made for testing **/

//===================================================================================================
void foo(char *fmt, ...)
{
    va_list ap;
    int d;
    char c, *s;

   va_start(ap, fmt);
    while (*fmt)
    {
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    }
    va_end(ap);
}
//===================================================================================================
void indexation(char const * dirPath, ...)
{
	va_list ap;
	char * tmpParam;
	int textThread, pictureThread, soundThread;
	PathStacks pathStack;	// Contains the path
				// of ready-to-be-indexed files
	
	// Initialise pathStack
	initStack(pathStack.textPathStack.pathFile);
	pathStack.textPathStack.fileType = TEXT;
	initStack(pathStack.picturePathStack.pathFile);
	pathStack.picturePathStack.fileType = PICTURE;
	initStack(pathStack.soundPathStack.pathFile);
	pathStack.soundPathStack.fileType = SOUND;
	
	// Fill pathStack with files of the directory
	// paths given in parameter
	if(dirPath != NULL)
	{
		// First parameter isn't in ap
		updateIndexableFile(dirPath, &pathStack);
		
		va_start(ap, dirPath);
		// Browse through parameters and
		// update pathStack
		while((tmpParam = va_arg(ap, char *)) != NULL)
			updateIndexableFile(tmpParam, &pathStack);
		
		va_end(ap);
	}
	
	// Let's index those crazy files
	
	// TEXT
	textThread = fork();
	if(textThread == -1)
		/** Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED**/
	
	if(!textThread)	// The child
	{
		indexFiles(&pathStack.textPathStack);
		exit(0);
	}
	
	// PICTURE
	pictureThread = fork();
	if(pictureThread == -1)
		/** Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED **/
	
	if(!pictureThread)	// The child
	{
		indexFiles(&pathStack.picturePathStack);
		exit(0);
	}
	
	// SOUND
	soundThread = fork();
	if(soundThread == -1)
		/** Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED */
	
	if(!soundThread)	// The child
	{
		indexFiles(&pathStack.soundPathStack);
		exit(0);
	}
	
	// The godfather is still waiting for his kids to be killed
	/** TEST ON EXITS NEEDS TO BE WRITTEN **/
	wait(NULL);
	wait(NULL);
	wait(NULL);
}
//===================================================================================================
void indexFiles(FilePathStack const * filePathStack)
{
	BaseDesc baseDesc = initBaseDesc(filePathStack->fileType);
	ListeBaseDesc listBaseDesc = initListBaseDesc(filePathStack->fileType);
	int date = getDate();
	char * tmpPathFile;
	void * tmpDesc;		// the desc being written at the moment (in the while)
	void * (*createDesc)(char *);
	
	switch(filePathStack->fileType)
	{
		case TEXT:
			createDesc = createTextDesc;
			break;
			
		case PICTURE:
			createDesc = createPictureDesc;
			break;
			
		case SOUND:
			createDesc = createSoundDesc;
			break;
	}
	
	/** depiler doesn't exist..... TO BE REPLACED BY THE GOOD ONE **/
	while(tmpPathFile = depiler(&filePathStack->pathFile))
	{
		tmpDesc = createDesc(tmpPathFile);
		
		
		/** MUTEX ? 0_0 =) **/
		addDesc(&baseDesc, &tmpDesc, filePathStack->fileType);
		/** Following tmpDesc->address won't compile... **/
		addListBaseDesc(&listBaseDesc, tmpPathFile, tmpDesc->address, date);
		/** MUTEX ? 0_0 =) **/
	}
}
