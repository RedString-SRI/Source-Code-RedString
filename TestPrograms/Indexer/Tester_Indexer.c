/**
 * \file Tester_Indexer.c
 * \brief Tester of Indexer functions
 * \author Morgan Chabaud \n
 */


#include "FileManager.h"
#include "Indexer.h"
#include "Type_Bool.h"



Bool tests_foo(Bool details);
Bool tests_updateIndexableFile(Bool details);
Bool tests_indexFiles(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_Indexer:\n");
	
	hasPassed = tests_updateIndexableFile(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_updateIndexableFile: Success\n");
	else
		printf("\n\t\tTests_updateIndexableFile: Failure\n");

	hasPassed = tests_indexFiles(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_indexFiles: Success\n");
	else
		printf("\n\t\tTests_indexFiles: Failure\n");
	
	printf("\tTester_End\n");
}
//===================================================================================================
Bool tests_foo(Bool details)
{
	foo("dcdd", 3, 'd', 5, 4);
}
//===================================================================================================
Bool tests_updateIndexableFile(Bool details)
{
	PathStacks pathStack;	// Contains the path
				// of ready-to-be-indexed files
	
	// Initialise pathStack
	initStack(&pathStack.soundPathStack.pathFile);
	pathStack.soundPathStack.fileType = SOUND;
	
	
	updateIndexableFile("../../..", &pathStack);
	while(!stackIsEmpty(pathStack.soundPathStack.pathFile))
	{
		printf("\n.. : %s", unstack(&pathStack.soundPathStack.pathFile));
	}
}

Bool tests_indexFiles(Bool details)
{
	PathStacks pathStack;	// Contains the path
				// of ready-to-be-indexed files
	
	// Initialise pathStack
	initStack(&pathStack.soundPathStack.pathFile);
	pathStack.soundPathStack.fileType = SOUND;
	
	
	updateIndexableFile("../../..", &pathStack);
	indexFiles(&pathStack.soundPathStack);
}
