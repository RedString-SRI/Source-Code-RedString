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
	strcpy (w1, "chien") ;  
	
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
//createTerm() checked
	termDetails(term1) ;
	increaseOccur(term1) ; 
	printf ("term1's occur : %d" , term1.occur) ; //affiche 1 au lieu d'afficher 2
} 
