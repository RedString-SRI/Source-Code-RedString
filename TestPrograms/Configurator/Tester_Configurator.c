/**
 * \file Tester_Configurator.c
 * \brief Tester of Configurator functions
 * \author Morgan Chabaud \n
 */

#include "Configurator.h"
#include "Type_Bool.h"


// TextDescriptor
extern int globs_occurThreshold;
extern int globs_maxTerms;

// SoundDescriptor
extern int globs_windowSize;
extern int globs_nbInterval;
extern double globs_minFrequency;
extern double globs_maxFrequency;

// PictureDescriptor
extern int globs_nbWeightyBits;
extern int globs_compTolerance;

Bool tests_setGlobsVariables(Bool details);
Bool tests_writeGlobs(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_Configurator:\n");
	
	hasPassed = tests_setGlobsVariables(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_setGlobsVariables: Success\n");
	else
		printf("\n\t\tTests_setGlobsVariables: Failure\n");
	
	hasPassed = tests_writeGlobs(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_writeGlobs (depends on readGlobs): Success\n");
	else
		printf("\n\t\tTests_writeGlobs (depends on readGlobs): Failure\n");
	
	printf("\tTester_End\n");
}

Bool tests_writeGlobs(Bool details)
{
	Bool testPassed = TRUE;
	
	return testPassed;
}

Bool tests_setGlobsVariables(Bool details)
{
	Bool testPassed = TRUE;
	WritableGlobs globs = { 10,
				15,
				20,
				25,
				0.35,
				-5.3,
				90,
				2};
				
	setGlobsVariables(&globs);
	
	if(details)
		printf("\nInitialising globs_occurThreshold : ");
	if(globs_occurThreshold != globs.textDesc_occurThreshold)
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
	
	if(details)
		printf("\nInitialising globs_maxTerms : ");
	if(globs_maxTerms != globs.textDesc_maxTerms)
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
	
	if(details)
		printf("\nInitialising globs_windowSize : ");
	if(globs_windowSize != globs.soundDesc_windowSize)
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
	
	if(details)
		printf("\nInitialising globs_nbInterval : ");
	if(globs_nbInterval != globs.soundDesc_nbInterval)
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
	
	if(details)
		printf("\nInitialising globs_minFrequency : ");
	if(globs_minFrequency != globs.soundDesc_minFrequency)
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
	
	if(details)
		printf("\nInitialising globs_maxFrequency : ");
	if(globs_maxFrequency != globs.soundDesc_maxFrequency)
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
	
	if(details)
		printf("\nInitialising globs_nbWeightyBits : ");
	if(globs_nbWeightyBits != globs.pictureDesc_nbWeightyBits)
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
	
	if(details)
		printf("\nInitialising globs_compTolerance : ");
	if(globs_compTolerance != globs.pictureDesc_compTolerance)
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