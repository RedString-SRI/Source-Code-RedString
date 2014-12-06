/**
 * \file FileManager.c
 * \brief A high-level file manager set of functions
 * \author Morgan Chabaud
 */

#include "FileManager.h"

//===================================================================================================
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
//===================================================================================================
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
}
//===================================================================================================
Bool copyFile(char const * newFileName, char const * fileName)
{
	Bool fileNamePossible, fileCopied = FALSE;
	FILE *file, *newFile;
	const int extNameSize = 4;	// 5 : "_xy\0"
	char* modNewFileName;	// modifiednewFileName : We can't use newFileName because
				// we want to modify it if the file already exists
	char* extName;
	char buffer[BUFSIZ];
	int modNewFileNameLen, readSize, i;	// i : value is used for the file extension number
	int fileLen, newFileLen;

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
	modNewFileNameLen = strlen(newFileName) + extNameSize;

	if(modNewFileNameLen >= NAME_MAX)
	{
/** Error management **/
		return FALSE;
	}
	modNewFileName = malloc(sizeof(char) * modNewFileNameLen);
	
	modNewFileName = strncpy(modNewFileName, newFileName, modNewFileNameLen);

	// Test if the newFileName already exists or not and
	// try to add [x] at the end of the file name 100 times
	// before it gives up
	fileNamePossible = FALSE;
	i = 0;
	while(i < NEW_NAME_LIM_LEN && !fileNamePossible)
	{
		if(fileExists(modNewFileName))
		{
/** may have to show some log errors **/
			sprintf(extName, "_%d", i);
			if(i == 0)
				modNewFileName = strncat(modNewFileName, extName, extNameSize);
			else if(i < 9)
				modNewFileName[modNewFileNameLen - 2] = extName[1];
			else	// the name is now like ...._xy
			{
				modNewFileName[modNewFileNameLen - 3] = extName[1];	// x
				modNewFileName[modNewFileNameLen - 2] = extName[2];	// y
			}
			
			// Increase the extension increment for the next test
			// (if there is still an error after the previous modification) ... until i == 100
			i++;
		}
		else
			fileNamePossible = TRUE;
	}
	if(!fileNamePossible)
	{
		perror("copyFile fileNamePossible");
		return FALSE;
	}
	
    
	// Opening file descriptors
	file = fopen(fileName, "rb");
	if(file == NULL)
	{
		perror("copyFile fopen file");
		return FALSE;
	}

	newFile = fopen(modNewFileName, "wb");
	if(newFile == NULL)
	{
		perror("copyFile fopen newFile");
		return FALSE;
	}

	fileLen = newFileLen = 0;
	while(readSize = fread(buffer,1, BUFSIZ, file))
	{
		fileLen += readSize;
		newFileLen += fwrite(buffer, 1, readSize, newFile);
	}

	if(fileLen != newFileLen)
	{
/** Error management **/
		fileCopied = FALSE;
	}
	else
		fileCopied = TRUE;
	

	free(modNewFileName);
	free(extName);
	fclose(file);
	fclose(newFile);
	return fileCopied;
}
//===================================================================================================
Bool writeFile(char const * path, char const * data)
{
	FILE *file = fopen(path, "w+");
	Bool saved = FALSE;

	if(file != NULL)
	{
		if(fputs(data, file) != EOF)
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
//===================================================================================================
Bool readStruct(FILE* file, void ** wStruct, size_t structSize)
{
	if(fread(*wStruct, structSize, 1, file)) 
		return TRUE;
	else
	{
		perror("readStruct fread");
		return FALSE;
	}
}
//===================================================================================================
Bool writeStruct(FILE* file, void ** rStruct, size_t structSize)
{
	if(fwrite(*rStruct, structSize, 1, file)) 
		return TRUE;
	else
	{
		perror("readStruct fwrite");
		return FALSE;
	}
}
