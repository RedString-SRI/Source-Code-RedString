#include "BaseDesc.h"
#include "Configurator.h"

SoundDesc * tests_writeSoundDesc(Bool details);
PictureDesc * tests_writePictureDesc();

int main(){
	printf("-----------------Starting program------------------\n\n");
	printf("Initializing Config file \n");
	initConfigurator();
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
	addDesc(&bd, tests_writePictureDesc(), PICTURE);
	printf("Checking if the BaseDescriptor is empty :");	
	if(listIsEmpty(bd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	printf("Initialize the SoundBase from the file\n");
	/*bd = initBaseDesc(SOUND);
	printf("Checking if the BaseDescriptor is not empty :");	
	if(!listIsEmpty(bd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	*/printf("Add a new file-descriptor\n");	
	addListBaseDesc(&lbd, "element1", 1564343131, 124315, SOUND);
	addListBaseDesc(&lbd, "element2", 156453431, 1231, SOUND);
	addListBaseDesc(&lbd, "element3", 15643431, 1231755, SOUND);
	addListBaseDesc(&lbd, "element4", 14546453431, 123515, SOUND);
	printf("Initialize the SoundListBase from the file\n");	
	/*lbd = initListBaseDesc(SOUND);*/
	printf("%d number\n", descExists(lbd, "element1"));
	lbd = NULL;
	lbd = initListBaseDesc(SOUND);
	/*printf("Printing the SoundBaseDescriptor\n");
	printList(bd, SOUND);*/
	printf("Checking if the ListBaseDescriptor is not empty :");
	if(!listIsEmpty(lbd))
		printf(" OK\n");
	else
		printf(" NOK\n");
	/*removeDesc(&bd, SOUND);
	printf("Checking if the BaseDescriptor is empty :");	
	if(listIsEmpty(bd))
		printf(" OK\n");
	else
		printf(" NOK\n");*/
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

PictureDesc * tests_writePictureDesc(){
	FILE* file = fopen("text.txt", "r");
	if(file == NULL){
		printf("hdsgfdgsufgs");
		fflush(stdout);
	}
	PictureDesc * pict;	
	pict = createPictureDesc(file);
		printf("hdsgfdgsufgs");
	fflush(stdout);
	fclose(file);
	return pict;
}
