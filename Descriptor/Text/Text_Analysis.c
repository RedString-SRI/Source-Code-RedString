 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h" 

void readWordbyWord(FILE *file){
	int i=0;
	int j;
	char c;
	char word[50];
	char *listWord;
	char *listWordRepetition;
	
	fopen(file , 'r');
	while(c != EOF) { // while isn't the end of the file ...
		fgetc(file);
		// if c == beacon ...etc
		// if c== slash ...etc
		// if c== antislash ...etc
		// if c== is not a correct char ..etc
		else if(c == 32) {// !=Space
			listWord=(char*)malloc(sizeof(char)); // add a place to put a word
			listWord=(char**)malloc((i+1)*sizeof(char*)); // create the place with i char to put the word into the list --> matrix 2dim
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
	fclose(file);
}
//===================================================================================================
Bool isAWord (char * word) {
	int i = 0 ; 
	if ((word[0] >= 32 || word[0] <= 37) || (word[0] >= 39 && word[0] <= 47) || (word[0] >= 58 && word[0] <= 64) || (word[0] >= 91 && word[0] <= 96) || (word[0] >=123 && word[0] <=137) || (word[0] == 139) || (word[0] >= 143 && word[0] <= 153) || (word[0] == 155) || (word[0] >= 160 && word[0] <=191) || (word[0] == 256)) 
//NOP :/ ??? 	// if( (word[0])>=65 && word[0]<=90) || (word[0])>=97 && word[0]<=122) || (word[0])>=97 && word[0]<=122) return TRUE;
			return FALSE ;
		else 
			return TRUE ; 
} 
//===================================================================================================
int endOfWord (char * word) {
	int j = 0 ;
	while (	word[j] != (int) NULL) {
		j++ ; 
	}
	return j ; 
}
//===================================================================================================
Bool isABeacon (char * word) {
	int k ; 
	if (word[0] == '<') 
		{ k = endOfWord(word) ; 
		   if (word[k] == '>') 
				return TRUE ;
		   else 
				return FALSE ; 
		}
	else if ((word[0] == '<') && (word[1] == '/')) 
		{ k = endOfWord(word) ; 
			if (word[k] == '>') 
				return TRUE ; 
			else 
				return FALSE ;
		}
	
		else 
			return FALSE ; 
}
//===================================================================================================
Bool isWordRelevant (const char * word) {
	int wordLenght ;
	wordLenght = strlen(word) ; 
	if (wordLenght < 3) 
		return FALSE ;
	else 
		return TRUE ;
}	
//===================================================================================================
//This function counts the number of appearances of a word in a text. 
int wordAppearance (char * word) {
	int appearance = 0 ; 
}
