/**
 * \file Tester_Keyboard.c
 * \brief Tester of Keyboard functions
 * \author Morgan Chabaud \n
 */


#include "Keyboard.h"
#include "FileManager.h"
#include "Type_Bool.h"


Bool tests_getKeyboard_Long(Bool);
Bool tests_getKeyboard_Double(Bool);
Bool tests_getKeyboard_String(Bool);

int main()
{
	Bool hasPassed;
	
	printf("\n\n\n\n\tTester_Keyboard (Interactive tests):\n");
	
	hasPassed = tests_getKeyboard_String(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_getKeyboard_String: Success\n");
	else
		printf("\n\t\tTests_getKeyboard_String: Failure\n");
	
	hasPassed = tests_getKeyboard_Double(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_getKeyboard_Double (depends on getKeyboard_String): Success\n");
	else
		printf("\n\t\tTests_getKeyboard_Double (depends on getKeyboard_String): Failure\n");
	
	hasPassed = tests_getKeyboard_Long(FALSE);
	if(hasPassed)
		printf("\n\t\tTests_getKeyboard_Long (depends on getKeyboard_String): Success\n");
	else
		printf("\n\t\tTests_getKeyboard_Long (depends on getKeyboard_String): Failure\n");
	
	printf("\tTester_End\n");
}

Bool tests_getKeyboard_Long(Bool details)
{
	Bool testPassed = TRUE;
	long aLong;
	
	// User types nothing
	printf("\nPlease type the string \"\\n\"");
	if(details)
		printf("\nThe user types nothing: ");
	if(getKeyboard_Long(&aLong, 0, 20) == 0)
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
	
	// User types under the minimum
	printf("\nPlease type the string \"9\\n\"");
	if(details)
		printf("\nThe user types under the minimum: ");
	if(getKeyboard_Long(&aLong, 10, 20) == -2)
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
	
	// User types over the maximum
	printf("\nPlease type the string \"21\\n\"");
	if(details)
		printf("\nThe user types over the maximum: ");
	if(getKeyboard_Long(&aLong, 10, 20) == -1)
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
	
	// User types a long between min and max
	printf("\nPlease type the string \"15\\n\"");
	if(details)
		printf("\nThe user types a long between min and max: ");
	if(getKeyboard_Long(&aLong, 10, 20) == 1)
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
	
	// User types the min
	printf("\nPlease type the string \"10\\n\"");
	if(details)
		printf("\nThe user types the min: ");
	if(getKeyboard_Long(&aLong, 10, 20) == 1)
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
	
	// User types the max
	printf("\nPlease type the string \"20\\n\"");
	if(details)
		printf("\nThe user types the max: ");
	if(getKeyboard_Long(&aLong, 10, 20) == 1)
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
	
	// User types some letters before
	printf("\nPlease type the string \"Want 15\\n\"");
	if(details)
		printf("\nThe user types some letters before: ");
	if(getKeyboard_Long(&aLong, 10, 20) == -4)
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
	
	// User types some letters after
	printf("\nPlease type the string \"15 Good\\n\"");
	if(details)
		printf("\nThe user types some letters after: ");
	if(getKeyboard_Long(&aLong, 10, 20) == -4)
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
	
	// User types no digits
	printf("\nPlease type the string \"Forty\\n\"");
	if(details)
		printf("\nThe user types no digits: ");
	if(getKeyboard_Long(&aLong, 10, 20) == -4)
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
	
	// User types something that returns an error from getKeyboard_String
	printf("\nPlease type the string \"I want to do something you don't want to\\n\"");
	if(details)
		printf("\nThe user types something that returns an error from getKeyboard_String: ");
	if(getKeyboard_Long(&aLong, 10, 20) == 0)
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

Bool tests_getKeyboard_Double(Bool details)
{
	Bool testPassed = TRUE;
	double aDouble;
	
	// User types nothing
	printf("\nPlease type the string \"\\n\"");
	if(details)
		printf("\nThe user types nothing: ");
	if(getKeyboard_Double(&aDouble, 0, 20) == 0)
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
	
	// User types under the minimum
	printf("\nPlease type the string \"9\\n\"");
	if(details)
		printf("\nThe user types under the minimum: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == -2)
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
	
	// User types over the maximum
	printf("\nPlease type the string \"21\\n\"");
	if(details)
		printf("\nThe user types over the maximum: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == -1)
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
	
	// User types a double between min and max
	printf("\nPlease type the string \"15\\n\"");
	if(details)
		printf("\nThe user types a double between min and max: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == 1)
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
	
	// User types the min
	printf("\nPlease type the string \"10\\n\"");
	if(details)
		printf("\nThe user types the min: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == 1)
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
	
	// User types the max
	printf("\nPlease type the string \"20\\n\"");
	if(details)
		printf("\nThe user types the max: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == 1)
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
	
	// User types some letters before
	printf("\nPlease type the string \"I want 15\\n\"");
	if(details)
		printf("\nThe user types some letters before: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == -4)
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
	
	// User types some letters after
	printf("\nPlease type the string \"15 is good\\n\"");
	if(details)
		printf("\nThe user types some letters after: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == -4)
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
	
	// User types no digits
	printf("\nPlease type the string \"Forty\\n\"");
	if(details)
		printf("\nThe user types no digits: ");
	if(getKeyboard_Double(&aDouble, 10, 20) == -4)
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

Bool tests_getKeyboard_String(Bool details)
{
	Bool testPassed = TRUE;
	const int arrSize = 11;
	char str[arrSize];
	
	// User types nothing
	printf("\nPlease type the string \"\\n\"");
	if(details)
		printf("\nThe user types nothing: ");
	if(getKeyboard_String(str, 1, arrSize - 1) == -2)
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
	
	// User does not type enough characters
	printf("\nPlease type the string \"writti\\n\"");
	if(details)
		printf("\nThe user does not type enough characters: ");
	if(getKeyboard_String(str, 8, arrSize - 1) == -2)
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
	
	// User does type too much characters
	printf("\nPlease type the string \"writting too much\\n\"");
	if(details)
		printf("\nThe user does type too much characters: ");
	if(getKeyboard_String(str, 8, arrSize - 1) == -1)
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
	
	// User types min characters
	printf("\nPlease type the string \"enough\\n\"");
	if(details)
		printf("\nThe user types min characters: ");
	if(getKeyboard_String(str, 6, arrSize - 1) == 1)
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
	
	// User types max characters
	printf("\nPlease type the string \"enoughCh_\\n\"");
	if(details)
		printf("\nThe user types max characters: ");
	if(getKeyboard_String(str, arrSize - 2, arrSize) == 1)
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
