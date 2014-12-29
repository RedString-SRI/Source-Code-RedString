

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
			messageError(0) ; 
			exit(0); 
			break;
	}
}
//========================================================
void IndexationMenu(){
	int choice;
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. Enter your path       |\n");
		printf("|2. ????????              |\n");
		printf("|                         |\n");
		printf("+=================0.RETURN+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice !=2 && choice!=0){
			system("clear");
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	clearBuffer();
	switch(choice){
		case(1):
			printf("Enter your path : \n");
			scanf("%s" , w); // enter a path ......
			if(ExistingPath(w)){
				system("clear");
			}
			else 
				printf("ERROR Path\n");  
			break;
		case(2):  
			system("clear");
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
	char a;
	char w[];
	char freq;
	char comm[6]="ls -";
	// FOR TESTING COMMAND UNIX
	int choice;
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. Research a word       |\n");
		printf("|2. Research a color      |\n");
		printf("|3. Research a sound      |\n");
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
			printf("Enter your color : \n");
			scanf("%s" , w); // enter a word ......
			if(isAColor(w)){
				byColor(w);
				//system("clear");
			}
			else printf("ERROR Color\n");
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		case(3):
			printf("Enter your frequence : \n");
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
}
