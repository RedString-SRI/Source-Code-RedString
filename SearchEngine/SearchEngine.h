/**
* \file SearchEngine.h
* \brief listing of research functions.
* \author Gabriel DEL REY
* \version 0.1
* \date 7 December 2014
*
* All the way to do research in the listeBaseDescriptor
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 enum COLOR(BLACK(000000), 
            LIGHTGRAY(101010), 
            DARKGRAY(010101), 
            WHITE(111111), 
            RED(110000), 
            PINK(111010), 
            YELLOW(001111), 
            PURPLE(??????), 
            BROWN(??????), 
            GREEN(001100), 
            BLUE(000011) );
/**
* \brief byColor.
* Search specifiquely in an image's descriptor a color:
* BLACK:    00 00 00 -> 0
* LIGHTGRAY:10 10 10 -> 42
* DARKGRAY: 01 01 01 -> 21
* WHITE:    11 11 11 -> 63
* RED:      11 00 00 -> 48
* PINK:     11 10 10 -> 58
* YELLOW:   00 11 11 -> 15
* PURPLE:
* BROWN:
* GREEN:    00 11 00 -> 12
* BLUE:     00 00 11 -> 3
* 
*
*/
void byColor(char color[]);

/**
* \brief byAuthor.
* Search in whichever descriptor a author in alphabetic order.
*/
void byAuthor();

/**
* \brief byModifDate.
* Search specifiquely in whichever descriptor the recent modification in increasing order.
*/
void byModifDate();

/**
* \brief byCreatingDate.
* Search specifiquely in whichever descriptor by Creating Date in increasing order.
*/
void byCreatingDate();

/**
* \brief byNameFile.
* Search specifiquely in whichever descriptor by Name's file in alphabetic order.
*/
void byNameFile();

/**
* \brief byOccurenceWord.
* Search specifiquely in texte descriptor the files which get the most of researched words.
*/
void byOccurenceWord();

/**
* \brief bySOUNDSOUNDSOUNDSOUND.
* 
*/
void bySOUNDSOUNDSOUND(); // I DONT KNOW WHAT IT IS RESEARCHED IN SOUND FILES !!!!!
