 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h" 
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
Bool isAChar (char word) {
	int i = 0 ; 
	if( (word[0])>=65 && word[0]<=90) || (word[0])>=97 && word[0]<=122) || (word[0])>=97 && word[0]<=122)
			return TRUE ;
		else 
			return FALSE ; 
} 
//===================================================================================================
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
void termDetails (Term term) {
	printf ("The word is : %s\n" , term.word) ;
	printf ("The number of appearances is : %d\n" , term.occur) ; 
} 

 //==================================================================================================================
int textNbchar(const char * path) {
	int nb_char = 0 ; 
	FILE * text = fopen(path,"r") ; 
	while (fgetc(text) != EOF) 
		nb_char++ ;
		
	fclose(text) ; 
	return nb_char - 1 ;
	}
//===================================================================================================================
void initIndex (Index *i) { 
	*i =  NULL ; 
}
//===================================================================================================================	
Bool indexIsEmpty (Index i) {
	if (i == NULL) 
		return TRUE ; 
	else 
		return FALSE ; 
}
//===================================================================================================================
void initTerm (Term * term) {
	term -> word = NULL ; 
	term -> occur = 0 ; 
	term -> ptr_next = NULL ; 
	printf ("term initialized\n") ; 
}

//==================================================================================================================
void createTerm (Term * term , char * w) {
	initTerm (term) ; 
	term -> word = w ; 
	term -> occur++ ;
	printf ("Term created\n") ; 
}

//==================================================================================================================
void addTerm (Index * i , Term term) { 
	Term * ptr_Term = (Term *) malloc(sizeof(Term)) ; 
		*(ptr_Term) = term ; 
		(*ptr_Term).ptr_next = *i ; 
		*i = ptr_Term ; 	
		printf("Term added\n") ; 	
	}
	
//==================================================================================================================
Bool doesTermExist (Index *i , Term t) {
	if (*i == NULL)
		printf ("END") ; 
	else { 
		while (*i != NULL) { 
			if ( (*i)->word == t.word)
				return TRUE ; 
			else { 
				*i = (*i)->ptr_next ; 
				doesTermExist (i , t) ;
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
		else { 
			while (*i != NULL) { 
				if ((*i) ->word == termtoremove.word) { 
				//	Index * ptr_stock = i ;  // COMPLETEMENT FAUX ! Index est une struct, je sais pas ce que tu as voulu faire ici
					*i = (*i) ->ptr_next ;
					aux = *(*ptr_stock) ; 
					free(ptr_stock) ; 
				} 
				else { 
					*i = (*i) -> ptr_next ;
					removeFromIndex(i , termtoremove) ;
				}
			}
		}
}

//=================================================================================================================
void returnIndex (Index i) {
	if (i == NULL) 
	{ printf ("END\n") ; 
	}
	else 
	{ while (i !=NULL) 
		{ printf ("%s\n" , i -> word) ;
		  i = i -> ptr_next ; 
		  returnIndex(i) ; 
		}
	}
}
//=================================================================================================================
void removeTerm (Index * i) {
	while (*i != NULL) { 
		if ((*i) -> occur < TMAX)
			removeFromIndex (i , *(*i)) ; 
	}
}
//=================================================================================================================
void addOccurences (Index * i , Term t) {
	if (*i == NULL) 
		printf ("END") ; 
	else { 
		if (doesTermExist (i , t) == TRUE) {	
			while (*i != NULL) { 
				if (t.word == (*i) -> word) { 
					(*i) -> occur++ ; 
					  break ; 
				}
			}
		}
	}
} 	
/*==================================================================================================================	

