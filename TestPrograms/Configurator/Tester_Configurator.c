/**
 * \file Tester_Configurator.c
 * \brief Tester of Configurator functions
 * \author Morgan Chabaud \n
 */

#include "Configurator.h"
#include "Type_Bool.h"


// TextDesc
extern int globs_occurThreshold;
extern int globs_maxTerms;

// SoundDesc
extern int globs_windowSize;
extern int globs_nbInterval;
extern double globs_minFrequency;
extern double globs_maxFrequency;

// PictureDesc
extern int globs_nbWeightyBits;
extern int globs_compTolerance;

Bool tests_setGlobsVariables(Bool details);
Bool tests_writeReadGlobs(Bool details);
Bool tests_enterGlobsVariables(Bool details);
Bool tests_initConfigurator(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_Configurator:\n");
	
	hasPassed = tests_setGlobsVariables(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_setGlobsVariables: Success\n");
	else
		printf("\n\t\tTests_setGlobsVariables: Failure\n");
	
	hasPassed = tests_writeReadGlobs(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_writeReadGlobs: Success\n");
	else
		printf("\n\t\tTests_writeReadGlobs: Failure\n");
	
	hasPassed = tests_enterGlobsVariables(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_enterGlobsVariables: Success\n");
	else
		printf("\n\t\tTests_enterGlobsVariables: Failure\n");
	
	hasPassed = tests_initConfigurator(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_initConfigurator: Success\n");
	else
		printf("\n\t\tTests_initConfigurator: Failure\n");
	
	printf("\tTester_End\n");
}
//===================================================================================================
Bool tests_initConfigurator(Bool details)
{
	Bool testPassed = TRUE;
	// Deleting the previous test file
	FILE* confFile = fopen(CONF_FILE_NAME, "wb+");
	if(confFile == NULL)
	{
		perror("tests_writeReadGlobs fopen");
		return FALSE;
	}
	fclose(confFile);
	
	if(initConfigurator())
	{
		if(details)
			printf("\nThe configuration file is empty, first writing: Pass");
	}
	else
	{
		if(details)
			printf("\nThe configuration file is empty, first writing: Fail");
		testPassed = FALSE;
	}
	
	if(initConfigurator())
	{
		if(details)
			printf("\nThe configuration file has already been set, we just import variables: Pass");
	}
	else
	{
		if(details)
			printf("\nThe configuration file has already been set, we just import variables: Fail");
		testPassed = FALSE;
	}
	
	printf("\nThose values have been imported:");
	
	printf("\nglobs_maxPathLength: %d", globs_maxPathLength);
	printf("\nglobs_occurThreshold : %d", globs_occurThreshold);
	printf("\nglobs_maxTerms : %d", globs_maxTerms);
	printf("\nglobs_nbWeightyBits : %d", globs_nbWeightyBits);
	printf("\nglobs_compTolerance : %d", globs_compTolerance);
	printf("\nglobs_windowSize : %d", globs_windowSize);
	printf("\nglobs_nbInterval : %d", globs_nbInterval);
	printf("\nglobs_minFrequency : %f", globs_minFrequency);
	printf("\nglobs_maxFrequency : %f", globs_maxFrequency);
	printf("\nglobs_minWindowMatch: %f", globs_minWindowMatch);
	printf("\nglobs_minQuantifMatch: %f", globs_minQuantifMatch);
	
	
	return testPassed;
}
//===================================================================================================
Bool tests_enterGlobsVariables(Bool details)
{
	Bool testPassed = TRUE;
	FILE* confFile = fopen("testConf.conf", "wb+");
	if(confFile == NULL)
	{
		perror("tests_writeReadGlobs fopen");
		return FALSE;
	}
	
	printf("\nIn order to test enterGlobsVariables, please compare your inputs and the stored variables:");
	if(enterGlobsVariables(confFile))
	{
		if(details)
			printf("\nVariables are stored in a configuration file named testConf.conf");
	}
	else
	{
		if(details)
			printf("\nVariables are NOT stored in a configuration file");
		testPassed = FALSE;
	}	
	
	printf("\nThose values have been stored:");
	
	printf("\nglobs_maxPathLength: %d", globs_maxPathLength);
	printf("\nglobs_occurThreshold : %d", globs_occurThreshold);
	printf("\nglobs_maxTerms : %d", globs_maxTerms);
	printf("\nglobs_nbWeightyBits : %d", globs_nbWeightyBits);
	printf("\nglobs_compTolerance : %d", globs_compTolerance);
	printf("\nglobs_windowSize : %d", globs_windowSize);
	printf("\nglobs_nbInterval : %d", globs_nbInterval);
	printf("\nglobs_minFrequency : %f", globs_minFrequency);
	printf("\nglobs_maxFrequency : %f", globs_maxFrequency);
	printf("\nglobs_minWindowMatch: %f", globs_minWindowMatch);
	printf("\nglobs_minQuantifMatch: %f", globs_minQuantifMatch);
	
	return testPassed;
}
//===================================================================================================
Bool tests_writeReadGlobs(Bool details)
{
	Bool testPassed = TRUE;
	WritableGlobs globs = {10, 15,
				20, 25,
				0.35, -5.3,
				90, 2};
	FILE* file = fopen("testConf.conf", "wb+");
	if(file == NULL)
	{
		perror("tests_writeReadGlobs fopen");
		return FALSE;
	}
	
	if(!writeGlobs(&globs, file))
	{
		perror("tests_writeReadGlobs writeGlobs");
		return FALSE;
	}
	
	// Changing the global variables before reading the file just saved.
	globs_maxPathLength = 0;
	globs_occurThreshold = 0;
	globs_maxTerms = 0;
	globs_nbWeightyBits = 0;
	globs_compTolerance = 0;
	globs_windowSize = 0;
	globs_nbInterval = 0;
	globs_minFrequency = 0.0;
	globs_maxFrequency = 0.0;
	globs_minWindowMatch = 0.0;
	globs_minQuantifMatch = 0.0;
	
	rewind(file);
	
	if(!readGlobs(file))
	{
		perror("tests_readGlobs readGlobs");
		return FALSE;
	}
	
	// Let's test if the globals have been read correctly
	if(details)
		printf("\nglobs_maxPathLength: ");
	if(globs_maxPathLength != globs.listBaseDesc_maxPathLength)
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
		printf("\nglobs_occurThreshold: ");
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
		printf("\nglobs_maxTerms: ");
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
		printf("\nglobs_nbWeightyBits: ");
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
		printf("\nglobs_compTolerance: ");
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
	
	if(details)
		printf("\nglobs_windowSize: ");
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
		printf("\nglobs_nbInterval: ");
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
		printf("\nglobs_minFrequency: ");
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
		printf("\nglobs_maxFrequency: ");
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
		printf("\nglobs_minWindowMatch: ");
	if(globs_minWindowMatch != globs.soundDesc_minWindowMatch)
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
		printf("\nglobs_minQuantifMatch: ");
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
	
	
	
	return testPassed;
}
//===================================================================================================
Bool tests_setGlobsVariables(Bool details)
{
	Bool testPassed = TRUE;
	WritableGlobs globs = { 250,
				10,
				15,
				20,
				25,
				0.35,
				-5.3,
				90,
				2,
				2.3,
				13.5};
				
	setGlobsVariables(&globs);
	
	if(details)
		printf("\nInitialising globs_maxPathLength: ");
	if(globs_maxPathLength != globs.listBaseDesc_maxPathLength)
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
		printf("\nInitialising globs_occurThreshold: ");
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
		printf("\nInitialising globs_maxTerms: ");
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
		printf("\nInitialising globs_windowSize: ");
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
		printf("\nInitialising globs_nbInterval: ");
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
		printf("\nInitialising globs_minFrequency: ");
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
		printf("\nInitialising globs_maxFrequency: ");
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
		printf("\nInitialising globs_nbWeightyBits: ");
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
		printf("\nInitialising globs_compTolerance: ");
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
	
	if(details)
		printf("\nInitialising globs_minWindowMatch: ");
	if(globs_minWindowMatch != globs.soundDesc_minWindowMatch)
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
		printf("\nInitialising globs_minQuantifMatch: ");
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
	
	return testPassed;
}