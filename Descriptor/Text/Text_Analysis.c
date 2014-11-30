 //file Text_Analysis.c
// brief  All the functions necessary to analyse a text and then proceed to its indexation
//Author Estelle Randria
//Date : 11/28/2014

#include <stdio.h>
#include <string.h>
#include "Type_Bool.h" 
#include "text_analysis.h" 


Bool isAWord (char * word) {
	int i = 0 ; 
	if ((word[0] >= 32 || word[0] <= 37) || (word[0] >= 39 && word[0] <= 47) || (word[0] >= 58 && word[0] <= 64) || (word[0] >= 91 && word[0] <= 96) || (word[0] >=123 && word[0] <=137) || (word[0] == 139) || (word[0] >= 143 && word[0] <= 153) || (word[0] == 155) || (word[0] >= 160 && word[0] <=191) || (word[0] == 256)) 
			return FALSE ;
		else 
			return TRUE ; 
} 


int endOfWord (char * word) {
	int j = 0 ;
	while (	word[j] != (int) NULL) {
		j++ ; 
	}
	return j ; 
}

 
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
			
	
Bool isWordRelevant (const char * word) {
	int wordLenght ;
	wordLenght = strlen(word) ; 
	if (wordLenght < 3) 
		return FALSE ;
	else 
		return TRUE ;
}	

//This function counts the number of appearances of a word in a text. 
int wordAppearance (char * word) {
	int appearance = 0 ; 
}
