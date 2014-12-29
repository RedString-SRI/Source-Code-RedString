/**
 * \file SoundDescriptor.c
 * \brief Sound desc manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file defines all functions available for sound descs.
 */

#include "SoundDescriptor.h"

double endianSwap_double(double dbl)
{
	char ch[SIZEDOUBLE];
	memcpy(ch, &dbl, SIZEDOUBLE);
	ch[0] ^= ch[7] ^= ch[0] ^= ch[7]; // Swap between ch[0] and ch[7]
	ch[1] ^= ch[6] ^= ch[1] ^= ch[6]; // Swap between ch[1] and ch[6]
	ch[2] ^= ch[5] ^= ch[2] ^= ch[5]; // Swap between ch[2] and ch[5]
	ch[3] ^= ch[4] ^= ch[3] ^= ch[4]; // Swap between ch[3] and ch[4]

	double dblRet;
	memcpy(&dblRet, ch, SIZEDOUBLE); 
	return dblRet;
}

SoundDescriptor * createSoundDesc(FILE* file)
{
	int doubleSize = sizeof(double),
		fSize = fileSize(file);
	double *tmp = malloc(sizeof(*tmp)),
		*intervalsThreshold = malloc(sizeof(*intervalsThreshold) * globs_nbInterval);
		
	SoundDescriptor * desc = malloc(sizeof(*desc));
	int iInterval, iElem, iWindow;	// Increments
	int nbWindows = (fSize / doubleSize) / globs_windowSize + 2;
	// (fSize / doubleSize)  is the number of values in the file
	// + 1 because : an interval : |-----| : There is two thresholds
	// another +1 for the ending NULL
	
	desc->histogram = malloc(sizeof(*desc->histogram) * nbWindows);
	
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
	while(readStruct(file, &tmp, doubleSize))
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
					//printf("%f", desc->histogram[iWindow][iInterval]);
					break;		
				}				
			}
			if(*tmp > intervalsThreshold[globs_nbInterval - 1])
				(desc->histogram[iWindow][globs_nbInterval - 1])++;
		}
		
		iElem++;
	}
	/** WHO THE FUCK EMITS THIS "INVALID ARGUMENT" ERROR MESSAGE?????? **/
	// perror("fin");
	free(tmp);
	free(intervalsThreshold);
	return desc;
}

void printSoundDesc(SoundDescriptor const * desc)
{
	int iInterval, iWindow = 0;
	printf("\nId: %d", desc->id);
	
	while(desc->histogram[iWindow] != NULL)
	{
		for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			printf("%d|", desc->histogram[iWindow][iInterval]);
		printf("\n");
		iWindow++;
	}
}

void writeSoundDesc(FILE* file, SoundDescriptor* desc)
{
	int iInterval, iWindow = 0;
	// Write desc->id
	writeStruct(file, &desc->id, sizeof(int));
	
	// Write desc->histogram
	while(desc->histogram[iWindow] != NULL)
	{
		writeStruct(file, &desc->histogram[iWindow], sizeof(int) * globs_nbInterval);
		iWindow++;
	}
}

SoundDescriptor * readSoundDesc(FILE* file)
{
	SoundDescriptor * desc = malloc(sizeof(*desc));
	int iElem, iWindow;	// Increments
	int nbWindows = (fileSize(file) / sizeof(double)) / globs_windowSize + 1;
	// (fSize / doubleSize)  is the number of values in the file
	// + 1 because : an interval : |-----| : There is two thresholds
	
	// Read desc->id
	readStruct(file, &desc->id, sizeof(int));
	
	desc->histogram = malloc(sizeof(*desc->histogram) * (nbWindows + 1));
	// another +1 for the ending NULL
	
	// Read desc->id
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
	{
		desc->histogram[iWindow] = malloc(sizeof(double) * globs_nbInterval);
		readStruct(file, &desc->histogram[iWindow], sizeof(int) * globs_nbInterval);
	}
	// Set NULL in the last one
	desc->histogram[iWindow] = NULL;

	return desc;
}