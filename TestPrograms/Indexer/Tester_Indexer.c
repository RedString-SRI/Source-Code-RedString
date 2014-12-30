/**
 * \file Tester_Indexer.c
 * \brief Tester of Indexer functions
 * \author Morgan Chabaud \n
 */


#include "FileManager.h"
#include "Indexer.h"
#include "Type_Bool.h"



Bool tests_foo(Bool details);

//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundDescriptor:\n");
	
	hasPassed = tests_foo(TRUE);
	if(hasPassed)
		printf("\n\t\tTests_createDescriptor: Success\n");
	else
		printf("\n\t\tTests_createDescriptor: Failure\n");

	printf("\tTester_End\n");
}

Bool tests_foo(Bool details)
{
	foo("dcdd", 3, 'd', 5, 4);
}
