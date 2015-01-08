/**
 * \file SoundDesc.c
 * \brief Sound desc manager
 * \author Morgan Chabaud
 * 
 * This file defines all functions available for sound descs.
 */

#include "SoundDesc.h"

//===================================================================================================
double endianSwap_double(double dbl)
{
	char ch[SIZEDOUBLE];
	double dblRet;
	
	memcpy(ch, &dbl, SIZEDOUBLE);
	ch[0] ^= ch[7] ^= ch[0] ^= ch[7]; // Swap between ch[0] and ch[7]
	ch[1] ^= ch[6] ^= ch[1] ^= ch[6]; // Swap between ch[1] and ch[6]
	ch[2] ^= ch[5] ^= ch[2] ^= ch[5]; // Swap between ch[2] and ch[5]
	ch[3] ^= ch[4] ^= ch[3] ^= ch[4]; // Swap between ch[3] and ch[4]

	memcpy(&dblRet, ch, SIZEDOUBLE); 
	return dblRet;
}
//===================================================================================================
SoundDesc * createSoundDesc(FILE* file)
{
	int doubleSize = sizeof(double),
		fSize = fileSize(file);
	double *tmp = malloc(sizeof(*tmp)),
		*intervalsThreshold = malloc(sizeof(*intervalsThreshold) * globs_nbInterval);
		
	SoundDesc * desc = malloc(sizeof(*desc));
	int iInterval, iElem, iWindow;	// Increments
	int nbWindows = (fSize / doubleSize) / globs_windowSize + 2;
	// (fSize / doubleSize)  is the number of values in the file
	// + 1 because : an interval : |-----| : There is two thresholds
	// another +1 for the ending NULL
	
	desc->nbWindows = nbWindows;
	desc->histogram = malloc(sizeof(int*) * nbWindows);

	for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
	{
		/* We want to know percentages of the interval value between globs_maxFrequency and globs_minFrequency,
		 * Let's say a is globs_minFrequency and b is globs_maxFrequency:
		 * --------a----------b--------
		 * But, 0 < a < b or
		 * 	a < 0 < b or
		 * 	a < b < 0	(We've excluded operators "<=")
		 * So we want to store percentages of this interval value in intervalsThreshold.
		 * Example:
		 * 	globs_nbInterval = 3;
		 * 	globs_minFrequency = -4;
		 * 	globs_maxFrequency = 2;
		 * 	So we want intervalsThreshold[0] = 1/3 of the interval between min and max frequency when positioning at min
		 * 					 = (1/3) * (max - min) + min
		 * 					 = -2
		 * 		intervalsThreshold[1] = 2/3 of the interval between min and max frequency when positioning at min
		 * 				      = (2/3) * (max - min) + min
		 * 				      = 0
		 * 		intervalsThreshold[2] = 3/3 ....
		 * 				      = 2
		 */
		intervalsThreshold[iInterval] = ((iInterval + 1) / (double)globs_nbInterval) * (globs_maxFrequency - globs_minFrequency)
					+ globs_minFrequency;
	}
	
	// Initialise the histogram with zeros
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
	{
		desc->histogram[iWindow] = malloc(sizeof(int) * globs_nbInterval);

		for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			desc->histogram[iWindow][iInterval] = 0;
	}
	// The last iWindow is going to be set to NULL
	// in order to be able to read this array without its size
	// (globs_nbInterval is a global variable...)
	//
	// Why not have looped with (iWindow < (nbWindows - 1))?
	// To avoid the calculous in a potentially large loop
	free(desc->histogram[iWindow - 1]);
	desc->histogram[iWindow - 1] = NULL;
	
	iElem = iWindow = iInterval = 0;
	while(readStruct(file, tmp, doubleSize))
	{
		if(iElem == globs_windowSize)
		{
			iElem = 0;
			iWindow++;
		}
		// Test file is not in the not in the same endian system as the testing system.
		*tmp = endianSwap_double(*tmp);
		if(*tmp <= intervalsThreshold[0])
			(desc->histogram[iWindow][0])++;
		else
		{
			for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			{
				if(*tmp <= intervalsThreshold[iInterval])
				{
					(desc->histogram[iWindow][iInterval])++;
					break;		
				}				
			}
			if(*tmp > intervalsThreshold[globs_nbInterval - 1])
				(desc->histogram[iWindow][globs_nbInterval - 1])++;
		}
		
		iElem++;
	}

	free(tmp);
	free(intervalsThreshold);
	return desc;
}
//===================================================================================================
int soundDescSize(SoundDesc const * desc)
{
	int size = 0;
	size += sizeof(desc->address);
	size += sizeof(desc->nbWindows);
	size += sizeof(int) * globs_nbInterval * (desc->nbWindows - 1);
	size += sizeof(int *);
	
	return size;
}
//===================================================================================================
void printSoundDesc(SoundDesc const * desc)
{
	int iInterval, iWindow, nbWindows = desc->nbWindows - 1;
	// -1 to stop before desc->histogram[iWindow] == NULL
	printf("\nId: %ld", desc->address);
	
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
	{
		for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			printf("%d|", desc->histogram[iWindow][iInterval]);
		printf("\n");
	}
}
//===================================================================================================
void writeSoundDesc(FILE* file, SoundDesc* desc)
{
	int iInterval, iWindow, nbWindows = desc->nbWindows - 1;
	// -1 to stop before desc->histogram[iWindow] == NULL
	
	// Write desc->address
	writeStruct(file, &desc->address, sizeof(desc->address));
	
	// Write desc->nbWindows
	writeStruct(file, &desc->nbWindows, sizeof(int));

	// Write desc->histogram
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
		writeStruct(file, desc->histogram[iWindow], sizeof(int) * globs_nbInterval);
	writeStruct(file, &desc->histogram[iWindow], sizeof(int*));
}
//===================================================================================================
SoundDesc * readSoundDesc(FILE* file)
{
	SoundDesc * desc = malloc(sizeof(*desc));
	const int histUpperSize = 5;	// The increment for array histogram
	int iElem, iWindow;	// Increments
	int nbWindows;
	

	// Read desc->address
	readStruct(file, &desc->address, sizeof(desc->address));
	
	// Read desc->nbWindows
	readStruct(file, &desc->nbWindows, sizeof(int));
	nbWindows = desc->nbWindows - 1;
	// -1 to stop before desc->histogram[iWindow] == NULL
	
	desc->histogram = malloc(sizeof(int*) * desc->nbWindows);
	// Note that we allocate space for desc->nbWindows
	// (including NULL) and not nbWindows just declared
	
	// Read desc->id
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
	{
		desc->histogram[iWindow] = malloc(sizeof(int) * globs_nbInterval);
		readStruct(file, desc->histogram[iWindow], sizeof(int) * globs_nbInterval);
	}

	// Set NULL in the last one
	desc->histogram[iWindow] = NULL;
	
	return desc;
}
