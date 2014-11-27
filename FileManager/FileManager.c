/**
 * \file FileManager.c
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud
 */

#include "FileManager.h"

Bool fileExists(char const * path) {
    if(path != NULL)
    {
    	if(access(path, F_OK)) // File unreachable
    		return FALSE;
    	else// Otherwise the file exists
    		return TRUE;
    }
    else
    {
    	perror("Error in fileExists : path ");
    	return FALSE;
    }
}

int fileSize(FILE* file)
{
	int size;
	if(file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		fseek(file, 0, SEEK_SET);
	}
	else
	{
		errno = EBADF;
		perror("fileSize file");
		return -1;
	}

Bool copyFile(char const * fileName, char const * newFileName)
{
	Bool success;
	FILE* file, newFile;
	const int extNameSize = 4;	// 4 : "[x]\0"
	char* newFileName;	// We can use pNewFileName because we want to modify it if the file already exists
	char* extName;
	char buffer[BUFSIZ];
	int newFileNameLength, i;	// i : value is used for the file extension number

	// Parameters Test
	if(fileName == NULL || strlen(fileName) <= 0)
	{
/** Error management **/
		return FALSE;
	}
	if(newFileName == NULL || strlen(newFileName) <= 0)
	{
/** Error management **/
		return FALSE;
	}

	
	extName = malloc(sizeof(char) * extNameSize);
	newFileNameLength = strlen(pNewFileName) + (extNameSize - 1);	// extNameSize - 1 removes the '\0' allocated size 
	if(newFileNameLength >= NAME_MAX)
	{
/** Error management **/
		return FALSE;
	}
	newFileName = malloc(sizeof(char) * (newFileNameLength + extNameSize));
	// Copy pNewFileName into newFileName using strncat with an empty string
	newFileName = strncpy("", pNewFileName, newFileNameLength);

	success = FALSE;
	i = 0;
	while(i < COPYLIMIT && !success)
	{
		// Test if the file has been copied successfully or if it already exists or there is another error
		if(link(pFileName, newFileName) == 0)
		{
			printf("\nCopy saved succesfully as \"%s\".", newFileName);
			success = TRUE;
		}
		else if(errno == EEXIST)
		{
			// Change name of the file until. Try to change it 100 times until it gives up.
			printf("\n\"%s\" already exists. It is going to be saved as \"%s(%d)\".", newFileName, pNewFileName, i);

			// Adjusting i value in extName
			sprintf(extName, "(%d)", i);
			if(i == 0)
				newFileName = strncat(newFileName, extName, newFileNameLength);
			else
				newFileName[newFileNameLength - 2] = extName[1];
			
			// Increase the extension increment for the next test
			// (if there is still an error after the previous modification) ... until i == 100
			i++;
		}
		else
		{
			i = 100; // Exiting the loop
			perror("copyFile link");
		}
	}

	free(newFileName);
	free(extName);
	return success;
}

Bool saveFile(char const * path, char const * data)
{
	FILE *file = fopen(pPath, "w+");
	Bool saved = FALSE;

	if(file != NULL)
	{
		if(fputs(pData, file) != EOF)
			saved = TRUE;
		else
		{
			perror("Error saveFile_fputs");
		}
		fclose(file);
	}
	else
	{
		perror("Error saveFile_fopen");
	}

	return saved;
}

