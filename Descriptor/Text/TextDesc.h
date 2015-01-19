//file TextDesc.h
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include "BaseDesc.h"
#include "Type_Term.h"
#include "Type_Bool.h"
#include "Type_TextDesc.h"


#define TMAX 3


typedef struct cell {
Term t1 ; 
struct cell *ptr_next ;
} Cell, *Index ; 

//Verify if the word is located into beacons 
Bool isInBeacons (char * word) ;

//Verify if the word is bigger than only three characters. 
Bool isWordRelevant (const char * word) ;

//Return the total number of characters of the text. 
int textNbchar(const char * path) ;

//Initialize the Index. 
void initIndex (Index * i) ;

//Check if the index is empty  
Bool indexEmpty (Index i) ;

//Create a term where the word is NULL and the initial occurence is 1. 
void initTerm (Term * t) ;

//Create the term (insert the word)
void createTerm (Term * t , char * w) ;

//Display the word's details 
void termDetails (Term t) ;

//Add a term into the index
void addTerm (Index * i , Term t) ;

//Verify if the term is already included in the index 
Bool doesTermExist (Index i , char * word) ;

//Display the Index in parameters
void returnIndex (Index i) ;

//Increase the number of occurence of the term in parameters.
void increaseOccur (Term * t);

//Read the text word by word to analyze it. 
void readWordbyWord(const char * path , Index * i) ;

//Return the final Index. 
Index finalIndex(Index * i) ;
