//file testTEXT.c
// brief : Test of the functions to analyse texts
//Author Estelle Randria
//Date : 01/02/2015
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Text_Analyse.h"

//===================================================================================== 
	
int main () {
	Index I ; 
	initIndex(&I) ; 
	int i ;
	char w1[10] ; 
	char w2[10] ; 
	char w3[15] ; 
	char w4[20] ; 
	char w5[10] ; 
	Term term1 , term2, term3, term4, term5 ; 
	

	
	printf("\n\nTESTS ONE BY ONE\n\n") ; 
	
	strcpy (w1, "sachet") ;
	strcpy (w2, "calamar") ;  
	strcpy (w3, "Salamandre") ; 
	strcpy (w4, "<antilope>") ;
	strcpy (w5, "rose") ;  
	printf ("number of characters of the text : %d\n" , textNbchar("/home/mahenina/FIL_ROUGE/Test")) ;
	initIndex(&I) ; 
//initIndex() checked. 

//=================================================================================

	if(indexEmpty(I)) 
		{ printf ("Index is currently empty\n") ; } 
//indexEmpty() checked

//=================================================================================
	
	initTerm(&term1) ; 
	termDetails(term1) ; 
	printf ("term1 creation :\n") ; 
	createTerm(&term1, w1) ; 
	printf ("After the update : \n") ; 
	addTerm(&I, term1) ;
//createTerm() checked & termDetails() checked 

//=================================================================================

	termDetails(term1) ;
for (i = 0 ; i < 15 ; i++)
		{ increaseOccur(&term1); }
//increaseOccur() checked

//=================================================================================

	termDetails(term1) ; 
	printf ("term1's occur : %d\n" , term1.occur) ;   
	addTerm(&I, term1) ;
	returnIndex(I) ; 
//addTerm() and returnIndex() checked

//=================================================================================

	createTerm(&term2 , w2) ; 
	createTerm(&term3, w3) ; 
	termDetails(term2) ; 
	addTerm(&I , term2) ; 
	addTerm(&I, term3) ; 
	returnIndex (I) ; 

//=================================================================================
	
	if (doesTermExist(I, "sachet"))
		printf ("sachet exists\n") ;
	else printf ("w1 doesn't exist\n") ;  
	if (doesTermExist(I , term2.word)) 
		printf ("w2 exists\n") ;
	else printf ("w2 doesn't exist\n") ;
	if(doesTermExist(I, term3.word))
		printf ("w3 exists\n") ; 
	else printf ("w3 doesn't exist\n") ; 
	//doesTermExist() checked

//==============================================================================

	if(isInBeacons(w4)) 
		printf ("The word w4 is in beacons\n") ;
	else printf ("The word w4 isn't in beacons\n") ; 
	
	if (isInBeacons(w5))
		printf ("The word w5 is in beacons\n") ; 
	else printf ("The word w5 isn't in beacons\n") ; 

	//isInBeacons() checked 

//============================================================================
	
	createTerm(&term5, w5) ;
	if(!doesTermExist(I, "rose")) 
	{	printf("term exists\n") ;	
	addTerm(&I, term5) ; 
	}	
	else { (addOccurences(&I, term5)) ; } 
	createTerm(&term4, w4) ; 
	addTerm(&I, term4) ; 
	returnIndex(I) ; 

	addOccurences(&I, term5) ; 
	addOccurences(&I, term4)  ;
	returnIndex(I) ; 

//==================================================================================

	printf ("number of characters of the text : %d\n" , textNbchar("/home/mahenina/FIL_ROUGE/Test")) ;
	//textNbChar() checked 

//====================================================================================


	readWordbyWord("/home/mahenina/FIL_ROUGE/Test", &I) ;
	//readWordbyWord() checked 

//===================================================================================

	returnIndex(finalIndex(&I)) ; 
} 
