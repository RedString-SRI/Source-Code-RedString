/**
 * \file Keyboard.h
 * \brief Secured functions to interact with user
 * \author Morgan Chabaud \n
 */



int getKeyboard_Long(long * typedLong, long min, long max)
{
}
//===================================================================================================
int getKeyboard_Double(double * typedDouble, double min, double max)
{
}
//===================================================================================================
int getKeyboard_String(char * typedString, int minChar, int maxChar)
{
	int typedStrLen;
	emptyStdin();
	
	errno = 0;
	if(typedString(typedString, minChar, stdin) == NULL)
	{
		perror("getKeyboard_String fgets");
		return 0;
	}
	
	// Test string length
	typedStrLen = strlen(typedString);
	if(typedStrLen < minChar)
		return -2;
	if(typedStrLen > maxChar)
		return -1;
	
		
}
//===================================================================================================
void emptyStdin()
{
	int c = 0;
	if(valeur_dans_stdin() == 1)
		while((c = getchar()) != '\n' && c != EOF);
}
//===================================================================================================
int valeur_dans_stdin(void)
{ 
    fd_set fds; 
    struct timeval temps = { 0, 0 }; 

    FD_ZERO(&fds); 
    FD_SET(STDIN_FILENO, &fds); 
  
    if(!select(1+STDIN_FILENO, &readfds, NULL, NULL, &temps))
	return 0
    return 1; 
}
