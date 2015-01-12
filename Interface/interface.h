/**
* \file interface.h
* \brief header on interface.c
* \author Gabriel DEL REY
* \version 0.1
* \date 7 December 2014
*
*
*/

#include "BaseDesc.h"

typedef struct vd{ // PILE DYnamic
	float pct; // percentage or nbr Occurence about linked research
	char nameFile[100]; // the name of the file to can open it.
	struct vd *NextVD;
}Val_Desc, *PileVD; // for easy the saving

/**
 * \brief First board print in console, main Menu
 * 
 * Permite the user to choose between indexation and research
 * if indexation, go to IndexationMenu()
 * if Research, go to ResearchMenu()
 */
 void mainMenu();
 
/**
 * \brief choosen board print in console, Indexation Menu
 * 
 * Permite the user to enter path(s) for indexation
 * The user enter a path, or many paths and when he want index the whole paths,
 * he must Enter an empty path to start indexation
 */
void IndexationMenu();

/**
 * \brief choosen board print in console, Research Menu
 * 
 * Permite the user to do reserach about colors, words, similar sound
 *  By color, the user can do research by named color of composants by composants :
 *      -by namde color : The user give a possible saved color (BLACK , DARKGRAY , LIGHTGRAY , WHITE , RED , PINK , YELLOW , PURPLE , BROWN , GREEN , LIGHTGREEN , BLUE , LIGHTBLUE)
 *      -by composants by composants : The user give bits of composants (RED,GREEN,BLUE) and go to byColor()
 *  By sound, research a given file sound about another file sound in the listeBAseSound
 */
void ResearchMenu();

/**
 * \brief clear input
 * 
 * Permite to clear input and dangerous scanf
 */
void clearBuffer();
