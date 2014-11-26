/**
 * \file FileManager.c
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud
 */

#include "FileManager.h"

Bool FileExist(char* path) {
    int answer;
    char sentence[50]="[ ! -f ";
    char sentenceEnd[5]=" ]";
    strcat(sentence,path);
    strcat(sentence,sentenceEnd);
    answer=system(sentence);
    if(answer==0)
        return FALSE;
    else
        return TRUE;
}

Bool copyFile(char const * pFileName, char const * pNewFileName)
{
	BOOLEAN success = FALSE;
	char* newFileName;	// We can use pNewFileName because we want to modify it if the file already exists
	char* extName = malloc(sizeof(char) * 4);
	int newFileNameLength, i = 0;	// i : value is used for the file extension number


	newFileNameLength = stringLength(pNewFileName) + 3;	// +3 includes extName.
	newFileName = malloc(sizeof(char) * newFileNameLength);
	// Copy pNewFileName into newFileName using concat with an empty string
	newFileName = concat("", pNewFileName);

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
				newFileName = concat(newFileName, extName);
			else
				newFileName[newFileNameLength - 2] = extName[1];
			
			// Increase the extension increment for the next test
			// (if there is still an error after the previous modification) ... until i == 100
			i++;
		}
		else
		{
			success = FALSE;
			i = 100; // Exiting the loop
			//perror("Saving copy problem :N");
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
		fclose(file);
	}
	else
	{
		perror("Impossible to write the file");
	}

	return saved;
}

