#include "BaseDesc.h"

SoundDesc * tests_writeSoundDesc(Bool details);

int main(){
	printf("-----------------Starting program------------------\n\n");
	BaseDesc bd;
	printf("Initializing the BaseDescriptor\n");
	initList(&bd);
	printf("Checking if the BaseDescriptor is empty :");	
	if(listIsEmpty(bd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	printf("Initializing the ListBaseDescriptor\n");
	ListBaseDesc lbd = NULL;
	printf("Checking if the ListBaseDescriptor is empty :");
	if(listIsEmpty(lbd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	printf("Add a new descriptor\n");
	addDesc(&bd, tests_writeSoundDesc(FALSE), SOUND);
	printf("Checking if the BaseDescriptor is not empty :");	
	if(!listIsEmpty(bd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	/*printf("Add a new file-descriptor\n");	
	addListBaseDesc(&lbd, "Mabite", 1564343131, 12315, SOUND);
	addListBaseDesc(&lbd, "MonPack", 156453431, 12315, SOUND);
	addListBaseDesc(&lbd, "Monpenis", 15643431, 12315, SOUND);
	addListBaseDesc(&lbd, "monEngin", 14546453431, 12315, SOUND);*/
	printf("Initialize the SoundListBase from the file\n");	
	lbd = initListBaseDesc(SOUND);
	printf("%d number\n", descExists(lbd, "Monpenis"));
	printf("Printing the SoundBaseDescriptor\n");
	printList(bd, SOUND);
	printf("Checking if the ListBaseDescriptor is not empty :");
	if(!listIsEmpty(lbd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	printf("\n----------------Program terminated-----------------\n\n");
}

//===================================================================================================
SoundDesc * tests_writeSoundDesc(Bool details)
{
	Bool testPassed = TRUE;
	SoundDesc *soundDesc;
	FILE* corpus = fopen("../../../../Ubuntu-Windows/corpus_m6.bin", "rb");	
	globs_windowSize = 4096;
	globs_nbInterval = 64;
	globs_maxFrequency = 1;
	globs_minFrequency = -1;
	soundDesc = createSoundDesc(corpus);
	soundDesc->address = 666;
	//printSoundDesc(soundDesc);
	//writeSoundDesc(testFile, soundDesc);
	//printf("Desc size %d", soundDescSize(soundDesc));
	//newSoundDesc = readSoundDesc(testFile);
	//printSoundDesc(newSoundDesc);
	fclose(corpus);
	return soundDesc;
}
