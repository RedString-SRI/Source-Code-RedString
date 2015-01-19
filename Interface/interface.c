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
#include "Configurator.h"


//========================================================
void clearBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}
//========================================================
void mainMenu(){
	int choice;
	
	
	system("clear");
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. INDEXATION            |\n");
		printf("|                         |\n");
		printf("|2. RESEARCH              |\n");
		printf("|                         |\n");
		printf("|3. parameters            |\n");
		printf("+===================0.EXIT+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice !=2 && choice!=0 && choice!=3){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0 && choice!=3);
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
		case(3): 
			system("clear");
			if(enterGlobsVariables(CONF_FILE_NAME)) printf("Succesfull saved parameters.\n");
			else printf("FAIL saved parameters...\n");
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
	FileType filetype;
	FILE *fileTOindex;
	BaseDesc basedesc;
	initList(&basedesc);
	void *desc;
	initBaseDesc(basedesc);
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. Index a SOUND         |\n");
		printf("|2. Index an IMAGE        |\n");
		printf("|3. Index a TEXT          |\n");
		printf("|                         |\n");
		printf("+=================0.RETURN+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice!=0 && choice!=2 && choice!=3){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	clearBuffer();
	
	do{
		printf("Add an empty path with \"Enter\" to start Indexation.\n");
		printf("Enter your(s) path(s) : \n");
		validPath = getKeyboard_String(path,0, maxSizePath);
		if(fileExists(path)){
			fileTOindex=fopen(path,"r");
			if(fileTOindex==NULL){ printf("FAIL !\n"); fflush(stdout) ; exit(0);}
			switch(choice){
				case(1):			 
					addDesc(basedesc,createSoundDesc(fileTOindex),SOUND);
				break;
				case(2):			
					addDesc(basedesc,createPictureDesc(fileTOindex),PICTURE);
				break;
				case(3):			
					/*desc=createTextDesc(fileTOindex); 
					basedesc=;
					addDesc(basedesc,desc,TEXT);*/
				break;
				case(0): 
					system("clear");
					mainMenu(); 
				break;
				default: 
					exit(0); 
				break;
			}
			fclose(fileTOindex);
			strcpy(path,""); // Permite to  secure the next path to enter by the user
			printf("Succesfull indexation.\n");
		}
		else{
			system("clear");
			printf("Error, file don\'t exists\n");
			mainMenu();
		}				
	} while ( validPath > 0 ); //while !0=NULL or !-1=so littre or !=-2=ERROR
	mainMenu();
}
//========================================================
void ResearchMenu(){

	char w[20];
	int validPath;
	int const maxSizePath = 100;
	char *path[maxSizePath] , *pathOfList[maxSizePath];
	int choice;
	float *percent;
	float *positionFile;
	char openPath[50]="xdg-open"; // Permite to default open file ex: xdg-open img.png
	
	PileVD *valDesc , tmpVD;
	PictureDesc imgDsc;
	SoundDesc sdDsc;
	//TextDesc txtDsc;
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
			if(!fileExists("PictureBaseDesc.db"))printf("PictureBaseDesc.db don\'t exists\n");
			else{
				IMGbase=fopen("PictureBaseDesc.db" , 'r');
				researchIMG(IMGbase);
				fclose(IMGbase);
			}
			system("clear");
			ResearchMenu();
			break;
		case(3):
			if(!fileExists("PictureBaseDesc.db"))printf("PictureBaseDesc.db don\'t exists\n");
			else{
				SOUNDbase=fopen("SoundBaseDesc.db" , 'r');
				researchSound(SOUNDbase);
				fclose(SOUNDbase);
			}
			system("clear");
			ResearchMenu();
			break;
		case(0): 
			system("clear");
			mainMenu(); 
			break;
		default: // to secure
			exit(0); 
			break;
	}
	mainMenu();
}

