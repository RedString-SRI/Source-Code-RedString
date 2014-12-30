//file Text_Analysis.h
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h> 
#include <string.h> 
#define TMAX 100

typedef struct term {
	char * word;
	int occur;
	struct term *ptr_next ; 
	} Term, *Index ; 


int textNbChar(const char * path) ; 

//Meant for word recognition (a word is built with fonts or numbers. If a string counts one or more symbol then it is NOT a word. 

Bool isAWord (char * word) ;

//Supposing the word is memorize into a table, this function counts the number of fonts in a word to find where the end of the word is located. 

int endOfWord (char * word) ;

//Supposed to print the word.
void stockWord (const char * path) ; 


//We also have to make a difference between a word and a beacon : a beacon is of the form "<beacon opening> word </beacon closing>  . 

Bool isABeacon (char * word) ;

// A word is considered as relevant if it contains more than three fonts ; this function help us to define if a word is relevant. 

Bool isWordRelevant (const char * word) ;

//This function counts the number of appearances of a word in a text. 
int wordAppearance (char * word) ;

//This function counts the total of characters in the text. 
int textNbChar(const char * path) ; 

//This function checks if the term already exists in the index. 
Bool doesTermExist (Index * i , Term term) ;

//Initialisation of the index. 
void initIndex (Index * i) ;

//Check if the index is empty. 
Bool indexEmpty (Index i) ; 

//Initialisation of a term. 
void initTerm (Term term) ;

//Create a new term. 
void createTerm (Term term , char * w) ; 
	

//Add a term in the index. 
void addTerm (Index * i , Term term) ;

//Remove a term from the index. 
void removeFromIndex (Index * i , Term termtoremove) ;

//Remove a term from the index under the condition that the number of appearances is inferior to the minimum required. 
void removeTerm (Index * i) ; 


//This function increments the appearances if the word already exist in the Index ; 
void addOccurences (Index * i , Term t) ;
