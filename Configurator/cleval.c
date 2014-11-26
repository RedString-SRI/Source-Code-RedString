
#include "cleval.h"

/**
	Sign: char* concat(char const * pFirstPart, char const * pSecondPart)

	Info: This function concatenates pFirstPart and pSecondPart.
	Input : char const * : pFirstPart
		char const * : pSecondPart
	Output : -
	Return: char* : The concatenated string

	Note: -
*/
char* concat(char const * pFirstPart, char const * pSecondPart)
{
	char* concatPart;
	int lengthFirstPart, lengthSecondPart;	// Used to calculate the lengths of parameters
	int i;	// Increment

	// pFirstPart length:
	lengthFirstPart = stringLength(pFirstPart);

	// pSecondPart length:
	lengthSecondPart = stringLength(pSecondPart);

	concatPart = malloc(sizeof(char) * (lengthFirstPart + lengthSecondPart + 1));	// +1 for '\0'

	for(i = 0; i < lengthFirstPart; i++)
		concatPart[i] = pFirstPart[i];

	for(i = lengthFirstPart; i < (lengthSecondPart + lengthFirstPart); i++)
		concatPart[i] = pSecondPart[i - lengthFirstPart];

	concatPart[i] = '\0';

	return concatPart;
}


/**
	Sign: BOOLEAN copyFile(int pFileDescriptor, char const * pNewFileName)

	Info: This function copies the file pFileDescriptor in the current directory.
		It will be called pNewFileName
	Input : int : pFileDescriptor
		char const * : pNewFileName
	Output : -
	Return: BOOLEAN : TRUE : The file has been copied successfully
			  FALSE : An error has been encountered.
				  The file has not been copied.

	Note: The given pNewFileName must not already exist (the function tries to rename it 100 times like "name(i)")
	      and the file associated with pFileDescriptor must be opened in reading
*/
BOOLEAN copyFile(char const * pFileName, char const * pNewFileName)
{
	BOOLEAN success = FALSE;
	char* newFileName;	// We can use pNewFileName because we want to modify it if the file already exists
	char* extName = malloc(sizeof(char) * 4);
	int newFileNameLength, i = 0;	// i : value is used for the file extension number


	newFileNameLength = stringLength(pNewFileName) + 3;	// +3 includes extName.
	newFileName = malloc(sizeof(char) * newFileNameLength);
	// Copy pNewFileName into newFileName using concat with an empty string
	newFileName = concat("", pNewFileName);

	while(i < COPYLIMIT && !success)
	{
		// Test if the file has been copied successfully or if it already exists or there is another error
		if(link(pFileName, newFileName) == 0)
		{
			printf("\nCopy saved succesfully as \"%s\".", newFileName);
			success = TRUE;
		}
		else if(errno == EEXIST)
		{
			// Change name of the file until. Try to change it 100 times until it gives up.
			printf("\n\"%s\" already exists. It is going to be saved as \"%s(%d)\".", newFileName, pNewFileName, i);

			// Adjusting i value in extName
			sprintf(extName, "(%d)", i);
			if(i == 0)
				newFileName = concat(newFileName, extName);
			else
				newFileName[newFileNameLength - 2] = extName[1];
			
			// Increase the extension increment for the next test
			// (if there is still an error after the previous modification) ... until i == 100
			i++;
		}
		else
		{
			success = FALSE;
			i = 100; // Exiting the loop
			//perror("Saving copy problem :N");
		}
	}

	free(newFileName);
	free(extName);
	return success;
}


/**
	Sign: BOOLEAN loadKeyValueParameters(char const * pParam[], int pNumParam, char * pKey[], char * pValue[])

	Info: This function puts parameters (those given to the program) from pParam to pKey and pValue
	      on condition that for each pKey, there is a pValue <(2n + 1 parameters).
	      The function deletes the first and the second parameter (executable and configFile).
	      It needs to have pKey and pValue already allocated (with a correct size...) before calling the function.
	Input : char const ** : pParam
	Output : char ** : pKey (NEEDS to be allocated before calling the function) : NULL if FALSE is returned
		 char ** : pValue (NEEDS to be allocated before calling the function) : NULL if FALSE is returned
	Return: BOOLEAN : TRUE : Parameters have been loaded successfully
				 (There is at least one couple pKey, pValue)
			  FALSE : Either there is no parameter (key and value) or a problem has been encountered

	Note: 	Pointers pKey and pValue needs to be allocated at the correct size before the function
		The arrays pKey and pValue are ended with a NULL value
*/
BOOLEAN loadKeyValueParameters(char ** const pParam, int pNumParam, char * pKey[], char * pValue[])
{
	BOOLEAN success;
	int numParam, tmpLgthParam;	// numParam is the number parameter (key, value) there is. key value -> numParam = 2
					// tmpLgthParam is used when parameters are copied
	int keyI, valueI;	// Increments for pKey and pValue
	int i, j;	// Increments


	// If the condition is not verified, success = FALSE
	success = FALSE;
	if(pNumParam%2 == 0)
	{
		i = 0;
		numParam = (pNumParam - 2);

		for(i = keyI = valueI = 0; i < numParam; i++, keyI++, valueI++)
		{
			// pKey
			tmpLgthParam = stringLength(pParam[i + 2]);
			pKey[keyI] = malloc(sizeof(char) * (tmpLgthParam + 1));	// +1 includes the '\0' character
			// Copy the parameter string into pKey[keyI] (Usefull because there is not a '\0' end to copy it fastly)
			for(j = 0; j < tmpLgthParam; j++)
				pKey[keyI][j] = pParam[i + 2][j];

			pKey[keyI][j] = '\0'; 

			// pValue
			i++;
			tmpLgthParam = stringLength(pParam[i + 2]);
			pValue[valueI] = malloc(sizeof(char) * (tmpLgthParam + 1));	// +1 includes the '\0' character
			// Copy the parameter string into pValue[valueI] (Usefull because there is not a '\0' end to copy it fastly)
			
			for(j = 0; j < tmpLgthParam; j++)
				pValue[valueI][j] = pParam[i + 2][j];

			pValue[valueI][j] = '\0'; 
			//*pValue[valueI] = *pParam[i + 2];
		}	
		// End pValue and pKey arrays with a NULL value
		pKey[keyI] = NULL;
		pValue[valueI] = NULL;

		success = TRUE;
	}

	return success;
}


/**
	Sign: int match_key (char const * pLine, char const * pKey)

	Info: This function compare pKey with the begining of pLine and test if it is equal.
	      (Look at "Return" for exceptions)
	Input : char const * : pLine
		char const * : pKey
	Output : - 
	Return: int : 1 : pKey is at the begining of pLine
			  pLine[0] == '\0' && pKey[0] == '\0'

		      0 : pKey is NOT at the begining of pLine
			  pLine == NULL
			  pKey == NULL
			  pKey[0] == '\0'

	Note: Signature of this function does not use BOOLEAN for return type
	       but it uses it in his definition
	       TRUE == 1
	       FALSE == 0
*/
int match_key (char const * pLine, char const * pKey)
{
	BOOLEAN hasMatched = FALSE;
	int i;	// Increment

	// The function returns FALSE if pLine or pKey is NULL
	if(pLine != NULL && pKey != NULL)
	{
		// The function returns TRUE if pLine and pKey are empty
		if(pLine[0] == '\0' && pKey[0] == '\0')
			hasMatched = TRUE;
		else
		{
			i = 0;
			// Test each first characters of pLine and pKey until pLine == '\0'
			//						   or pLine[i] != pLine[i]
			while(pLine[i] == pKey[i] && pLine[i] != '\0')
				i++;
			
			// Test if the previous loop has ended with pKey's ending (so it matches)
			if(pKey[i] == '\0')
				hasMatched = TRUE;
		}
	}

	return hasMatched;
}


/**
	Sign: char* matchedLineKey (int pFileDescriptor, char const * pKey)

	Info: This function returns the line in pFileDescriptor which contains pKey
	Input : int : pFileDescriptor
		 char const * : pKey
	Output : -
	Return: char* : The line where pKey has been found
			NULL : There is no line in pFileDescriptor which contains pKey at the begining 

	Note: -
*/
char* matchedLineKey (int pFileDescriptor, char const * pKey)
{
	char *currentLine, *matchingLine;
	BOOLEAN keyFound = FALSE;
	
	currentLine = read_line(pFileDescriptor);
	// Test if pKey is at the begining of a line by testing each line until pFileDescriptor "ends"
	// If the key is found in a line, the loop stops.
	while(currentLine[0] != '\0' && !keyFound)
	{	
		// Copies currentLine into matchingLine if the key is found.
		// (by making a copy of pointers)
		if(match_key (currentLine, pKey))
		{
			matchingLine = currentLine;
			keyFound = TRUE;			
		}
		
		// read the next line
		currentLine = read_line (pFileDescriptor);
	}
	
	if(!keyFound)
		matchingLine = NULL;
	
	free(currentLine);
	return matchingLine;
}


/**
	Sign: char* matchedValueLine (char const * pLine)

	Info: This function returns the value (the line begining at the second word) of pLine
	Input : char const * : pLine
	Output : - 
	Return: char* : The value of pLine
			"" : Nothing if there is no word after the first one

	Note: pLine must contain at least a character
*/
char* matchedValueLine (char const * pLine)
{
	char* valueLine;
	int j, i;	// Increments. j for valueLine and i for pLine
	int lengthPLine;

	// Calculate the pLine's length for initialising valueLine at his maximum length.
	lengthPLine = 0;	
	while(pLine[lengthPLine] != '\0')
		lengthPLine++;
	lengthPLine++;	// Adds the size of '\0'

	// Copy pLine in valueLine
	valueLine = malloc(sizeof(char) * lengthPLine);

	i = 0;
	while(pLine[i] != ' ' && pLine[i] != '\0')
		i++;

	i++;	// We want to remove the white space which was at the previous pLine[i]
	// Adjusting the valueLine's length
	valueLine = realloc(valueLine, (lengthPLine - i));

	j = 0;	// Increment for valueLine
	while(pLine[i] != '\0')
		valueLine[j++] = pLine[i++];
	valueLine[j] = '\0';	// Make it a ZTS

	return valueLine;
}


/**
	Sign: char* read_fileWithWantedModification(char const * pPath, char ** const pKey, char ** const pValue)

	Info: This function returns the whole file (pFileDescriptor) with wanted modification in a string
	Input : int : pFileDescriptor
	Output : - 
	Return: char* : the whole file (selected by pFileDescriptor)

	Note: A function shouldn't do two things in a row but it is done to increase performances
*/
char* read_fileWithWantedModification(char const * pPath, char ** const pKey, char ** const pValue)
{
	int file = open(concat("./", pPath), O_RDONLY);
	char *tmpStr, *fileStr;
	int fileStrLength = 1;	// At the begining	
	int i;	// Increment
	
	if(file == -1)
		perror("Reeding error of the given file");

	fileStr = malloc(sizeof(char) * fileStrLength);	
	fileStr[0] = '\0';	// To be well interpreted by concat 

	tmpStr = read_line(file);
	while(tmpStr[0] != '\0' && file != -1)
	{
		// Check if a key matches this line and replace it if it's the case
		i = 0;
		while(pKey[i] != NULL)
		{
			if(match_key(tmpStr, pKey[i]))
				tmpStr = concat(concat(pKey[i], " "), pValue[i]);
			i++;
		}

		// Re-calculate the length
		fileStrLength += stringLength(tmpStr);
		fileStr = realloc(fileStr, fileStrLength);
		tmpStr = concat(tmpStr, "\n");	// tmpStr is a line
		fileStr = concat(fileStr, tmpStr);

		//Put the next line into tmpStr
		tmpStr = read_line(file);
	}

	free(tmpStr);
	close(file);
	return fileStr;
}


/**
	Sign: char* read_line (int pFileDescriptor)

	Info: This function returns the next line of pFileDescriptor
	Input : int : pFileDescriptor
	Output : - 
	Return: char* : The next line of pFileDescriptor
			NULL : Nothing is found by read(...) on the first current character

	Note: -
*/
char* read_line (int pFileDescriptor)
{
	char *line, character;
	int isEnding, length = 20;	// isEnding : returned int from read(...)
					// length : the returned line's length 
	int i;	// Increment

	// line is allocated with an initial length, if it is not enough, it is going to be reallocated
	line = malloc(sizeof(char) * length);

	i = 0;
	isEnding = read (pFileDescriptor, &character, sizeof(char));

	// isEnding is higher than 0 if something has been copied in character
	if(isEnding > 0)
	{
		// Test each character of pFileDescriptor's current line until it find '\n'
		while(character != '\n' && isEnding > 0)
		{
			// If the initial length is not enough, it reallocates line
			if( i >= (length - 1))
			{
				length += 5;
				line = realloc (line, length);
			}
			
			// Character by character, it copies pFileDescriptor's current line in line
			line[i++] = character;
			isEnding = read (pFileDescriptor, &character, sizeof(char));
		}
	
		// It secures the line's end with '\0'
		line[i] = '\0';
	}
	else
	{
		//perror("Reed problem");
		line = realloc(line, sizeof(char));
		line[0] = '\0';
	}

	return line;
}


/**
	Sign: int saveFile(char const * pPath, char const * pData)

	Info: This function save pData in pPath
	Input : char const ** : pParam
	Output : char ** : pKey (NEEDS to be allocated before calling the function) : NULL if FALSE is returned
		 char ** : pValue (NEEDS to be allocated before calling the function) : NULL if FALSE is returned
	Return: BOOLEAN : TRUE : Parameters have been loaded successfully
				 (There is at least one couple pKey, pValue)
			  FALSE : Either there is no parameter (key and value) or a problem has been encountered

	Note: 	Pointers pKey and pValue needs to be allocated at the correct size before the function
		The arrays pKey and pValue are ended with a NULL value
*/
BOOLEAN saveFile(char const * pPath, char const * pData)
{
	FILE *file = fopen(pPath, "w+");
	BOOLEAN saved = FALSE;

	if(file != NULL)
	{
		if(fputs(pData, file) != EOF)
			saved = TRUE;
		fclose(file);
	}

	return saved;
}


/**
	Sign: int stringLength(char const * pStr)

	Info: This function returns the length of pStr. (number of characters in the string)
	Input : char const * : pStr
	Output : -
	Return: int : The string length

	Note: The length does not include the '\0' for the ZTS 
*/
int stringLength(char const * pStr)
{
	int length = 0;
	while(pStr[length] != '\0')
		length++;
	return length;
}
