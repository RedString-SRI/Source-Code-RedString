

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void IndexationMenu();
void ResearchMenu();
void messageError(int i);
void mainMenu();
void clearBuffer();
//========================================================
void clearBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}
//========================================================
void messageError(int i) {
	switch(i) {
	case(0): printf("ERROR : error411\n\n"); break;
	case(1): printf("ERROR : Wrong choice\n\n"); break;
	case(2): printf("ERROR : Unexisting path\n\n"); break;
	case(3): printf("ERROR : Wrong option\n\n"); break;
	case(4): printf("ERROR : \n\n"); break;
	case(5): printf("ERROR : \n\n"); break;
	case(6): printf("ERROR : \n\n"); break;
	case(7): printf("ERROR : \n\n"); break;
	}
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
			messageError(1);
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
			messageError(1);
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	clearBuffer();
	switch(choice){
		case(1):
			system("clear");  
			break;
		case(2):  
			system("clear");
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		default: 
			messageError(0) ; 
			exit(0); 
			break;
	}
}
//========================================================
void ResearchMenu(){
	char a;
	char comm[6]="ls -";
	// FOR TESTING COMMAND UNIX
	int choice;
	
	do{
		printf("+=========================+\n");
		printf("|                         |\n");
		printf("|1. Research a word       |\n");
		printf("|2. Research a color      |\n");
		printf("|3. Research a sound      |\n");
		printf("|4. Test command UNIX     |\n");
		printf("|                         |\n");
		printf("+=================0.RETURN+\n");

		scanf("%d" , &choice);
		if(choice!=1 && choice !=2 && choice!=0 && choice!=4){
			system("clear");
			messageError(1);
		}
	}while(choice!=1 && choice!=2 && choice!=0 && choice!=4);
	clearBuffer();
	switch(choice){
		case(1):
			system("clear");  
			break;
		case(2):  
			system("clear");
			break;
		case(0): 
			system("clear");
			mainMenu(0); 
			break;
		case(4): 
			printf("Test command unix :");
			scanf("%c" , &a);
			strcat(comm,&a);
			system(comm); 
			// BIG PROBLEM !!!!!!!!!
			//    /!\ :/
			ResearchMenu();
			break;
		default: 
			messageError(0) ; 
			exit(0); 
			break;
	}
}
