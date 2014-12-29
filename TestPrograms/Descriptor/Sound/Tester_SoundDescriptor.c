/**
 * \file Tester_SoundDescriptor.c
 * \brief Tester of SoundDescriptor functions
 * \author Morgan Chabaud \n
 */


#include "SoundDescriptor.h"
#include "FileManager.h"
#include "Type_Bool.h"



Bool tests_createDescriptor(Bool details);
Bool tests_printSoundDesc(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundDescriptor:\n");
	
	hasPassed = tests_createDescriptor(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_createDescriptor: Success\n");
	else
		printf("\n\t\tTests_createDescriptor: Failure\n");
	
	hasPassed = tests_printSoundDesc(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_createDescriptor: Success\n");
	else
		printf("\n\t\tTests_createDescriptor: Failure\n");

	printf("\tTester_End\n");
}

Bool tests_createDescriptor(Bool details)
{
	Bool testPassed = TRUE;
	SoundDescriptor *soundDesc;
	FILE* testFile = fopen("/home/rayope/SRI/FilRouge/data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("Error tests_createDescriptor fopen");
		return FALSE;
	}

	globs_windowSize = 4096;//2048;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;

	if(details)
		printf("\nIt creates a descriptor:");
	soundDesc = createSoundDesc(testFile);
	if(soundDesc != NULL)
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
	
	free(soundDesc);
	fclose(testFile);
	return testPassed;
}

Bool tests_printSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDescriptor *soundDesc;
	FILE* testFile = fopen("/home/rayope/SRI/FilRouge/data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("Error tests_createDescriptor fopen");
		return FALSE;
	}

	globs_windowSize = 4096;//2048;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;
	// Display a file

	soundDesc = createSoundDesc(testFile);
	// Usually soundDesc->id is initialised with another function.
	// We'll do it manually
	soundDesc->id = 666;
	
	if(details)
		printf("\nIt displays a descriptor:");
	printSoundDesc(soundDesc);
	
	free(soundDesc);
	fclose(testFile);
	return TRUE;
}
