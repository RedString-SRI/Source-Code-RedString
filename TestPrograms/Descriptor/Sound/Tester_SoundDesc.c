/**
 * \file Tester_SoundDesc.c
 * \brief Tester of SoundDesc functions
 * \author Morgan Chabaud \n
 */

#include "SoundDesc.h"
#include "FileManager.h"
#include "Type_Bool.h"

Bool tests_createDesc(Bool details);
Bool tests_printSoundDesc(Bool details);
Bool tests_writeSoundDesc(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundDesc:\n");
	
	hasPassed = tests_createDesc(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_createDesc: Success\n");
	else
		printf("\n\t\tTests_createDesc: Failure\n");
	
	hasPassed = tests_printSoundDesc(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_printSoundDesc: Success\n");
	else
		printf("\n\t\tTests_printSoundDesc: Failure\n");

	hasPassed = tests_writeSoundDesc(FALSE);
		if(hasPassed)
		printf("\n\t\tTests_createDesc: Success\n");
	else
		printf("\n\t\tTests_createDesc: Failure\n");
	
	printf("\tTester_End\n");
}
//===================================================================================================
Bool tests_createDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDesc *soundDesc;
	FILE* testFile = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("Error tests_createDesc fopen");
		return FALSE;
	}

	globs_windowSize = 4096;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;

	if(details)
		printf("\nIt creates a desc:");
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
//===================================================================================================
Bool tests_printSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDesc *soundDesc;
	FILE* testFile = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb");
	if(testFile == NULL)
	{
		perror("tests_createDesc fopen");
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
		printf("\nIt displays a desc:");
	//printSoundDesc(soundDesc);
	
	free(soundDesc);
	fclose(testFile);
	return TRUE;
}
//===================================================================================================
Bool tests_writeSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDesc *soundDesc, *newSoundDesc;
	FILE* testFile = fopen("testDesc.desc", "wb+"),
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
	//printf("Desc size %d", soundDescSize(soundDesc));
	fseek(testFile, 0, SEEK_SET);
	newSoundDesc = readSoundDesc(testFile);
	//printSoundDesc(newSoundDesc);
	
	free(soundDesc);
	fclose(testFile);
	fclose(corpus);
	return TRUE;
}
