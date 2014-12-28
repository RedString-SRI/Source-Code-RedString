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

	descriptor->histogram = malloc(sizeof(*descriptor->histogram) * nbWindows);
	
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
		descriptor->histogram[iWindow] = malloc(sizeof(double) * globs_nbInterval);
		for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			descriptor->histogram[iWindow][iInterval] = 0;
	}
	
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
			(descriptor->histogram[iWindow][0])++;
		else
		{
			for(iInterval = 0; iInterval < globs_nbInterval; iInterval++)
			{
				if(*tmp <= intervalsThreshold[iInterval])
				{
					(descriptor->histogram[iWindow][iInterval])++;
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
