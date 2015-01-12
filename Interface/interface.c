/**
* \file interface.c
* \brief listing of research functions.
* \author Gabriel DEL REY
* \version 0.8
* \date 12 December 2014
*
* Interface User/Machine IMH
*
*/
#include "interface.h"


//========================================================
void clearBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}
//========================================================
void mainMenu(){
	int choice;
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. INDEXATION            |\n");
		printf("|                         |\n");
		printf("|2. RESEARCH              |\n");
		printf("|                         |\n");
		printf("+===================0.EXIT+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice !=2 && choice!=0){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	clearBuffer();
	switch(choice){
		case(1): 
			system("clear");
			IndexationMenu(); 
			break;
		case(2): 
			system("clear");
			ResearchMenu(); 
			break;
		case(0): 
			exit(0); 
			break;
		default: 
			exit(0); 
			break;
	}
}
//========================================================
void IndexationMenu(){
	int choice , validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath];
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|                         |\n");
		printf("|1. Enter your(s) path(s) |\n");
		printf("|                         |\n");
		printf("|                         |\n");
		printf("+=================0.RETURN+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice!=0){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	clearBuffer();
	switch(choice){
		case(1):
			printf("Add an empty path with \"Enter\" to start Indexation.\n");
			printf("Enter your(s) path(s) : \n");
			do {
				validPath = getKeyboard_String(path,0, maxSizePath);
				if(fileExists(path))
					/*SAVE path IN A TABLE OF PATH TO INDEX FORWARD ???? */
			} while ( validPath > 0 ) //while !0=NULL or !-1=so littre or !=-2=ERROR
			if(validPath==0)
				indexation(*path , .... ); /*PROBLEM INDEXATION ! I DON'T HOW IT'S WORK THE MULTI PARAMS */
			else
				fprintf(stderr,"Error name path\n");
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		default: 
			exit(0); 
			break;
	}
}
//========================================================
void ResearchMenu(){
	char w[20];
	int validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath] , *pathOfList[maxSizePath];
	int choice;
	long ID; int date i=0;
	float percent;
	float *positionFile;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *PilevalDesc , tmpVD;
	Val_Desc VD;
	IMGdesc imgDsc, tmpIdsc;
	SoundDesc sdDsc, tmpSdsc;
	TextDesx txtDsc , tmpTdsc;
	FILE *listBASE=fopen("listBAseDescriptor.txt" , 'r'); // NEED TO CHECK THE PATH HERE
	FILE *fileOfDesc;
	FILE *GivenPath;
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. Research a word       |\n");
		printf("|2. Research a color      |\n");
		printf("|3. Research similar sound|\n");
		printf("|                         |\n");
		printf("+=================0.RETURN+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice !=2 && choice!=0 && choice!=3){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0 && choice!=3);
	clearBuffer();
	switch(choice){
		case(1):
			printf("Enter your word : \n");
			scanf("%s" , w); // enter a word ......
			if(isAWord(w)){
				byOcurrenceWord(w);
				system("clear");
			}
			else printf("ERROR Word\n");
			break;
		case(2):
			do{
				printf("1. By named color ? \n");	
				printf("2. composants by composants ? \n");
				printf("+=================0.RETURN+\n");
				scanf("%d" , &choice);
			}while(choice!=1 && choice!=2 && choice!=0)
			if(choice==1) byNamedColor();
			else if(choice==2) cpsBYcps();
			else if(choice==0) ResearchMenu();
			break;
		case(3):
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
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		default: // to secure
			exit(0); 
			break;
	}
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
