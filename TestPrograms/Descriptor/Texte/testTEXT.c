//file testTEXT.c
// brief : Test of the functions to analyse texts
//Author Estelle Randria
//Date : 01/02/2015
	
int main () {
	Index I ;  
	char w[10] ; 
	char w1[10] ; 
	Term term1 , term2 ; 
	strcpy (w, "sachet") ;
	strcpy (w1, "calamar") ;  
	
	printf ("number of characters of the text : %d\n" , textNbchar("/home/mahenina/FIL_ROUGE/Test")) ;
	initIndex(&I) ; 
//initIndex() checked. 
	if(indexEmpty(I)) 
		{ printf ("Index is currently empty\n") ; } 
//indexEmpty() checked
	initTerm(&term1) ; 
	termDetails(term1) ; 
	printf ("term1 creation :\n") ; createTerm(&term1, w) ; 
	printf ("After the update : \n") ; 
//createTerm() checked & termDetails() checked 
	termDetails(term1) ;
	increaseOccur(&term1) ; 
//increaseOccur() checked
	termDetails(term1) ; 
	printf ("term1's occur : %d\n" , term1.occur) ; 
	decreaseOccur(&term1) ;
//decreaseOccur() checked  
	addTerm(&I, term1) ;
	returnIndex(I) ; 
//addTerm() and returnIndex() checked
	createTerm(&term2 , w1) ; 
	termDetails(term2) ; 
	addTerm(&I , term2) ; 
	returnIndex (I) ; 

//Currently testing :
	if (doesTermExist(&I, term1))
		printf ("term1 exists\n") ; //it exists
	else printf ("term1 doesn't exist\n") ;  
	if (doesTermExist(&I , term2)) 
		printf ("term2 exists\n") ;
	else printf ("term2 doesn't exist\n") ; //it doesn't exist
		
} 
