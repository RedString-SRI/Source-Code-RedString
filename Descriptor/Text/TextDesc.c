 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014
//Latest Update : 01/18/2015

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "TextDesc.h"

Bool isInBeacons (char * word) {
	int i = 0 ; 
	
		if (word[0] == '<')
	 	{	 
			while( word[i] != '\0' ) 
				{   
					if (word[i] == '>')
						{
						  
						  return TRUE;
						} 
					else 
						i++ ;
				}
		}
		return FALSE ; 
		 
} 


//===============================================================================

/*Bool isAChar (int word) {
int i = 0 ;
if( (word[i] >= 65 && word[i]<=90) || (word[i]>=97 && word[i]<=122) || (word[i]>=97 && word[i]<=122))
return TRUE ; 
else
return FALSE ;
}
*/

//================================================================================

Bool isWordRelevant (const char * word) {
	int wordLenght ;
	wordLenght = strlen(word) ;
	if (wordLenght > 3)
		return TRUE ;
	else
		return FALSE ;
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
			return FALSE ;
}

//=================================================================================

void initTerm (Term * t) {
	t->word = NULL ; 
	t->occur = 1 ; 
}

//=================================================================================

void createTerm (Term * t , char * w) {
	initTerm (t) ; 
	t->word = strdup(w) ;
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
}

//=====================================================================================


Bool doesTermExist (Index i , char * word) {
	Index ptr_dep = i;	
	if (i == NULL) 
		{
			printf ("END does term exist\n") ;
			return FALSE ; 
	
		}
	else 
		while (ptr_dep != NULL)  
		{ 	
			if (strcmp(ptr_dep->t1.word, word) == 0) 
				return TRUE;
					ptr_dep=ptr_dep->ptr_next ;		
		}	
	return FALSE;	
}


//=====================================================================================
 
void returnIndex (Index i) {
	Index ptr_dep = i ; 
	printf ("\n\n==== returnIndex process started =====\n\n") ; 
	if (indexEmpty(i)) 
		printf ("No more term\n") ; 
	else 
	{ 
		while ((ptr_dep) -> ptr_next !=NULL) 
		{
		  termDetails(ptr_dep->t1) ; 
		  printf ("--------------\n") ; 
		  ptr_dep = ptr_dep->ptr_next ; 
		}
		printf ("End reached\n") ;
	}
	printf ("\n==== Index returned ======\n\n") ; 
	
}


//===================================================================================

void increaseOccur (Term * t) {
	(t ->occur)++ ;
}

//===================================================================================


void addOccurences (Index * i , Term t) {
	Cell * ptr_Cell = (Cell *) malloc(sizeof(Cell)) ;
	if (*i == NULL) 
		printf ("END addoccurences\n") ; 
	else 
		{ 		ptr_Cell = *i ; 
				while (*i != NULL) 	
				{ if	(strcmp((*i)->t1.word, t.word) == 0)  
					{ increaseOccur(&((*i)->t1)) ; 
					  //printf("occur increased\n") ; 
					  break ; 
					}
				   *i = (*i)->ptr_next ; 
				}
				*i = ptr_Cell ; 
		}
}

//===========================================================================================

void readWordbyWord(const char * path , Index * i) {
	FILE * text = fopen(path,"r") ;
	char * word ; 
	word = malloc(sizeof(char)*100) ;  
	if (text != NULL) 
	
	{	
		while(fscanf(text,"%s",word) != EOF)
		{
	
				if ((!isInBeacons(word)) && (isWordRelevant(word)))
				{	
	
					 if (doesTermExist(*i ,word) == FALSE) 	
					 
					{	
										
						Term * t = (Term*) malloc(sizeof(Term)) ;
						createTerm(t , word) ;	
						addTerm(i , *t) ;
					}

				  	else
					{	
						Cell * cTmp = *i ; 
						while ( strcmp(cTmp->t1.word , word) != 0) 
						{ cTmp = (cTmp)->ptr_next ; }		
						(cTmp)->t1.occur ++ ;   
					} 
				
				}
			
		}  
		fclose(text) ; 
	}
	free(word) ;    
}

//=======================================================================

Index finalIndex(Index * i) {
	Index finalI ;
	initIndex(&finalI) ; 
		while ((*i) -> ptr_next != NULL) 
		{		
			if ((*i) -> t1.occur < TMAX) 
			{	Cell * ptr_stock = *i ; 
			 	*i = (*i)->ptr_next ;
			 	free(ptr_stock) ; 
			}
		
	 		else 
			{ 	Cell * ptr_stock = *i ;
				addTerm(&finalI, (*i)->t1) ; 
				(*i) = (*i) -> ptr_next ; 
				free(ptr_stock) ; 
			}
		}
	printf("End of final Indexation\n") ; 
	return finalI ;
} 



//=======================================================================


	
