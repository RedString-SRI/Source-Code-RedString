/**
 * \file Keyboard.h
 * \brief Secured functions to interact with user
 * \author Morgan Chabaud \n
 */

#include <stdlib.h>

#ifndef KEYBOARD
#define KEYBOARD

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
 * \param typedLong Variable for the typed long
 * \param min The minimum you want for typedLong (not lesser than LONG_MIN)
 * \param max The maximum you want for typedLong (not higher than LONG_MAX)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred \n
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
 * \param typedDouble Variable for the typed double
 * \param min The minimum you want for typedDouble (not lesser than HUGE_VALL)
 * \param max The maximum you want for typedDouble (not higher than HUGE_VALF)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred \n
 * -1 : The typed double is outside min or max \n
 * -2 : The user does not type a digit but press 'Enter' \n
 * -3 : The user types too much digits \n
 * -4 : A non-digit (except the space) is typed \n
 */
int getKeyboard_Double(double * typedDouble, double min, double max);

/**
 * \brief Allow the user to type a string
 * 
 * It allows the user to type typedString. This function is
 * secured, the string must contains within minChar and maxChar characters. \n
 * Otherwise the function returns an error. \n
 * The function returns errors in those following cases :\n
 * - The user types too much characters \n
 * - The user types not enough characters \n
 * - The user does not type a character but press 'Enter' \n
 * - An unknown error has occurred
 * \param typedString Variable for the typed double
 * \param minChar The minimum you want for typedString (not lesser than 0)
 * \param maxChar The maximum you want for typedString (not lesser or equal than minimum)
 * \return 1 : Success \n
 * 0 : An unknown error has occurred \n
 * -1 : The user types too much characters \n
 * -2 : The user types not enough characters \n
 * -3 : The user does not type a digit but press 'Enter' \n
 */
int getKeyboard_String(char * typedString, int minChar, int maxChar);

#endif