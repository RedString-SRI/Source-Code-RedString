//file Test_TextDesc.c
// brief : Test of the functions to analyse texts
//Author Estelle Randria
//Date : 01/15/2015

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TextDesc.h"

int main () {

	Index DescText ; 
	Index I ; 
	initIndex(&I) ; 


	int NumberOfChars = textNbchar("/home/mahenina/.cache/.fr-nqBiAD/Base_Textes/05-Edition___les_mots_et.xml") ;
	printf("The number of characters is : %d\n" , NumberOfChars) ; 
	readWordbyWord("/home/mahenina/.cache/.fr-nqBiAD/Base_Textes/05-Edition___les_mots_et.xml", &I) ;
	//printf("\nThe temporary Index is :\n") ; 	
	//returnIndex(I) ; 
	DescText = finalIndex(&I) ;
	printf("\nThe Descriptor :\n") ;
	returnIndex(DescText) ; 
}
