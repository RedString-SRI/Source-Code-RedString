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

#include<ctype.h>
#include "SearchEngine.h"
#include "SoundSearch.h"

extern int globs_nbWeightyBits;

//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR IMAGE========================================
//===================================================================================================

void byColor(COLOR c, FILE *imgbase){
/*
  float *OrderPercentage;
  float percent , tmpFloat;
  int iThPath = 0;
  int size=0, i , tmpInt;
  char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
  
  while(!feof(imgbase)) {
  	iThPath++; // can read the Ith file of the desc base
  	percent = findColor(path , colorDecimal) // NEED TO CREAT THIS FUNCTION !!!!;
    if(percent) { 
    	*OrderPercentage = (float*)malloc(sizeof(float)); // add the new percentage of the associate file // FLOAT ???
    	size++;
    	**OrderPercentage = (float**)malloc(sizeof(float*)): // add in the same colomn the number if the Ith file of the desc base :
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
  printf("Do you want to open it one ? Which one ? \n");
  scanf("%d" , &i); // now, "i" is a choice
  if(i<0 || i>size) printf("ERROR choice\n");
  else // OPEN THE FILE §§§§§!! !!!!!!
  if(i==0) ResearchMenu() ;
 */
}

//===================================================================================================
float compareFileIMG(PictureDesc *imgD1 , PictureDesc *imgD2){
  float percentCompare;
  int max , i;
  float compare[max];
  
  // To don't have memories overflowing 
  if(imgD1->nbcomp<imgD2->nbcomp)
  	max=pow(2,(imgD1->nbcomp)*globs_nbWeightyBits);
  else
  	max=pow(2,(imgD2->nbcomp)*globs_nbWeightyBits);
  for(i=0; i<max ; i++){
    if ((imgD1->histogram[i])>(imgD2->histogram[i])) compare[i] = 1-imgD1->histogram[i]/imgD2->histogram[i] ;
    else compare[i] = 1-imgD1->histogram[i]/imgD2->histogram[i] ;
    percentCompare+=compare[i]; // add every compare+i to be divide by the number of cells (max)
  }
  return percentCompare/max ;
}
//========================================================
void byNamedColor(FILE *imgbase){
/*
	int choice , i;
	char w[20];
	do{
		printf("Enter your COLOR : \n");
			scanf("%d" , w); // enter a word ......
			while(w[i]){ toupper(w[i]) ; i++;}
			if(isAColor(w))
				byColor(w,imgbase);
			else {
				printf("ERROR Color\n");
				printf("Color possible : BLACK , DARKGRAY , LIGHTGRAY , WHITE , RED , PINK , YELLOW , PURPLE , BROWN , GREEN , LIGHTGREEN , BLUE , LIGHTBLUE\n");
			}
	}while(!isAColor(w));
*/
}
//========================================================
Bool isAColor(char c[]){
		if(strcomp(c,"BLACK")) 				byColor(BLACK); 
        else if(strcomp(c,"LIGHTGRAY")) 	byColor(LIGHTGRAY); 
        else if(strcomp(c,"DARKGRAY")) 		byColor(DARKGRAY);
        else if(strcomp(c,"WHITE"))			byColor(WHITE); 
        else if(strcomp(c,"RED")) 			byColor(RED);
        else if(strcomp(c,"PINK")) 			byColor(PINK);
        else if(strcomp(c,"YELLOW")) 		byColor(YELLOW);
        else if(strcomp(c,"PURPLE")) 		byColor(PURPLE); 
        else if(strcomp(c,"BROWN")) 		byColor(BROWN); 
        else if(strcomp(c,"GREEN")) 		byColor(GREEN); 
        else if(strcomp(c,"LIGHTGREEN")) 	byColor(LIGHTGREEN);
        else if(strcomp(c,"BLUE")) 			byColor(BLUE);
        else if(strcomp(c,"LIGHTBLUE")) 	byColor(LIGHTBLUE);
        else return FALSE;
        return TRUE;

}
//========================================================
void researchIMG(FILE *imgbase){
	int validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath] , *pathOfList[maxSizePath];
	int choice;
	long ID; 
	int date, i=0;
	float percent;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *PilevalDesc , tmpVD;
	Val_Desc VD;
	PictureDesc *imgDsc, tmpIdsc;
	FILE *fileOfDesc;
	FILE *GivenPath;
	
			do{
				printf("1. By named color ? \n");	
				printf("2. by compare file ? \n");
				printf("+=================0.RETURN+\n");
				scanf("%d" , &choice);
			}while(choice!=1 && choice!=2 && choice!=0);
			
			if(choice==1) byNamedColor(imgbase);
			else if(choice==2){
				ID=getAddress(imgbase,path);
				imgDsc=getDesc(imgbase , ID , PICTURE);
				while(!feof(imgbase)){
				// NEED TO CLEAR PATH BEFORE ?????????????????
					fscanf(imgbase , "%l" , &ID );
					fscanf(imgbase, "%s" , pathOfList); // Search the iTh path of the ListBASE
					fscanf(imgbase , "%d" , &date );
					fileOfDesc=getDesc(imgbase , ID , SOUND); // open the link of the linked descript
					percent=compareFileIMG(imgDsc , fileOfDesc );
					addOrderVD(*PilevalDesc , percent , pathOfList); // add in decrease Order
					i++;
				}
				printf("+=========================+\n");
				printBestList(PilevalDesc , 0);
				printf("+=================0.RETURN+\n");
				printf("DoYou want to open it one ? Which one ? \n");
  				scanf("%d" , &choice); // now, "i" is a choice
  				if(choice<0 || choice>i) printf("ERROR choice\n");
  				else {
  					strcat(openPath , getChoosenFile(PilevalDesc,choice));
  					system(openPath);
  				}
			}
			else ResearchMenu();
}
//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR TEXT ========================================
//===================================================================================================
/* BETA TEST <---------
void byOccurenceWord(char word[] ){
  
 int *OrderOcurr;
  int colorDecimal = (int)color; // NEED TO BE CHECK !!!!!!
  int wordOcurr ; 
  int iThPath = 0;
  int size=0, i , tmpInt;
  while(/*PAS FIN LISTE BASE desc/) {
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
void researchTXT(FILE *txtbase){
	char w[20];
	int validPath;
	int const maxSizePath = 100;
	char path[maxSizePath] , pathOfList[maxSizePath];
	int choice;
	long ID; int date;
	float percent;
	float *positionFile;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *PilevalDesc , tmpVD;
	Val_Desc VD;
	TextDesc txtDsc , tmpTdsc;
	FILE *listBASE=fopen("listBAseDescriptor.txt" , 'r'); // NEED TO CHECK THE PATH HERE
	FILE *fileOfDesc;
	FILE *GivenPath;
	BaseDesc BDimg , BDsound , BDtxt;
}*/
//===================================================================================================
//==============================ASSOCIATED RESEARCH FOR SOUND========================================
//===================================================================================================
void researchSound(FILE *soundbase){
	int validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath] , *pathOfList[maxSizePath];
	int choice;
	long ID; int date, i=0;
	float percent;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *PilevalDesc;
	SoundDesc *sdDesc, tmpSdsc;
	FILE *fileOfDesc;
	FILE *GivenPath;
	
	printf("Enter your path to compare : \n");
		do {
			validPath = getKeyboard_String(path,0, maxSizePath);
			if(!fileExists(path)) printf("This file don\'t exist\n");
		} while (!fileExists(path) && validPath!=0);
		if(!validPath) ResearchMenu();
		else{
			ID=getAddress(soundbase,path);
			sdDesc=getDesc(soundbase , ID , SOUND);
			while(!feof(soundbase)){
			// NEED TO CLEAR PATH BEFORE ?????????????????
				fscanf(soundbase , "%l" , &ID );
				fscanf(soundbase, "%s" , pathOfList); // Search the iTh path of the ListBASE
				fscanf(soundbase , "%d" , &date );
				fileOfDesc=getDesc(soundbase , ID , SOUND); // open the link of the linked descript
				percent=compareSoundDesc(sdDesc , fileOfDesc );
				addOrderVD(PilevalDesc , percent , pathOfList); // add in decrease Order
				i++;
			}
			fclose(soundbase);
			printf("+=========================+\n");
			printBestList(PilevalDesc , 0);
			printf("+=================0.RETURN+\n");
			printf("DoYou want to open it one ? Which one ? \n");
  			scanf("%d" , &choice); // now, "i" is a choice
  			if(choice<0 || choice>i) printf("ERROR choice\n");
  			else {
  				strcat(openPath , getChoosenFile(PilevalDesc,choice));
  				system(openPath);
  			}
		}
}
//========================================================
void addOrderVD(PileVD *pvd, float perct , char nFile){	
	PileVD tmpPvd;
	
	if(((*pvd)->pct) < perct){
			tmpPvd = (PileVD)malloc(sizeof(Val_Desc));
			tmpPvd->pct = perct;
			strcpy(tmpPvd->nameFile, nFile);
			tmpPvd->NextVD = *pvd;
			*pvd=tmpPvd;
	}
	else {
		if(((*pvd)->NextVD)->pct <= perct){
			tmpPvd = (PileVD)malloc(sizeof(Val_Desc));
			tmpPvd->pct = perct;
			strcpy(tmpPvd->nameFile, nFile);
			tmpPvd->NextVD = (*pvd)->NextVD;
			(*pvd)->NextVD=tmpPvd;
		}
		else addOrderVD( &((*pvd)->NextVD) , perct , nFile ); 
	}		
}
//========================================================
void printBestList(PileVD pvd ,int j){ //récursif
	if(pvd==NULL) return;
	printf("%3d. %30s --> %.2f" , j+1 , pvd->nameFile , (pvd->pct)*100 );
	printBestList(pvd , j+1);
}
//========================================================
char *getChoosenFile(PileVD PilevalDesc,int choice){ // return the nTh name of the Pile of file, to can open it easier.
	if(choice==0) return PilevalDesc->nameFile ;
	else getChoosenFile( PilevalDesc, choice-1);
}
