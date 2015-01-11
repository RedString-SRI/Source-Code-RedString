 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h"


Bool isInBeacons (char * word) {
	int j = 0 ; 
	char k ;
	
		if (word[0] == '<')
	 	{	k = word[0]  ; 
			while(k!= (int) NULL)
				{   k = word[j] ;
					printf (" %c\t " , k) ;
					j++ ;   
					if (k == '>')  
						{
						  return TRUE;
						} 
				}
			return FALSE ; 
		}
		else 
			return FALSE ; 
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
	printf ("current word : %s\n", t->word) ;
	t -> occur = 0 ; 
	printf ("current occur : %d\n" , t->occur) ;  
	printf ("term initialized\n") ; 
}

//=================================================================================

void createTerm (Term * t , char * w) {
	initTerm (t) ; 
	t -> word = w ; 
	printf ("current word : %s\n" , t-> word) ; 
	t -> occur++ ;
	printf ("current occur : %d\n" , t -> occur) ; 
	printf ("Term created\n") ; 
}

//==================================================================================

void termDetails (Term t) {
	printf ("The word is : %s\n" , t.word) ;
	printf ("The number of appearances is : %d\n" , t.occur) ; 
} 

//===================================================================================
 
void addTerm (Index * i , Term t) { 
	printf ("==== Add process started =====\n") ; 
	printf ("=Term in parameters details=\n") ; 
	termDetails (t) ; 
	Cell * ptr_Cell = (Cell *) malloc(sizeof(Cell)) ; 
	(*ptr_Cell).t1 = t ; 
	(*ptr_Cell).ptr_next = *i ; 
	printf ("=Term updated details=\n") ; 
	termDetails ((*ptr_Cell).t1) ;
	ptr_Cell->ptr_next = *i; 
	*i = ptr_Cell ; 	
	printf("==== Term added in the index ====\n") ; 	
}


//=====================================================================================

Bool doesTermExist (Index i , Term t) {
	Index ptr_dep = i;
	if (i == NULL) 
		printf ("END\n") ;
	else 
		while (ptr_dep != NULL)  
		{ 
			if (strcmp(ptr_dep->t1.word, t.word) == 0)
				return TRUE; 
			else 
				ptr_dep=ptr_dep->ptr_next;
		}
	return FALSE;
}
				
//===================================================================================

Term removeFromIndex (Index * i , Term ttoremove) {
		Term taux ; 
		Cell caux ; 
		while (*i != NULL) 
		{
			if (*i == NULL) 		
				{ printf ("END\n") ;}
			else 
			{ 	
				if ((*i) -> t1.word == ttoremove.word) 
 				{ 
					Cell * ptr_stock = *i ; 
					(*i) = (*i) ->ptr_next ;
					taux = (ptr_stock) -> t1 ; 
					free(ptr_stock) ; 
					return taux ; 
					break ; 
				} 
				 else 
					{ *i = (*i) -> ptr_next ; }
				
			}
			
		}
	}	


//=====================================================================================
 
void returnIndex (Index i) {
	printf ("==== returnIndex process started =====\n") ; 
	Cell tmpCell ; 
	if (indexEmpty(i)) 
		printf ("No more term\n") ; 
	else 
	{ 
		while (i !=NULL) 
		{ tmpCell = *i ; 
		  termDetails(tmpCell.t1) ; 
		  printf ("--------------\n") ; 
		  i = i -> ptr_next ; 
		}
	}
	printf ("==== Index returned ======\n") ; 
	
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

void addOccurences (Index * i , char * word) {
	Cell * ptr_Cell = (Cell *) malloc(sizeof(Cell)) ;
	if (*i == NULL) 
		printf ("END\n") ; 
	else 
		{ if (doesTermExist (*i , word)) 
			{	ptr_Cell = *i ; 
				while (*i != NULL) 	
				{ if	(strcmp((*i) -> t1.word, word) == 0)  
					{ increaseOccur(&((*i) -> t1)) ; 
					  printf("occur increased\n") ; 
					  break ; 
					}
				  else *i = (*i) -> ptr_next ; 
				}
				*i = ptr_Cell ; 
			}
		  else printf ("This word hasn't been found\n") ; 
			
		}
}

//===================================================================================
