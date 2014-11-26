/* Test :		// test is the config file
Prompt : more test
cle1 valeur1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono


Prompt : ./prog
You should give parameter(s) as : ./program [configFile] [key] ([value] [value] [key] [value]...)


Prompt : ./prog test
You should give parameter(s) as : ./program [configFile] [key] ([value] [value] [key] [value]...)


Prompt : ./prog test cle1
valeur1


Prompt : ./prog test cle1 NEWval1
Copy saved succesfully as "newtest".
Your modified file has been saved successfully. A copy of the former one has been created.


Prompt : more test
cle1 NEWval1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono


Prompt : more newtest
cle1 valeur1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono


Prompt : ./prog test cle2 NEWval2 cleSANSVAL
You need to have one value for each key : Pairs(key; value)


Prompt : more test
cle1 NEWval1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono

Prompt : ./prog test cle1 last1 cle3 lastVal3 cle4 aValue cle6 yesyes cle8 invisible
"newtest" already exists. It is going to be saved as "newtest(0)".
Copy saved succesfully as "newtest(0)".
Your modified file has been saved successfully. A copy of the former one has been created.


Prompt : more test
cle1 last1
cle2 valeur2
cle3 lastVal3
cle4 aValue
cle5 "Jacky chan is invisible"
cle6 yesyes


Prompt : more newtest
cle1 valeur1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono


Prompt : more newtest\(0\)
cle1 NEWval1
cle2 valeur2
cle3 valeur3 ou 3
cle4
cle5 "Jacky chan is invisible"
cle6 nono


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "cleval.h"

/**
NOTE : match_key uses const parameters. So, if you want to test it with test_match_key.c,
       it needs to delete "const" (on parameters) for match_key and matchedLineKey functions
*/


/**
	Usage : ./program [configFile] [key] ([value] [value] [key] [value]...)
*/
int main (int argc, char *argv[])
{
	char **key, **value;	// They are initialised in the function loadKeyValueParameters
	int file;
	char *retLine, *strFileToSave;
	int i;	// Increment

	// Test if there is at least one parameter (the file path)
	if(argc >= 2)
		file = open(argv[1], O_RDONLY);
	
	if(file != -1)
	{
		switch(argc)	// argc can't be inferior or equal to 0
		{
			case 1:
				printf("You should give parameter(s) as : ./program [configFile] [key] ([value] [value] [key] [value]...)");
				break;
			case 2:
				printf("You should give parameter(s) as : ./program [configFile] [key] ([value] [value] [key] [value]...)");
				break;
			case 3:
				retLine = matchedLineKey(file, argv[2]);
				if(retLine[0] != '\0')
					printf("%s\n", matchedValueLine(retLine));
				else
					printf("The key has not been found");
	
				free(retLine);
				break;
	
			default:	// n > 3
				// Allocating the arrays for loadKeyValueParamters(...)
				// When we reach the c function limits.... a non-const pointer given in parameter...No realloc of it allowed in the function...
				key = malloc(sizeof(char*) * ((argc - 2) / 2 + 1));	// +1 include the last NULL entry);
				value = malloc(sizeof(char*) * ((argc - 2) / 2 + 1));	// +1 include the last NULL entry);

				if(!loadKeyValueParameters(argv, argc, key, value))
					printf("\nYou need to have one value for each key : Pairs(key; value)");
				else
				{	
					if(copyFile(argv[1], concat("new", argv[1])))
					{
						strFileToSave = read_fileWithWantedModification(argv[1], key, value);
						// Break the link between the new file and the former one
						unlink(argv[1]);

						if(saveFile(argv[1], strFileToSave))
							printf("\nYour modified file has been saved successfully. A copy of the former one has been created.");
						else
							printf("\nAn error has been encountered to save your modified file");
						
						// Free key[i] and value[i]
						// The last element of key and value is a NULL value
						i = 0;
						while(key[i] != NULL)
							free(key[i++]);
						i = 0;
						while(value[i] != NULL)
							free(value[i++]);
	
						free(strFileToSave);
					}
					else
						printf("\nAn error has been encountered when it tried to save a copy of your file.\n"
							"You may have not appropriate rights.");
				}
				
				// Free the remaining pointers
				free(value);
				free(key);
				break;
		}
		close(file);
	}
	else
		perror("Error opening the file");

	printf("\n");
	return 0;
}
