/**
 * \file Tester_FileManager.c
 * \brief Tester of FileManager functions
 * \author Morgan Chabaud \n
 */


#include "FileManager.h"

Bool tests_fileExists(Bool details);
Bool tests_copyFile(Bool details);
Bool tests_writeFile(Bool details);

int main()
{
	Bool hasPassed;
	printf("\n\n\n\n\t\Tester_FileManager :\n");
	
	hasPassed = tests_fileExists(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_fileExists : Success\n");
	else
		printf("\n\t\tTests_fileExists : Failure\n");
	
	hasPassed = tests_copyFile(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_copyFile (depends on fileExists): Success\n");
	else
		printf("\n\t\tTests_copyFile : Failure\n");
	
	
	printf("\tTester_End\n");
}

Bool tests_fileExists(Bool details)
{
	Bool testPassed = TRUE;

	/** The file does exist **/
	if(details)
		printf("\nThe file does exist : ");
	if(fileExists("existingFile"))
	{
		if(details)
			printf("Pass");
	}
	else
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	
	/** The file doesn't exist **/
	if(details)
		printf("\nThe file doesn't exist : ");
	if(fileExists("unexistingFile"))
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	else
	{
		if(details)
			printf("Pass");
	}
	return testPassed;
}

Bool tests_copyFile(Bool details)
{
	Bool testPassed = TRUE;

	/** File to copy doesn't exist **/
	if(details)
		printf("\nFile to copy doesn't exist : ");
	if(copyFile("copiedFile_empty", "copyFile_unexisting"))
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	else
	{
		if(fileExists("copiedFile_empty"))
		{
			if(details)
				printf("Fail");
			testPassed = FALSE;
		}
		else
		{
			if(details)
				printf("Pass");
		}
			
	}
	
	/** File name of the wanted copy already exists **/
	if(details)
		printf("\nFile name of the wanted copy already exists : ");
	if(copyFile("existingFile", "existingFile"))
	{
		if(details)
			printf("Pass");
	}
	else
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}

	
	/** File **/
	
	return testPassed;
}