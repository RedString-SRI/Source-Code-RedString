/**
 * \file Tester_Keyboard.c
 * \brief Tester of Keyboard functions
 * \author Morgan Chabaud \n
 */


#include "Keyboard.h"

int main()
{
	int t;
	if(1)//valeur_dans_stdin() == 1)
		printf("vide\n");
	else
		printf("plein\n");
	
	scanf("%d", &t);
	printf("My character : %d\n", t);
		emptyStdin();

	scanf("%d", &t);
	printf("My character : %d\n", t);
	
	if(valeur_dans_stdin() == 1)
		printf("vide\n");
	else
		printf("plein\n");
	emptyStdin();
	if(valeur_dans_stdin() == 1)
		printf("vide\n");
	else
		printf("plein\n");
}