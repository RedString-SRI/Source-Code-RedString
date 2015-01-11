#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IndexationMenu();
void ResearchMenu();
void mainMenu();
void clearBuffer();

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
			} while ( validPath == 1 )
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
	FILE *listBASE=fopen("listBAseDescriptor.txt" , 'r'); // NEED TO CHECK THE PATH HERE
	char a;
	char w[];
	char freq;
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
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		case(3):
			printf("Enter your path to compare : \n");
			scanf("%f" , &freq); // enter a frequence ......
			if(isAFreq){
				bySOUNDSOUNDSOUND(freq);
				system("clear");
			}
			else printf("ERROR Sound\n");
			break;
		default: 
			exit(0); 
			break;
	}
	fclose(listBASE);
}
