//file Text_Analysis.h
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h> 
#include <string.h> 
#define TMAX 100

typedef struct {
	char * word;
	int occur;
	} Term	;
	
typedef struct { 
	Term t ; 
	Term * ptr_next ; 
	} Index ; 

typedef Index * i ; 


int textNbChar(const char * path) ; 

//Meant for word recognition (a word is built with fonts or numbers. If a string counts one or more symbol then it is NOT a word. 

Bool isAWord (char * word) ;

//Supposing the word is memorize into a table, this function counts the number of fonts in a word to find where the end of the word is located. 

int endOfWord (char * word) ;

//We also have to make a difference between a word and a beacon : a beacon is of the form "<beacon opening> word </beacon closing>  . 

Bool isABeacon (char * word) ;

// A word is considered as relevant if it contains more than three fonts ; this function help us to define if a word is relevant. 

Bool isWordRelevant (const char * word) ;

//This function counts the number of appearances of a word in a text. 
int wordAppearance (char * word) ;
