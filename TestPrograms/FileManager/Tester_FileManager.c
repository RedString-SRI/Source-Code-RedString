/**
 * \file Tester_FileManager.c
 * \brief Tester of FileManager functions
 * \author Morgan Chabaud \n
 */


#include "FileManager.h"

Bool tests_readStruct(Bool);
Bool tests_fileExists(Bool);
Bool tests_fileSize(Bool);
Bool tests_copyFile(Bool);
Bool tests_writeFile(Bool);

typedef struct{
	int a;
	char b;
}Integ;

//===================================================================================================
int main()
{
	Bool hasPassed;
	
	printf("\n\n\n\n\tTester_FileManager (without verifying written data, done a la mano) :\n");
	
	hasPassed = tests_fileExists(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_fileExists : Success\n");
	else
		printf("\n\t\tTests_fileExists : Failure\n");
	
	hasPassed = tests_copyFile(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_copyFile (depends on fileExists): Success\n");
	else
		printf("\n\t\tTests_copyFile : Failure (may be caused by root)\n");
	
	
	hasPassed = tests_readStruct(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_readStruct : Success\n");
	else
		printf("\n\t\tTests_readStruct : Failure\n");
	
	
	printf("\tTester_End\n");
}
//===================================================================================================
Bool tests_readStruct(Bool details)
{
	Bool testPassed = TRUE;
	Integ *myInteg, *newInteg;
	myInteg = malloc(sizeof(Integ));
	newInteg = malloc(sizeof(Integ));

	FILE* file = fopen("testStruct", "wb+");
	if(file == NULL)
	{
		perror("copyFile fopen file");
		return FALSE;
	}
	
	
	myInteg->a = 1;
	myInteg->b = 'a';
	
	printf("%d%c", myInteg->a, myInteg->b);
	if(!writeStruct(file, &myInteg, sizeof(Integ)))
		testPassed = FALSE;
	
	fseek(file, 0, SEEK_SET);
	
	if(!readStruct(file, &newInteg, sizeof(Integ)))
		testPassed = FALSE;
	
	printf("\nNew int : %d and %c", newInteg->a, newInteg->b);
	
	free(myInteg);
	free(newInteg);
	fclose(file);
	return testPassed;
}
//===================================================================================================
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
//===================================================================================================
Bool tests_fileSize(Bool details)
{
	Bool testPassed = TRUE;


	/** The file doesn't exist **/
	if(details)
		printf("\nThe file doesn't exist : ");
	if(fileSize("unexistingFile"))
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
//===================================================================================================
Bool tests_copyFile(Bool details)
{
	Bool testPassed = TRUE;

	/** File to copy doesn't exist **/
	if(details)
		printf("\nFile to copy doesn't exist : ");
	if(copyFile("copyFile_unexisting2", "copyFile_unexisting"))
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	else
	{
		if(fileExists("copyFile_unexisting2"))
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
	
	/** File to copy doesn't have read permission **/
	// Not testable in root
	if(details)
		printf("\nFile to copy doesn't have read permission : ");
	if(copyFile("notPossibleFile", "file_noReadRight"))
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	else
	{
		if(fileExists("notPossibleFile"))
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
			printf("Pass (without verifying written data)");
	}
	else
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	
	/** File should be copied **/
	if(details)
		printf("\nFile should be copied : ");
	if(copyFile("aBigFile", "bigfile"))
	{
		if(fileExists("notPossibleFile"))
		{
			if(details)
				printf("Pass (without verifying written data)");
		}
		else
		{
			if(details)
				printf("Fail");
			testPassed = FALSE;
		}
	}
	else
	{
		if(details)
			printf("Fail");
		testPassed = FALSE;
	}
	
	
	return testPassed;
}
