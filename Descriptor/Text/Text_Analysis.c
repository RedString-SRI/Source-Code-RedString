 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h" 

void readWordbyWord(char path[]){
	int i=0;
	int j;
	char c;
	char word[50];
	char *listWord;
	char *listWordRepetition;
	
	FILE *file=fopen(path , 'r');
	
	while(c != EOF) { // while isn't the end of the file ...
		c=fgetc(file);
		if(IsInBeacons(c,file)){ i=0 ; continue ;}
		if(c=='\\'){i=0 ; continue;}
		if(c=='/'){i=0 ; continue;}
		if(c==' '){i=0 ; continue;}
		i++;
		
		while(i>3){
			listWord=(char*)malloc(sizeof(char)); // add a place to put a word
		
			if(c == ' ') { // A space
				listWord=(char**)malloc((i+1)*sizeof(char*)); // create the place with +1 char to put the word into the list --> matrix 2dim
				for(j=0 ; j<i ; j++)
					*(listWord+i)=word[i]; // save the word ...
				listWordRepetition=(char*)malloc(sizeof(char));
				listWordRepetition[i]++; // +1 for the existing word
				i=0; // putting back at zero to start the save of a new word
			}
			else{
				word[i]=c;
				i++;
			}
		}
	}
	fclose(file);
}
//===================================================================================================
Bool isAChar (char word) {
	int i = 0 ; 
	if( (word[0])>=65 && word[0]<=90) || (word[0])>=97 && word[0]<=122) || (word[0])>=97 && word[0]<=122)
			return TRUE ;
		else 
			return FALSE ; 
} 
//===================================================================================================
Bool isInBeacons (char word,  FILE f) {
	int k=word; 
	if (k == '<') {
		while(k!='>')
			k = fgetc(f) ; 
		return TRUE;
	}
	else 
		return FALSE ; 
}
//===================================================================================================
//This function counts the number of appearances of a word in a text. 
int wordAppearance (char * word) {
	int appearance = 0 ; 
}
//====================================================================================================
int textNbchar(const char * path) 
	{ 	int nb_char = 0 ; 
		FILE * text = fopen(path,"r") ; 
	  	while (fgetc(text) != EOF) 
			 nb_char++ ;
		return nb_char - 1 ;
		fclose(text) ; 
	}
//===================================================================================================================
void stockWord (const char * path) { 
	int tmpc = 0 ; 
	int i = 0 ; 
	char word[50] ; 
	FILE * text = fopen(path,"r") ; 
	 
	do 
        {	  tmpc = fgetc(text) ;
            word[i] = tmpc ; 
		  printf("%c" , word[i]) ; 
            i++ ; 
        } while (tmpc != ' ') ; // On continue tant que fgetc n'a pas retourné un espace (fin de mot)
	fclose(text) ; 
 }
 
 //==================================================================================================================
int textNbchar(const char * path) 
	{ 	int nb_char = 0 ; 
		FILE * text = fopen(path,"r") ; 
	  	while (fgetc(text) != EOF) 
			 nb_char++ ;
		return nb_char - 1 ;
		fclose(text) ; 
	}
//===================================================================================================================
void initIndex (Index *i) { 
	*i =  NULL ; 
}

//===================================================================================================================	
Bool indexEmpty (Index i) {
	if (i == NULL) 
		return TRUE ; 
	else 
		return FALSE ; 
}
//===================================================================================================================
void initTerm (Term term) {
	term.word = NULL ; 
	term.occur = 0 ; 
	term.ptr_next = NULL ; 
}
//==================================================================================================================
void createTerm (Term term , char * w) {
	initTerm (term) ; 
	term.word = w ; 
	term.occur++ ; 
}

//==================================================================================================================
void addTerm (Index * i , Term term) { 
	Index * ptr_index = (Index *) malloc(sizeof(Index)) ; 
		(*ptr_index) -> word = term.word ;
		(*ptr_index) -> occur = term.occur ; 
		(*ptr_index) -> ptr_next = *i ; 
		i = ptr_index ; 		
	}

//==================================================================================================================
Bool doesTermExist (Index * i , Term term) {
	if (*i == NULL) {
		printf ("END") ; 
	}
	else 
		{ while (*i != NULL) 
			{ if ((*i) -> word == term.word)
				return TRUE ; 
			
			else 
				{ *i = (*i) -> ptr_next ; 
				  doesTermExist (i , term) ;
				}
			 }
		}
	}
				
//==================================================================================================================
void removeFromIndex (Index * i , Term termtoremove) {
		Term aux ; 
		if (*i == NULL) {
			printf ("END") ;
		}
		else 
			{ 
			while (*i != NULL) 
				{ if ((*i) ->word == termtoremove.word) 
 					{ Index * ptr_stock = i ; 
					*i = (*i) ->ptr_next ;
					aux = *(*ptr_stock) ; 
					free(ptr_stock) ; 
					} 
				 else 
					{ *i = (*i) -> ptr_next ;
					  removeFromIndex (i , termtoremove) ;
					}
				}
			}
	}

//=================================================================================================================
void removeTerm (Index * i) {
	while (*i != NULL) 
		{ if ((*i) -> occur < TMAX)
			{ removeFromIndex (i , *(*i)) ; 
			}
		}
	}
	
//=================================================================================================================
void addOccurences (Index * i , Term t) {
	if (*i == NULL) 
		printf ("END") ; 
	else 
		{ if (doesTermExist (i , t) == TRUE) 
			{	while (*i != NULL) 	
				{ if	(t.word == (*i) -> word) 
					{ (*i) -> occur++ ; 
					  break ; 
					}
				}
			}
		}
} 	

//==================================================================================================================	
int main () {
	printf ("%d\n" , text_nbchar("/home/mahenina/FIL_ROUGE/Test")) ;
} 
