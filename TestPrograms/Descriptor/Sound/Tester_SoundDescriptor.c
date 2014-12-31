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
Bool tests_writeSoundDesc(Bool details);


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
		printf("\n\t\tTests_printSoundDesc: Success\n");
	else
		printf("\n\t\tTests_printSoundDesc: Failure\n");

	fflush(stdout);
	hasPassed = tests_writeSoundDesc(FALSE);
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
	FILE* testFile = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("Error tests_createDescriptor fopen");
		return FALSE;
	}

	globs_windowSize = 4096;
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
	FILE* testFile = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("tests_createDescriptor fopen");
		return FALSE;
	}

	globs_windowSize = 4096;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;
	// Display a file

	soundDesc = createSoundDesc(testFile);
	// Usually soundDesc->id is initialised with another function.
	// We'll do it manually
	soundDesc->address = 666;
	
	if(details)
		printf("\nIt displays a descriptor:");
	//printSoundDesc(soundDesc);
	
	free(soundDesc);
	fclose(testFile);
	return TRUE;
}

Bool tests_writeSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDescriptor *soundDesc, *newSoundDesc;
	FILE* testFile = fopen("testDescriptor.desc", "wb+"),
		* corpus = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("tests_writeSoundDesc fopen");
		return FALSE;
	}
	
	globs_windowSize = 4096;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;

	soundDesc = createSoundDesc(corpus);
	soundDesc->address = 666;
	//printSoundDesc(soundDesc);
	writeSoundDesc(testFile, soundDesc);
	
	fseek(testFile, 0, SEEK_SET);
	newSoundDesc = readSoundDesc(testFile);
	//printSoundDesc(newSoundDesc);
	
	free(soundDesc);
	fclose(testFile);
	fclose(corpus);
	return TRUE;
}
