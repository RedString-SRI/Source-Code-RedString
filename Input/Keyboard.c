/**
 * \file Keyboard.h
 * \brief Secured functions to interact with user
 * \author Morgan Chabaud \n
 */

#include "Keyboard.h"

int getKeyboard_Long(long * typedLong, long min, long max)
{
	char *retStrtol;
	char strLong[LONG_MAX_STRLEN];
	long value;	// The value of the string written by the user
	
	*typedLong = 0;	// If errors occur, it will be that value
	
	switch(getKeyboard_String(strLong, 1, LONG_MAX_STRLEN))
	{
		case 1:
			break;
		
		default:
			return 0;
	}		
	
	errno = 0;
	value = strtol(strLong, &retStrtol, 10);
	if(retStrtol != NULL && retStrtol[0] != '\0')	// The user hasn't typed digits only
	{
		if(errno == ERANGE)
		{
			perror("getKeyboard_Long strtol");
			return 1;
		}
		// else (retStrtol == strLong) or (retStrtol[0] >= '0' && retStrtol[0] <= '9')
		return -4;
	}
	
	// Test long value
	if(value < min)
		return -2;
	if(value > max)
		return -1;
	
	*typedLong = value;
	return 1;
}

int getKeyboard_Double(double * typedDouble, double min, double max)
{
	char *retStrtod;
	char strDouble[DBL_MAX_STRLEN];
	double value;	// The value of the string written by the user
	
	*typedDouble = 0;	// If errors occur, it will be that value
	
	switch(getKeyboard_String(strDouble, 1, DBL_MAX_STRLEN))
	{
		case 1:
			break;
		
		default:
			return 0;
	}		
	
	errno = 0;
	value = strtod(strDouble, &retStrtod);
	if(retStrtod != NULL && retStrtod[0] != '\0')	// The user hasn't typed digits only
	{
		if(errno == ERANGE)
		{
			perror("getKeyboard_Double strtod");
			return 1;
		}
		// else (retStrtod == strDouble) or (retStrtod[0] >= '0' && retStrtod[0] <= '9')
		return -4;
	}
	
	// Test double value
	if(value < min)
		return -2;
	if(value > max)
		return -1;
	
	*typedDouble = value;
	return 1;
}

int getKeyboard_String(char * typedString, int minChar, int maxChar)
{
	size_t typedStrLen;
	char * ptrNewLineChar;
	
	if(fgets(typedString, maxChar, stdin) == NULL)
	{
		perror("getKeyboard_String fgets");
		return 0;
	}
	
	//Removing the '\n' kept by fgets
	ptrNewLineChar = strchr(typedString, '\n');
	if(ptrNewLineChar != NULL)
		*ptrNewLineChar = '\0';
	else
	{
		// No '\0' has been found.... meaning that some characters were left in stdin
		emptyStdin();
		return -1;
	}
	
	// Test string length
	typedStrLen = strlen(typedString);
	if(typedStrLen < minChar)
		return -2;
	
	return 1;	
}

void emptyStdin()
{
	int c = 0;
	while((c = getchar()) != '\n' && c != EOF);
}
