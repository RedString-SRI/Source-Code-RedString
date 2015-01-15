/**
 * \file Indexer.c
 * \brief The main manager for indexing files
 * \author Morgan Chabaud \n
 */

#include "Indexer.h"


//===================================================================================================
void indexation(char const * dirPath, ...)
{
	va_list ap;
	char * tmpParam;
	int soundThread;//, textThread, pictureThread;
	PathStacks pathStack;	// Contains the path
				// of ready-to-be-indexed files
	
	// Initialise pathStack
	initStack(&pathStack.soundPathStack.pathFile);
	pathStack.soundPathStack.fileType = SOUND;
	/*initStack(pathStack.textPathStack.pathFile);
	pathStack.textPathStack.fileType = TEXT;
	initStack(pathStack.picturePathStack.pathFile);
	pathStack.picturePathStack.fileType = PICTURE;*/
	
	
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
	
	// SOUND
	soundThread = fork();
	if(soundThread == -1)
		/// Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED
	
	if(!soundThread)	// The child
	{
		indexFiles(&pathStack.soundPathStack);
		exit(0);
	}
	
	// TEXT
	/*textThread = fork();
	if(textThread == -1)
		/// Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED
	
	if(!textThread)	// The child
	{
		indexFiles(&pathStack.textPathStack);
		exit(0);
	}*/
	
	// PICTURE
	/*pictureThread = fork();
	if(pictureThread == -1)
		/// Thread doesn't work, jump into slow mode.	TO BE IMPLEMENTED
	
	if(!pictureThread)	// The child
	{
		indexFiles(&pathStack.picturePathStack);
		exit(0);
	}*/
	
	// The godfather is still waiting for his kids to be killed
	/** TEST ON EXITS NEEDS TO BE WRITTEN **/
	wait(NULL);
	/*wait(NULL);
	wait(NULL);*/
}
//===================================================================================================
void updateIndexableFile(char * dirPath, PathStacks * pathStack)
{
	struct dirent **directories;
	struct stat tmpFileStat;
	globs_maxPathLength = 250;
	char *pathRoot = malloc(globs_maxPathLength * sizeof(*pathRoot)),
		*innerPathRoot = malloc(globs_maxPathLength * sizeof(*innerPathRoot)),
		*tmpFilePath = malloc(globs_maxPathLength * sizeof(*tmpFilePath)),
		*pathKeeper;	// Used to store the path
	int nbFile = scandir(dirPath, &directories, NULL, alphasort);
	int i = 0;
	Bool isSound, isText, isPicture;
	if(pathRoot == NULL)
		perror("updateIndexableFile malloc");
	if(innerPathRoot == NULL)
		perror("updateIndexableFile malloc");
	if(tmpFilePath == NULL)
		perror("updateIndexableFile malloc");
	
	// Setting the new root for files with dirPath as parent directory
	pathRoot[0] = '\0';
	pathRoot = strcpy(pathRoot, dirPath);
	pathRoot = strcat(pathRoot, "/");
	//printf("\nPATHROOT : %s", pathRoot);
	//printf("\n%d: %s", i, directories[i]->d_name);
	
	
	for(; i < nbFile; i++)
	{
		if(strncmp(directories[i]->d_name, ".", 2) == 0 ||
			strncmp(directories[i]->d_name, "..", 3) == 0)
			continue;
		tmpFilePath = strcpy(tmpFilePath, pathRoot);
		tmpFilePath = strcat(tmpFilePath, directories[i]->d_name);
		
		errno = 0;
		if(!stat(tmpFilePath, &tmpFileStat))
		{
			//printf("\nThere is : %s at %d", tmpFilePath, i);
			//perror("updateIndexableFile stat");
		}
		
		// If it is a directory, we jump into it
		if(S_ISDIR(tmpFileStat.st_mode))
		{
			//printf("\nDir: tmpFilePath: %s", tmpFilePath);
			innerPathRoot = strcpy(innerPathRoot, tmpFilePath);
			//innerPathRoot = strcat(tmpFilePath, directories[i]->d_name);
			//printf("\ninnerPathRoot : %s", innerPathRoot);
			updateIndexableFile(innerPathRoot, pathStack);
		}
		else
		{
			//printf("\ntmpFilePath : %s", tmpFilePath);
			
			// If we find .bin in the filePath, we consider it as a sound file
			if(strstr(tmpFilePath, "corpus_m6.bin") != NULL)
				isSound = TRUE;
			/*else if(strstr(tmpFilePath, ".xml") != NULL)
				isText = TRUE;
			else if(strstr(tmpFilePath, ".txt") != NULL)
				isPicture = TRUE;*/
			else
				continue;
				
			
			// Add the new file to index
			// pathKeeper will not be free until someone unstack pathStack->soundPathStack.pathFile
			pathKeeper = malloc(globs_maxPathLength * sizeof(*pathKeeper));
			pathKeeper = strcpy(pathKeeper, tmpFilePath);
			
			if(isSound)
			{
				stack(&pathStack->soundPathStack.pathFile, pathKeeper);
				isSound = FALSE;
			}
			/*else if(isText)
			{
				stack(&pathStack->textPathStack.pathFile, pathKeeper);
				isText = FALSE;
			}
			else if(isPicture)
			{
				stack(&pathStack->picturePathStack.pathFile, pathKeeper);
				isPicture = FALSE;
			}*/
			
		}
	}

	//puts("Le dossier a ete ferme avec succes");
	free(pathRoot);
	free(innerPathRoot);
	free(tmpFilePath);
}
//===================================================================================================
int getDate()
{
	return 1;
}
//===================================================================================================
void indexFiles(FilePathStack const * filePathStack)
{
	BaseDesc baseDesc = initBaseDesc(filePathStack->fileType);
	ListBaseDesc listBaseDesc = initListBaseDesc(filePathStack->fileType);
	int date = getDate();
	char * tmpPathFile;
	void * tmpDesc;		// the desc being written at the moment (in the while)
	void * (*createDesc)(char *);
	long address;
	
	switch(filePathStack->fileType)
	{
		case SOUND:
			createDesc = createSoundDesc;
			address = ((SoundDesc*)tmpDesc)->address;
			break;
		
		/*case TEXT:
			createDesc = createTextDesc;
			address = ((TextDesc*)tmpDesc)->address;
			break;
			
		case PICTURE:
			createDesc = createPictureDesc;
			address = ((PictureDesc*)tmpDesc)->address;
			break;*/
			
		
	}
	
	while(stackIsEmpty(filePathStack->pathFile))
	{
		tmpPathFile = unstack(&filePathStack->pathFile);
		tmpDesc = createDesc(tmpPathFile);
		
		
		/** MUTEX ? 0_0 =) **/
		addDesc(&baseDesc, &tmpDesc, filePathStack->fileType);

		addListBaseDesc(&listBaseDesc, tmpPathFile, address, date, filePathStack->fileType);
		/** MUTEX ? 0_0 =) **/
	}
}
