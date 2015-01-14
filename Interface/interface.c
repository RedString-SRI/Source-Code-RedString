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


=======
>>>>>>> 1acd67cda2f5a004129f22e34a66296428690c1c

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
<<<<<<< HEAD
	char w[20];
	int validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath] , *pathOfList[maxSizePath];
=======
>>>>>>> 1acd67cda2f5a004129f22e34a66296428690c1c
	int choice;
	float *percent;
	float *positionFile;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *valDesc , tmpVD;
	PictureDesc imgDsc;
	SoundDesc sdDsc;
	TextDesx txtDsc;
	FILE *IMGbase;
	FILE *TXTbase;
	FILE *SOUNDbase;
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
			/*TXTbase=fopen("TextBaseDesc.db" , 'r');
			researchTXT
			fclose(TXTbase);
			system("clear");
			*/
			break;
		case(2):
			IMGbase=fopen("PictureBaseDesc.db" , 'r');
			researchIMG(IMGbase);
			fclose(IMGbase);
			system("clear");
			break;
		case(3):
			SOUNDbase=fopen("SoundBaseDesc.db" , 'r');
			researchSound(SOUNDbase);
			fclose(SOUNDbase);
			system("clear");
>>>>>>> 1acd67cda2f5a004129f22e34a66296428690c1c
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		default: // to secure
>>>>>>> 1acd67cda2f5a004129f22e34a66296428690c1c
			exit(0); 
			break;
	}
}

