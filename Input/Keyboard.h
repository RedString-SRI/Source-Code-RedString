/**
 * \file Keyboard.h
 * \brief Secured functions to interact with user
 * \author Morgan Chabaud \n
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/time.h> 
#include <errno.h>
#include <limits.h>
#include <float.h> // DBL_MAX

#ifndef KEYBOARD
#define KEYBOARD

#define DBL_MAX_STRLEN 40	// DBL_MAX is 1E+37, so it should be the size of a string like
				// "-12345...\0" : so 39 sould be the maximum
#define LONG_MAX_STRLEN 11	// 2,147,483,647

/**
 * \brief Allow the user to type a long
 * 
 * It allows the user to type typedLong. This function is
 * secured, the long must be within min and max. Otherwise,
 * the function returns an error. \n
 * The function returns errors in those following cases :\n
 * - A non digit (except the space not taken into account) is typed \n
 * - The user types too much digits \n
 * - The user does not type a digit but press 'Enter' \n
 * - The typed long is outside min or max
 * - An unknown error has occurred
 * \param typedLong Variable for the typed long. 0 is returned if an error has occurred.
 * \param min The minimum you want for typedLong (not inferior to LONG_MIN)
 * \param max The maximum you want for typedLong (not superior to LONG_MAX)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred (or an error from getKeyboard_String) \n
 * -1 : The typed long is outside min or max \n
 * -2 : The user does not type a digit but press 'Enter' \n
 * -3 : The user types too much digits \n
 * -4 : A non-digit (except the space) is typed \n
 */
int getKeyboard_Long(long * typedLong, long min, long max);

/**
 * \brief Allow the user to type a double
 * 
 * It allows the user to type typedDouble. This function is
 * secured, the double must be within min and max. Otherwise,
 * the function returns an error. \n
 * The function returns errors in those following cases :\n
 * - A non digit (except the space not taken into account) is typed \n
 * - The user types too much digits \n
 * - The user does not type a digit but press 'Enter' \n
 * - The typed double is outside min or max
 * - An unknown error has occurred
 * \param typedDouble Variable for the typed double. 0 is returned if an error has occurred.
 * \param min The minimum you want for typedDouble (not inferior to HUGE_VALL)
 * \param max The maximum you want for typedDouble (not superior to HUGE_VALF)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred (or an error from getKeyboard_String) \n
 * -1 : The user types a double superior to max \n
 * -2 : The user types a double inferior to min \n
 * -3 : The user does not type a digit but press 'Enter' \n
 * -4 : A non-digit (except the space) is typed \n
 */
int getKeyboard_Double(double * typedDouble, double min, double max);

/**
 * \brief Allow the user to type a string
 * 
 * It allows the user to type typedString. This function is
 * secured, the string must contains within minChar and maxChar characters
 * (this size must be inferior to (strlen(typedString)). \n
 * When allocating typedString, you must take in consideration an ending character '\n'
 * needed by fgets but the typedString won't be returned with it.
 * Otherwise the function returns an error. \n
 * The function returns errors in those following cases :\n
 * - The user types too much characters \n
 * - The user types not enough characters \n
 * - An unknown error has occurred
 * \param typedString Variable for the typed double
 * \param minChar The minimum you want for typedString (not inferior to 0 and not superior to maxChar)
 * \param maxChar The maximum you want for typedString (not inferior or equal to minChar)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred \n
 * -1 : The user types too much characters \n
 * -2 : The user types not enough characters \n
 */
int getKeyboard_String(char * typedString, int minChar, int maxChar);

/**
 * \brief Empty stdin
 * 
 * Empty the stdin buffer with getchar method.
 * WATCH OUT : If stdin is already empty, the function will pause
 * 		the program waiting for a character from the user
 */
void emptyStdin();


#endif