/**
 * \file Tester_Keyboard.c
 * \brief Tester of Keyboard functions
 * \author Morgan Chabaud \n
 */


#include "Keyboard.h"
#include "FileManager.h"
#include "Type_Bool.h"

int main()
{
	int i;
		char string[80], str[80];
		printf("enter an integer:\n");
		getKeyboard_String(str, 0, 10);
		printf("enter a string:\n");
		getKeyboard_String(string, 0, 10);
		printf("You typed %s and \"%s\"\n", str, string);
		return 0;
}