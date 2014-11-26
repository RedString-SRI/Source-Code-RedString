
#ifndef CLEVAL
#define CLEVAL
	
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <errno.h>

	#define COPYLIMIT 100
	#define BOOLEAN int
	#define TRUE 1
	#define FALSE 0

	
	char* concat(char const * pFirstPart, char const * pSecondPart);
	/// Info: This function concatenates pFirstPart and pSecondPart.

	BOOLEAN copyFile(char const * pFileName, char const * pNewFileName);
	/// Info: This function copies the file pFileDescriptor in the current directory.
	///       It will be called pNewFileName

	BOOLEAN loadKeyValueParameters(char ** const pParam, int pNumParam, char * pKey[], char * pValue[]);
	/// Info: This function puts parameters (those given to the program) from pParam to pKey and pValue
	///       on condition that for each pKey, there is a pValue <(2n + 1 parameters).
	///       The function deletes the first and the second parameter (executable and configFile).
	///       It needs to have pKey and pValue already allocated (with a correct size...) before calling the function.

	int match_key (char const * line, char const * key);
	/// Info: This function compare pKey with the begining of pLine and test if it is equal.
	///       (Look at "Return" for exceptions)

	char* matchedLineKey (int pFileDescriptor, char const * pKey);
	/// Info: This function returns the line in pFileDescriptor which contains pKey

	char* matchedValueLine (char const * pLine);
	/// Info: This function returns the value (the line begining at the second word) of pLine

	char* read_fileWithWantedModification(char const * pPath, char ** const pKey, char ** const pValue);
	/// Info: This function returns the whole file (pFileDescriptor) with wanted modification in a string

	char* read_line (int pFileDescriptor);
	/// Info : This function returns the next line of pFileDescriptor
	
	BOOLEAN saveFile(char const * pPath, char const * pData);
	/// Info: This function save pData in pPath

	int stringLength(char const * pStr);
	/// Info: This function returns the length of pStr. (number of characters in the string)

#endif

