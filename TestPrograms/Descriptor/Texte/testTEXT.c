//file testTEXT.c
// brief : Test of the functions to analyse texts
//Author Estelle Randria
//Date : 01/02/2015
	
	Index I ;  
	char w[10] ; 
	char w1[10] ; 
	strcpy (w, "sachet") ;
	strcpy (w1, "chien") ;  
	Term term1 , term2 ; 
	printf ("%d\n" , textNbchar("/home/mahenina/FIL_ROUGE/Test")) ;
	initIndex(&I) ; 
	if(indexEmpty(I)) 
		{ printf ("Index is currently empty\n") ; } 
	initTerm(&term1) ; 
	printf ("term1 word is %s\nterm1 occur is %d\n" , term1.word, term1.occur) ; 
	createTerm(&term1, w) ; 
	printf ("term1 word is %s\nterm1 occur is %d\n" , term1.word, term1.occur) ; 
	termDetails(term1) ; 
	createTerm(&term2, w1) ;
	termDetails(term2) ;  
