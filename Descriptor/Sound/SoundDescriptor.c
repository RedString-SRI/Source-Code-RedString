/**
 * \file SoundDescriptor.c
 * \brief Sound descriptor manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file defines all functions available for sound descriptors.
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

SoundDescriptor * createDescriptor(FILE* file)
{
	int doubleSize = sizeof(double),
		fSize = fileSize(file);
	double *tmp = malloc(sizeof(double)),
		*intervalsThreshold = malloc(sizeof(double) * globs_nbInterval);
		// + 1 because : an interval : |-----| : There is two thresholds
	SoundDescriptor * descriptor = malloc(sizeof(SoundDescriptor));
	int iInterval, iElem, iWindow;	// Increments
	int nbWindows = (fSize / doubleSize) / globs_windowSize + 1;
	// (fSize / doubleSize)  is the number of values in the file
	//printf("____%d____", nbWindows);
	descriptor->histogram = malloc(sizeof(*descriptor->histogram) * nbWindows);
	
	for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
	{
		//===========================================================================================================================================================================================================================================================================================================================
		//////////////////////////////////// NEEEEEEEEDDDDDDDDDDDSSSSSSSSSSSS TOOOOOOOOO BEEEEEEEEEEE EXPLAINEDDDDDDDDDD
		intervalsThreshold[iInterval] = ((iInterval + 1) / (double)globs_nbInterval) * (globs_maxFrequency - globs_minFrequency)
					+ globs_minFrequency;
		//printf("\nintervalsThreshold : %f", intervalsThreshold[iInterval]);
	}
	
	// Initialise the histogram with zeros
	for(iWindow = 0; iWindow < nbWindows; iWindow++)
	{
		descriptor->histogram[iWindow] = malloc(sizeof(double) * globs_nbInterval);
		for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			descriptor->histogram[iWindow][iInterval] = 0;
	}
fflush(stdout);
	//printf("\nglobs_windowSize : %d globs_nbInterval : %d, globs_maxFrequency : %f globs_minFrequency : %f", globs_windowSize, globs_nbInterval, globs_maxFrequency, globs_minFrequency);
	
	iElem = iWindow = iInterval = 0;
	while(readStruct(file, &tmp, doubleSize))
	{
		if(iElem == globs_windowSize)
		{
			if(iInterval < globs_nbInterval)
			//printf("\niWindow : %d, iElem : %d histo : %d", iWindow, iElem, descriptor->histogram[iWindow][iInterval]);
			fflush(stdout);
			iElem = 0;
			iWindow++;
		}
		*tmp = endianSwap_double(*tmp);
		if(*tmp <= intervalsThreshold[0])
			(descriptor->histogram[iWindow][0])++;
		else
		{
			for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			{
				if(*tmp <= intervalsThreshold[iInterval])
				{
					(descriptor->histogram[iWindow][iInterval])++;
					//printf("d_______%d", iInterval);
					break;		
				}				
			}
			if(*tmp > intervalsThreshold[globs_nbInterval - 1])
				(descriptor->histogram[iWindow][globs_nbInterval - 1])++;
		}
		
		iElem++;
	}
	
	free(tmp);
	free(intervalsThreshold);
	return descriptor;
}