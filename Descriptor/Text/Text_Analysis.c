 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h"

Bool isInBeacons (const char * path, char word) {
	FILE * text = fopen(path,"r") ;
	int k=word;
	if (k == '<')
	 {
		while(k!='>')
		k = fgetc(text) ;
		return TRUE;
	}
	else
		{ return FALSE ; }
	fclose(text) ; 
} 

//======================================================================

void readWordbyWord(const char * path){
	int i=0;
	int j;
	char c;
	char word[50];
	char *listWord;
	char *listWordRepetition;
	FILE *text=fopen(path , "r");
	while(c != EOF) 
	{ // while isn't the end of the file ...
		c=fgetc(text);
		if(isInBeacons(path,c)){ i=0 ; continue ;}
		if(c=='\\'){i=0 ; continue;}
		if(c=='/'){i=0 ; continue;}
		if(c==' '){i=0 ; continue;}
		i++;
		while(i>3)
		  {
			listWord=(char*)malloc(sizeof(char)); // add a place to put a word
			if(c == ' ') 
			{ // A space
				listWord=(char**)malloc((i+1)*sizeof(char*)); // create the place with +1 char to put the word into the list --> matrix 2dim
				for(j=0 ; j<i ; j++) 
				{
				*(listWord+i)=word[i]; // save the word ...
				listWordRepetition=(char*)malloc(sizeof(char));
				listWordRepetition[i]++; // +1 for the existing word
				i=0; // putting back at zero to start the save of a new word
				}
			}
			else
			{
				word[i]=c;
				i++;
			}

		}
	}
	
fclose(text);
}

//===================================================================================================
/*Bool isAChar (char word) {
int i = 0 ;
if( (word[0])>=65 && word[0]<=90) || (word[0])>=97 && word[0]<=122) || (word[0])>=97 && word[0]<=122)
return TRUE ;
else
return FALSE ;
} */

//================================================================================

int endOfWord (char * word) {
int j = 0 ;
while ( word[j] != (int) NULL) {
j++ ;
}
return j ;
}


//================================================================================

Bool isWordRelevant (const char * word) {
	int wordLenght ;
	wordLenght = strlen(word) ;
	if (wordLenght < 3)
		return FALSE ;
	else
		return TRUE ;
} 

//================================================================================

int textNbchar(const char * path) 
	{ 	int nb_char = 0 ; 
		FILE * text = fopen(path,"r") ; 
	  	while (fgetc(text) != EOF) 
			 nb_char++ ;
		return nb_char - 1 ;
		fclose(text) ; 
	}

//=================================================================================

void initIndex (Index * i) 
	{ *i =  NULL ; 
	  printf ("Index iniatialized\n") ; 
	}
	
//=================================================================================

Bool indexEmpty (Index i) {
	if (i == NULL) 
		return TRUE ;
	else 
		return FALSE ;
}

//=================================================================================

void initTerm (Term * t) {
	t -> word = NULL ; 
	t -> occur = 0 ; 
	printf ("term initialized\n") ; 
}

//=================================================================================

void createTerm (Term * t , char * w) {
	initTerm (t) ; 
	t -> word = w ; 
	t -> occur++ ;
	printf ("Term created\n") ; 
}

//==================================================================================

void termDetails (Term t) {
	printf ("The word is : %s\n" , t.word) ;
	printf ("The number of appearances is : %d\n" , t.occur) ; 
} 

//===================================================================================
 
void addTerm (Index * i , Term t) { 
	Cell * ptr_Cell = (Cell *) malloc(sizeof(Cell)) ; 
		(*ptr_Cell).t1 = t ; 
		(*ptr_Cell).ptr_next = *i ; 
		*i = ptr_Cell ; 	
		printf("Term added\n") ; 	
	}

//=====================================================================================


Bool doesTermExist (Index * i , Term t) {
	if (*i == NULL) {
		printf ("END\n") ; 
	}
	else 
		{ while (*i != NULL) 
			{ if ((*i) -> t1.word == t.word)
				{ return TRUE ; 
				  break ; 
				}
			
			else 
				{ *i = (*i) -> ptr_next ; 
				}
			 }
		}
	}
				
//===================================================================================

void removeFromIndex (Index * i , Term ttoremove) {
		Cell aux ; 
		if (*i == NULL) {
			printf ("END\n") ;
		}
		else 
			{ 
			while (*i != NULL) 
				{ if ((*i) -> t1.word == ttoremove.word) 
 					{ Index * ptr_stock = i ; 
					*i = (*i) ->ptr_next ;
					aux = *(*ptr_stock) ; 
					free(ptr_stock) ; 
					} 
				 else 
					{ *i = (*i) -> ptr_next ;
					}
				}
			}
	}


//=====================================================================================
 
void returnIndex (Index i) {
	Cell tmpCell ; 
	if (indexEmpty(i)) 
		printf ("No more term\n") ; 
	else 
	{ 
		while (i !=NULL) 
		{ tmpCell = *i ; 
		  termDetails(tmpCell.t1) ; 
		  i = i -> ptr_next ; 
		  returnIndex(i) ; 
		}
	}
	
}

//====================================================================================

void removeTerm (Index * i) {
	while (*i != NULL) 
		{ if ((*i) -> t1.occur < TMAX)
			{ removeFromIndex (i , (*i) -> t1) ; 
			}
		}
	}

//===================================================================================

void increaseOccur (Term * t) {
	printf ("current word : %s\ncurrent occur : %d\n" , t -> word ,t -> occur) ;
	(t ->occur)++ ;
	printf ("new occur : %d\n", t -> occur) ; 
}

//===================================================================================

void decreaseOccur (Term * t) {
	printf ("current word : %s\ncurrent occur : %d\n" , t -> word ,t -> occur) ;
	(t ->occur)-- ;
	printf ("new occur : %d\n", t -> occur)  ;
}

//===================================================================================

void addOccurences (Index * i , Term t) {
	if (*i == NULL) 
		printf ("END\n") ; 
	else 
		{ if (doesTermExist (i , t) == TRUE) 
			{	while (*i != NULL) 	
				{ if	(t.word == (*i) -> t1.word) 
					{ increaseOccur(&((*i) -> t1)) ; 
					  break ; 
					}
				}
			}
		}
}
