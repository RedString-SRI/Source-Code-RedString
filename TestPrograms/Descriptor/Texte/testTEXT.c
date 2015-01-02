Bool isAChar (char word) {
printf("FONCTION 1:\n");
	int i = 0 ; 
	if( (word[0])>=65 && word[0]<=90) || (word[0])>=97 && word[0]<=122) || (word[0])>=97 && word[0]<=122)
			return TRUE ;
			printf("true\n");
		else 
			return FALSE ; 
			printf("false\n");
} 
//===================================================================================================
Bool isInBeacons (char word,  FILE f) {
printf("FONCTION 1:\n");
	int k=word; 
	if (k == '<') {
		while(k!='>')
			{ k = fgetc(f) ; printf("%c " , k);
		printf("true\n");
		return TRUE;
		
	}
	else 
		{return FALSE ; printf("false\n"); }
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
void stockWord (const char path) { 
	int tmpc = 0 ; 
	int i = 0 ; 
	char word[50] ; 
	FILE *text = fopen(path,"r") ; 
	 
	do{
		tmpc = fgetc(text) ;
            	word[i] = tmpc ; 
		printf("%c" , word[i]) ; 
            	i++ ; 
        } 
        while (tmpc != ' ') ; // On continue tant que fgetc n'a pas retourné un espace (fin de mot)
	fclose(text) ; 
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
void initTerm (Term t) {
	t.word = NULL ; 
	t.occur = 0 ; 
	t.ptr_next = NULL ; 
}
//==================================================================================================================
void createTerm (Term t , char w) {
	initTerm (t) ; 
	t.word = w ; 
	t.occur++ ; 
}

//==================================================================================================================
void addTerm (Index *i , Term t) { 
	Index * ptr_index = (Index *) malloc(sizeof(Index)) ; 
	(*ptr_index) -> word = t.word ;
	(*ptr_index) -> occur = t.occur ; 
	(*ptr_index) -> ptr_next = *i ; 
	i = ptr_index ; 		
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
int main () {
	printf ("%d\n" , text_nbchar("/home/mahenina/FIL_ROUGE/Test")) ;
} 
*/
