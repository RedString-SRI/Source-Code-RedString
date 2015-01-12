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
	int choice;
	
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
			break;
		case(2):
			researchIMG();
			break;
		case(3):
			researchSound();
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
