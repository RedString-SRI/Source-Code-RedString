/**
* \file SearchEngine.h
* \brief listing of research functions.
* \author Gabriel DEL REY
* \version 0.1
* \date 7 December 2014
*
* All the way to do research in the listeBaseDesc
*
*/
//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR IMAGE========================================
//===================================================================================================
void byColor(COLOR c){
  
  float *OrderPercentage;
  float percent , tmpFloat;
  int iThPath = 0;
  int size=0, i , tmpInt;
  char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
  
  while(/*PAS FIN LISTE BASE desc*/) {
  	iThPath++; // can read the Ith file of the desc base
  	percent = findColor(path , colorDecimal) // NEED TO CREAT THIS FUNCTION !!!!;
    if(percent) { 
    	*OrderPercentage = (int*)malloc(sizeof(int)); // add the new percentage of the associate file // FLOAT ???
    	size++;
    	**OrderPercentage = (int**)malloc(sizeof(int*)): // add in the same colomn the number if the Ith file of the desc base :
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
  
  //+=========================+ print list
  printf("+=========================+\n");
  for(i=1 ; i<=size ; i++)
    printf("%2i : %20s --> %.2f\n" , i , path , orderPercentage[i] );
  printf("+===================0.EXIT+\n");
  printf("DoYou want to open it one ? Which one ? \n");
  scanf("%d" , &i); // now, "i" is a choice
  if(i<0 || i>size) printf("ERROR choice\n");
  else // OPEN THE FILE §§§§§!! !!!!!!
  if(i=0) ResearchMenu() ;
}
//===================================================================================================
float compareFileIMG(FILE *file1 , FILE *file2){
  Dimension size1 , size2;
  float percentCompare;
  int max=pow(2,3*globs_nbWeightyBits);
  float histo1[max] , histo2[max] , compare[max];
  int i=0;
  
  //read sizes
  fscanf(file1 , "%d" , size1->height); fscanf(file1 , "%d" , size1->width);
  fscanf(file2 , "%d" , size2->height); fscanf(file2 , "%d" , size2->width);
  
  //read percentage histograms
  while(!foef(file1) && !foef(file2) && i<max ) { //3 end steps to be secure
    fscanf(file1 , "%f" , histo1+i);
    fscanf(file2 , "%f" , histo2+i);
    if (histo[i]>histo2[i]) compare[i] = 1-histo1[i]/histo2[i] ;
    else compare[i] = 1-histo2[i]/histo1[i] ;
    percentCompare+=compare[i]; // add every compare+i to be divide by the number of cells (max)
    i++;
  }
  return percentCompare/max ;
}
//========================================================
void byNamedColor(){
	COLOR c;
	int choice;
	
	do{
		printf("Enter your COLOR : \n");
			scanf("%s" , c); // enter a word ......
			if(isAColor(w))
				byColor(w);
			else {
				printf("ERROR Color\n");
				printf("Color possible : BLACK , DARKGRAY , LIGHTGRAY , WHITE , RED , PINK , YELLOW , PURPLE , BROWN , GREEN , LIGHTGREEN , BLUE , LIGHTBLUE\n");
			}
	}while(!isAColor(w));
}
//========================================================
Bool isAColor(char c[]){
	if(strcomp(c,BLACK)) byColor(BLACK); 
        else if(strcomp(c,"LIGHTGRAY")) 	byColor(LIGHTGREY); 
        else if(strcomp(c,"DARKGRAY")) 		byColor(DARKGREY);
        else if(strcomp(c,"WHITE")		byColor(WHITE); 
        else if(strcomp(c,"RED")) 		byColor(RED);
        else if(strcomp(c,"PINK")) 		byColor(PINK);
        else if(strcomp(c,"YELLOW")) 		byColor(YELLOW);
        else if(strcomp(c,"PURPLE")) 		byColor(PURPLE); 
        else if(strcomp(c,"BROWN")) 		byColor(BROWN); 
        else if(strcomp(c,"GREEN")) 		byColor(GREEN); 
        else if(strcomp(c,"LIGHTGREEN")) 	byColor(LIGHTGREEN);
        else if(strcomp(c,"BLUE")) 		byColor(BLUE);
        else if(strcomp(c,"LIGHTBLUE")) 	byColor(LIGHTBLUE);
        else return FALSE;
        return TRUE;
}
//========================================================
void cpsBYcps(){
	COLOR c;
	printf("Value possible : 11 , 10 , 01 , 00 \n");
	printf("Enter RED composants :\n");
	scan("%d" , &c);
	if(c!=11||c!=10||c!=01) c=0;
	c = c<<(glob_nbWeightyBits);
	printf("Enter GREEN composants :\n");
	scan("%d" , &c);
	if(c!=11||c!=10||c!=01) c=0;
	c = c<<(glob_nbWeightyBits);
	printf("Enter BLUE composants :\n");
	scan("%d" , &c);
	if(c!=11||c!=10||c!=01) c=0;
	c = c<<(glob_nbWeightyBits);
	
	byColor(c);
}
//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR TEXT ========================================
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
void byOccurenceWord(char word[] ){
  
 int *OrderOcurr;
  int colorDecimal = (int)color; // NEED TO BE CHECK !!!!!!
  int wordOcurr ; 
  int iThPath = 0;
  int size=0, i , tmpInt;
  while(/*PAS FIN LISTE BASE desc*/) {
  	iThPath++; // can read the Ith file of the desc base
  	wordOcurr = findWord(path , colorDecimal) // NEED TO CREAT THIS FUNCTION !!!!;
    if(wordOcurr) { 
    	*OrderOcurr = (int*)malloc(sizeof(int)); // add the new percentage of the associate file
    	size++;
    	**OrderOcurr = (int**)malloc(sizeof(int*)): // add in the same colomn the number if the Ith file of the desc base :
    	// Matrix 2xN  percent | ... | ...
    	//			  Ith file | ... | ...
  		for(i=0 ; i<size ; i++){ // In order
  			if(wordOcurr > orderOcurr[i] ) { // switch for inserting in order
  				tmpInt=wordOcurr ; wordOcurr=orderOcurr[i] ; orderOcurr[i]=tmpInt; // switch Percentage
  				tmpInt=iThPAth ; iThPAth=orderOcurr[1][i]= ; orderOcurr[1][i]=tmpInt; // switch the number of the file
  			}
  		}
    }
  }
  
  //+=========================+ print list
  printf("+=========================+\n");
  for(i=1 ; i<=size ; i++)
    printf("%2i : %20s --> %.2d\n" , i , path , orderOccur[i] );
  printf("+===================0.EXIT+\n");
  printf("You want to open it one ? Which one ? \n");
  scanf("%d" , &i); // now, "i" is a choice
  if(i<0 || i>size) printf("ERROR choice\n");
  if(i=0) ResearchMenu() ;
}
//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR SOUND========================================
//===================================================================================================
void bySound(){
	//INIT ?
	
	printf("Enter your path to compare : \n");
	validPath = getKeyboard_String(path,0, maxSizePath);
	if(fileExists(path)){
		ID=getID(path);
		sdDesc=getDesc(listeBASE , ID , SOUND); // ???? NEED CHECKING <==============
		while(!feof(listeBASE)){
		// NEED TO CLEAR PATH BEFORE ?????????????????
			fscanf(listeBASE , "%l" , &ID );
			fscanf(listeBASE , "%s" , pathOfList); // Search the iTh path of the ListBASE
			fscanf(listeBASE , "%d" , &date );
			fileOfDesc=getDesc(listeBASE , ID , SOUND); // open the link of the linked descript
			percent=compareSoundDesc(sdDesc , fileOfDesc );
			addOrderVD(*PilevalDesc , percent , pathOfList); // add in decrease Order
			i++;
		}
		fclose(listeBASE);
		printf("+=========================+\n");
		printBestList(PilevalDesc , 0)
		printf("+=================0.RETURN+\n");
		printf("DoYou want to open it one ? Which one ? \n");
  		scanf("%d" , &choice); // now, "i" is a choice
  		if(choice<0 || choice>i) printf("ERROR choice\n");
  		else {
	  		strcat(openPath , getChoosenFile(PilevalDesc,choice));
 			system(openPath);
 		}
	}
	else printf("ERROR Sound\n");
}
//========================================================
void addOrderVD(PileVD *pvd, float perct , char nFile){	
	PileVD tmpPdv;
	
	if(((*pvd)->pct) < perct)
			tmpPvd = (PileVD)malloc(sizeof(Val_Desc));
			tmpPvd.pct = perct;
			strcpy(tmpPdv.nameFile, nFile);
			tmpPvd->NextVD= *pvd;
			*pvd=tmpVD;
	else {
		if(((*pvd)->NextVD).pct <= perct){
			tmpPvd = (PileVD)malloc(sizeof(Val_Desc));
			tmpPvd.pct = perct;
			strcpy(tmpPdv.nameFile, nFile);
			tmpPvd->NextVD = (*pvd)->NextVD;
			(*pvd)->NextVD=tmpPvd;
		}
		else addOrderVD( &((*pvd)->NextVD) , perct , nFile ); 
	}		
}
//========================================================
void printBestList(PileVD pvd , j){ //récursif
	if(pvd==NULL) return;
	printf("%3d. %30s --> %.2f" , j+1 , pvd.nameFile , pvd.pct*100 )
	printBestList(pvd , j+1);
}
//========================================================
char *getChoosenFile(PileVD PilevalDesc,int choice){
	if(choice==0) return PilevalDasc.nameFile ;
	else getChoosenFile( PilevalDesc, choice-1);
}
