/**
* \file SearchEngine.h
* \brief listing of research functions.
* \author Gabriel DEL REY
* \version 0.1
* \date 7 December 2014
*
* All the way to do research in the listeBaseDescriptor
*
*/

void byColor(char color[]){
  int *OrderPercentage;
  int colorDecimal = (int)color; // NEED TO BE CHECK !!!!!!
  float percent , tmpFloat;
  int iThPath = 0;
  int size=0, i , tmpInt;
  while(/*PAS FIN LISTE BASE DESCRIPTOR*/) {
  	iThPath++; // can read the Ith file of the descriptor base
  	percent = findColor(path , colorDecimal) // NEED TO CREAT THIS FUNCTION !!!!;
    if(percent) { 
    	*OrderPercentage = (int*)malloc(sizeof(int)); // add the new percentage of the associate file
    	size++;
    	**OrderPercentage = (int**)malloc(sizeof(int*)): // add in the same colomn the number if the Ith file of the descriptor base :
    	// Matrix 2xN  percent | ... | ...
    	//			  Ith file | ... | ...
  		for(i=0 ; i<size ; i++){ // In order
  			if(percent > orderPercentage[i] ) { // switch for inserting in order
  				tmpFloat=percent ; percent=orderPercentage[i] ; orderPercentage[i]=tmpFloat; // switch Percentage
  				tmpInt=iThPAth ; iThPAth=orderPercentage[1][i]= ; orderPercentage[1][i]=tmpInt; // switch the number of the file
  			}
  		}
    }
  }
  // print list
  for(i=1 ; i<=size ; i++)
  	printf("%2i : %20s --> %.2f\n" , i , path , orderPercentage[i] );
  printf("+===================0.EXIT+\n");
  printf("You want to open it one ? Which one ? \n");
  scanf("%d" , &i); // now, "i" is a choice
  if(i<0 || i>size) printf("ERROR choice\n");
  if(i=0) ResearchMenu() ;
}
//===================================================================================================
void byAuthor(){

}
//===================================================================================================
void byModifDate(){

}
//===================================================================================================
void byCreatingDate(){

}
//===================================================================================================
void byNameFile(){

}
//===================================================================================================
void byOccurenceWord(){

}
//===================================================================================================
void bySOUNDSOUNDSOUND(){

}
