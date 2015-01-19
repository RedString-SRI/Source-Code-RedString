/**
* \file SearchEngine.h
* \brief listing of research functions.
* \author Gabriel DEL REY
* \version 0.1
* \date 7 December 2014
*
* All the way to do research in the listeBaseDesc 
*
*/

#include"BaseDesc.h"
#include"interface.h"

typedef enum COLOR COLOR;
enum COLOR{BLACK=000000, 
            LIGHTGRAY=101010, 
            DARKGRAY=010101, 
            WHITE=111111, 
            RED=110000,
            PINK=111010, 
            YELLOW=001111, 
            PURPLE=100010, 
            BROWN=100101, 
            GREEN=001100, 
            LIGHTGREEN=001000, 
            BLUE=000011,
            LIGHTBLUE=000010};
/**
* \brief byColor.
* Search specifiquely in an image's desc a color.
*
*/
void byColor(COLOR c);

/**
* \brief compareFileIMG
* Make a percent of difference bewteen 2 IMGDdesc.
*/
float compareFileIMG(PictureDesc *imgD1, PictureDesc *imgD2);

/**
* \brief byNamedColor
* Search IMG base the most appropriate pictures of the research.
*/
void byNamedColor();

/**
* \brief isAColor
* Say if the color in parameter is in the listing of possible colors.
*/
Bool isAColor(char c[]);

/**
* \brief cpsBYcps.
* composants by composants. The user put the value of RED, next GREEN and BLUE and the appli search about it
*/
void cpsBYcps();

/**
* \brief researchIMG
* Search on the image's Base.
*/
void researchIMG(FILE *imgbase);

/**
* \brief byOccurenceWord.
* Search specifiquely in texte desc the files which get the most of researched words.
*/
void byOccurenceWord(char word);

/**
* \brief researchTXT
* Search on the text's Base.
*/
void researchTXT(FILE *txtbase);

/**
* \brief researchSound
* Search on the sound's Base.
*/
void researchSound(FILE *soundbase);

/**
* \brief addOrderVD
* Do a list of decreasing pertinence of files
*/
void addOrderVD(PileVD *pvd, float perct , char nFile);

/**
* \brief printfBestList
* Recursive, print the pertinence listing of the user's choice.
*/
void printBestList(PileVD pvd , int j);

/**
* \brief getChoosenFile
* Give the name of the coosen file by the user.
*/
char *getChoosenFile(PileVD PilevalDesc,int choice);
