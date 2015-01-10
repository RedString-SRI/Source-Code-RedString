/**
 * \file Tester_SoundSearch.c
 * \brief Tester of SoundSearch functions
 * \author Morgan Chabaud \n
 */

#include "Type_Bool.h"
#include "SoundSearch.h"
#include <stdio.h>

extern int globs_nbInterval;
extern float globs_minQuantifMatch;
extern float globs_minWindowMatch;

Bool tests_compareWindows(Bool details);
Bool tests_compareSoundDesc(Bool details);


//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundSearch:\n");
	
	hasPassed = tests_compareWindows(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_compareWindows: Success\n");
	else
		printf("\n\t\tTests_compareWindows: Failure\n");
	
	hasPassed = tests_compareSoundDesc(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_compareSoundDesc: Success\n");
	else
		printf("\n\t\tTests_compareSoundDesc: Failure\n");
	

	printf("\tTester_End\n");
}

Bool tests_compareSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDesc *soundDescIndex, *soundDescSearch;
	FILE *soundIndexed = fopen("../../../../data/SON_CORPUS/corpus_m6.bin", "rb"),
		*soundSearched = fopen("../../../../data/SON_REQUETE/jingle_m6.bin", "rb");
	if(soundIndexed == NULL)
	{
		perror("Error tests_createDesc soundIndexed fopen");
		return FALSE;
	}
	if(soundSearched == NULL)
	{
		perror("Error tests_createDesc soundSearched fopen");
		return FALSE;
	}

	globs_windowSize = 2048;
	globs_maxFrequency = 0.4;
	globs_minFrequency = -0.4;
	globs_nbInterval = 64;
	globs_minWindowMatch = 60.0/100;
	globs_minQuantifMatch = 95.0/100;

	soundDescIndex = createSoundDesc(soundIndexed);
	soundDescSearch = createSoundDesc(soundSearched);

	if(details)
		printf("\nFinding entirely a smaller sound: ");
	if((compareSoundDesc(soundDescSearch, soundDescIndex) - 1.0) < 0.00001)	// float precision...
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
	
	free(soundDescIndex);
	free(soundDescSearch);
	fclose(soundIndexed);
	fclose(soundSearched);
	return testPassed;
}

Bool tests_compareWindows(Bool details)
{
	Bool testPassed = TRUE;
	globs_nbInterval = 5;
	globs_minWindowMatch = 60.0/100;
	globs_minQuantifMatch = 95.0/100;

	int window1[5] = {50, 39, 46, 55, 12},
		window2[5] = {50, 39, 46, 55, 12};
	
	if(details)
		printf("\nEqual windows: ");
	if(compareWindows(window1, window2) == 1.0)
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
	
	window1[0] = 49;
	
	if(details)
		printf("\nEqual windows with one quantif barely different: ");
	if((compareWindows(window1, window2) - 1.0) < 0.00001)	// float precision...
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
	
	window1[2] = 10;

	if(details)
		printf("\nOne quantif is different: ");
	if(fabs(compareWindows(window1, window2) - 4.0/5) < 0.00001)	// float precision...
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
	
	window1[0] = 0;
	window1[1] = -26;
	window1[3] = 900;
	
	if(details)
		printf("\nOne quantif is equal: ");
	if(fabs(compareWindows(window1, window2) - 1.0/5) < 0.00001)	// float precision...
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
	
	window1[4] = 300;
	
	if(details)
		printf("\nWindows are different: ");
	if(fabs(compareWindows(window1, window2) - 0.0) < 0.00001)	// float precision...
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
		
	return testPassed;
}