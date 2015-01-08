/**
 * \file Tester_SoundSearch.c
 * \brief Tester of SoundSearch functions
 * \author Morgan Chabaud \n
 */

#include "Type_Bool.h"

Bool tests_setGlobsVariables(Bool details);


//===================================================================================================
int main()
{
	Bool hasPassed;

	printf("\n\n\n\n\tTester_SoundSearch:\n");
	
	hasPassed = tests_setGlobsVariables(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_setGlobsVariables: Success\n");
	else
		printf("\n\t\tTests_setGlobsVariables: Failure\n");
	

	printf("\tTester_End\n");
}
