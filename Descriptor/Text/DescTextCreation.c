#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Text_Analyse.h"

int main () {

	Index DescText ; 
	Index I ; 
	initIndex(&I) ; 


	int NumberOfChars = textNbchar("/home/mahenina/.cache/.fr-nqBiAD/Base_Textes/05-Edition___les_mots_et.xml") ;
	printf("The number of characters is : %d\n" , NumberOfChars) ; 
	readWordbyWord("/home/mahenina/.cache/.fr-nqBiAD/Base_Textes/05-Edition___les_mots_et.xml", &I) ;
	returnIndex(I) ; 
	DescText = finalIndex(&I) ;
	printf("\nThe Descriptor :\n") ;
	returnIndex(DescText) ; 
}
