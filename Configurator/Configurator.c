/**
 * \file Configurator.c
 * \brief A file configurator system
 * \author Morgan Chabaud \n
 */

#include "Configurator.h"

//===================================================================================================
Bool initConfigurator()
{
	FILE* confFile = fopen(CONF_FILE_NAME, "rb");
	if(confFile == NULL)
	{
		perror("initConfigurator fopen confFile");
		return FALSE;
	}
	
	// If it fits the size of an WritableGlobs, we'll consider it well written
	if(fileSize(confFile) == sizeof(WritableGlobs))
	{
		if(readGlobs(confFile))
			printf("\nConfiguration variables loaded successfully.");
		else
		{
			printf("\nAn error has occurred when loading the configuration file");
			return FALSE;
		}
	}
	else
	{
		fclose (confFile);
		// Open the configurator file in writing mode
		confFile = fopen(CONF_FILE_NAME, "wb+");
		if(confFile == NULL)
		{
			perror("initConfigurator fopen confFile");
			return FALSE;
		}
		
		printf("\nFirst you need to configure indexing parameters...");
		if(!enterGlobsVariables(confFile))
			printf("\nAn error has occurred while saving the configuration file");
		
		printf("\nIndexing parameters are now up-to-date");
	}
	
	fclose(confFile);
	return TRUE;
}
//===================================================================================================
Bool enterGlobsVariables(FILE* confFile)
{
	WritableGlobs globs;
	
	printf("\n\tText indexation :\n\t Enter the occurrence threshold for words : ");
	while(getKeyboard_Long(&globs.textDesc_occurThreshold, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\tEnter the maximum terms to keep for a file : ");
	while(getKeyboard_Long(&globs.textDesc_maxTerms, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\n\tPicture indexation :\n\tEnter the number of "
		"weighty bits to store for each pixel component : ");
	while(getKeyboard_Long(&globs.pictureDesc_nbWeightyBits, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\tEnter the comparison tolerance between two pixels : ");
	while(getKeyboard_Long(&globs.pictureDesc_compTolerance, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\n\tSound indexation : \n\tEnter the window Size : ");
	while(getKeyboard_Long(&globs.soundDesc_windowSize, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\tEnter the number of interval in a window : ");
	while(getKeyboard_Long(&globs.soundDesc_nbInterval, 0, INT_MAX) != 1)
		printf("\t\tPlease enter a value between %d and %d: ", 0, INT_MAX);
	
	printf("\tEnter the minimum frequency: ");
	while(getKeyboard_Double(&globs.soundDesc_minFrequency, -DBL_MAX, DBL_MAX) != 1)
		printf("\t\tPlease enter a value between %f and %f: ", -DBL_MAX, DBL_MAX);
			
	printf("\tEnter the maximum frequency: ");
	while(getKeyboard_Double(&globs.soundDesc_maxFrequency, globs.soundDesc_minFrequency, DBL_MAX) != 1
		|| globs.soundDesc_maxFrequency == globs.soundDesc_minFrequency)
		printf("\t\tPlease enter a value between %f (excluded) and %f: ", globs.soundDesc_minFrequency, DBL_MAX);

	return writeGlobs(&globs, confFile);
}
//===================================================================================================
void setGlobsVariables(WritableGlobs const * globs)
{
	// Needa to some tests there. For max or min values for example.
	globs_occurThreshold = globs->textDesc_occurThreshold;
	globs_maxTerms = globs->textDesc_maxTerms;
	globs_windowSize = globs->soundDesc_windowSize;
	globs_nbInterval = globs->soundDesc_nbInterval;
	globs_minFrequency = globs->soundDesc_minFrequency;
	globs_maxFrequency = globs->soundDesc_maxFrequency;
	globs_nbWeightyBits = globs->pictureDesc_nbWeightyBits;
	globs_compTolerance = globs->pictureDesc_compTolerance;
}
//===================================================================================================
Bool writeGlobs(WritableGlobs const * globs, FILE* confFile)
{
	if(!writeStruct(confFile, globs, sizeof(*globs)))
	{
/** Error Management **/
		return FALSE;
	}
	
	// Updating variables into global variables
	setGlobsVariables(globs);
	return TRUE;
}
//===================================================================================================
Bool readGlobs(FILE* confFile)
{
	WritableGlobs * globs = malloc(sizeof(*globs));

	if(!readStruct(confFile, globs, sizeof(*globs)))
	{
/** Error Management **/
		return FALSE;
	}
	
	// Updating variables into global variables
	setGlobsVariables(globs);
	
	return TRUE;
}
//===================================================================================================
Bool matchKey (char const * line, char const * key)
{
	Bool hasMatched = FALSE;
	int iLine, iKey;	// Increments

	// The function returns FALSE if line or key is NULL
	if(line != NULL && key != NULL)
	{
		// The function returns FALSE if line or key are empty
		if(line[0] == '\0' || key[0] == '\0')
		{
/** ErrorManagement **/
			return FALSE;
		}
		else
		{
			iLine = ignoreSpaces(line, 0);
			iKey = ignoreSpaces(key, 0);
			
			// Test each first characters of line and key until line == '\0' or key == '\0'
			//						   or line[iLine] != line[iLine]
			while(line[iLine] == key[iKey] && line[iLine] != '\0' && key[iKey] != '\0')
			{
				iLine++;
				iKey++;
			}
				
			// Test if the previous loop has ended with key's ending (so it matches)
			if(key[iKey] == '\0')
				hasMatched = TRUE;
			else
				hasMatched = FALSE;
		}
	}
	else
	{
/** ErrorManagement **/
		return FALSE;
	}

	return hasMatched;
}
//===================================================================================================
char* matchedLineKey(int fileDescriptor, char const * key)
{
	char *currentLine;
	Bool keyFound = FALSE;
	
	// Begining at the begining !
	lseek(fileDescriptor, 0, SEEK_SET);
	currentLine = readLine(fileDescriptor);
	// Test if key is at the begining of a line by testing each line until fileDescriptor "ends"
	// If the key is found in a line, the loop stops.
	while(currentLine[0] != '\0' && !keyFound)
	{	
		if(matchKey(currentLine, key))
			keyFound = TRUE;			
		else	// read the next line
			currentLine = readLine(fileDescriptor);
	}
	
	if(!keyFound)
		currentLine = NULL;
	
	return currentLine;
}
//===================================================================================================
char* matchedValueLine (char const * line, char separator)
{
	char* valueLine;
	int jValueLine, iLine;	// Increments
	int lineLen, valueLineLen;

	// Calculate the line's length to initialise valueLine at his maximum length.
	lineLen = 0;	
	while(line[lineLen] != '\0')
		lineLen++;
	lineLen++;	// Adds the size of '\0'


	// Goes over the first word
	iLine = 0;
	while(line[iLine] != ' ' && line[iLine] != '\0')
		iLine++;

	iLine = ignoreSpaces(line, iLine);
	// We want to remove the separator
	// If there is nothing, we are at the begining of the value.
	if(line[iLine] == separator)
	{
		iLine++;
		iLine = ignoreSpaces(line, iLine);
	}
	
	// Now let's copy the value into valueLine
	valueLineLen = lineLen - iLine;
	if(valueLineLen > 0)
	{
		valueLine = malloc(sizeof(char) * (lineLen - iLine));
		jValueLine = 0;
		while(line[iLine] != '\0')
			valueLine[jValueLine++] = line[iLine++];
		valueLine[jValueLine] = '\0';	// Make it a zero terminated string
	}
	else
	{
		// There is no value on this line
/** Error Management **/
		return NULL;
	}
	return valueLine;
}
//===================================================================================================
char* readLine (int fileDescriptor)
{
	char *line, character;
	int isEnding, length = 30;	// isEnding : returned int from read(...)
					// length : the returned line's length 
	int i;	// Increment

	

	i = 0;
	isEnding = read(fileDescriptor, &character, sizeof(char));

	// isEnding is higher than 0 if something has been copied in character
	if(isEnding > 0)
	{
		// line is allocated with an initial length, if it is not enough, it is going to be reallocated
		line = malloc(sizeof(*line) * length);
		
		// Test each character of fileDescriptor's current line until it find '\n'
		while(character != '\n' && isEnding > 0)
		{
			// If the initial length is not enough, it reallocates line
			if( i >= (length - 2))	// - 2 includes the '\0' at the string end
			{
				length += 5;
				line = realloc (line, length);
			}
			
			// Character by character, it copies fileDescriptor's current line in line
			line[i++] = character;
			isEnding = read (fileDescriptor, &character, sizeof(char));
		}
	
		// It secures the line's end with '\0'
		line[i] = '\0';
	}
	else
	{
		perror("readLine read");
		line = malloc(sizeof(char));
		line[0] = '\0';
	}

	return line;
}
//===================================================================================================
int ignoreSpaces(char const * str, int position)
{
	if(str == NULL)
	{
/** ErrorManagement **/
		return -1;
	}
	else if(position < 0)
	{
/** ErrorManagement **/
		return -1;
	}
	else
	{
		while(str[position] != '\n' && str[position] == ' ')
			position++;
	}
	return position;	
}
