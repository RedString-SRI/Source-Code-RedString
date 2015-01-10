/**
 * \file SoundSearch.c
 * \brief Sound searching manager
 * \author Morgan Chabaud
 * 
 * This file defines all functions available for managing sound searching.
 */

#include "SoundSearch.h"

//===================================================================================================
float compareSoundDesc(SoundDesc *searchedDesc ,SoundDesc *indexedDesc)
{
	// NB: In comments, searchedDesc and indexedDesc are very representative
	//	of their histogram, respectively.
	int nbWinSearch = searchedDesc->nbWindows - 1,	// Removing the count of NULL
		nbWinIndex = indexedDesc->nbWindows - 1,
		iSearchMax = nbWinSearch - 1,
		iIndexMax = nbWinIndex - 1,
		nbFullWinCompare = nbWinIndex - nbWinSearch;	// How many time serachedDesc is entirely compared to indexedDesc
	int iSearch, iIndex;	// Increments
	int iTmpIndex;	// temporary index of indexedDesc, it can be incremented "faster" than iIndex
			// If a sequence begins, iTmpIndex will be used to test the next window
	float tmpMaxMatch, tmpMatch, maxMatch = 0,
		nbWinMatch = 0,
		scalePercent;	// Scale percentage for a unique window
				// amongst all the other of searchedDesc
	Bool inSequence = FALSE;
	
	if(nbWinSearch < nbWinIndex)
	{
		scalePercent = 1.0 / nbWinSearch;

		// 0 --> nbWinSearch
		for(iIndex = 0; iIndex < nbWinSearch; iIndex++, iSearchMax--)
		{
			// A new set of searchedDesc is about to start
			// So we want a brand new sequence begining asap.
			// In order to do so, let's make like we start a
			// new set of windows comparisons.
			inSequence = FALSE;
			tmpMaxMatch = 0;
			iTmpIndex = iIndex;
			for(iSearch = iSearchMax; iSearch < nbWinSearch; iSearch++)
			{
				// If the matching rate is higher than the configuration variable, we take it into account
				tmpMatch = compareWindows(searchedDesc->histogram[iSearch], indexedDesc->histogram[iTmpIndex]);
				if((tmpMatch >= globs_minWindowMatch))
				{
					// Begin or continue a sequence of matches
					inSequence = TRUE;
					tmpMaxMatch += scalePercent;
					// Updating maxMatch of this window
					if(tmpMaxMatch > maxMatch)
						maxMatch = tmpMaxMatch;
					if(iTmpIndex < nbWinIndex)
						iTmpIndex++;
					else
						break;	// The sequence is finished because we've reached the end of indexedDesc
				}
				else
				{
					inSequence = FALSE;
					tmpMaxMatch = 0.0;
				}
				/** Improvement to know where was the match to implement... 
				if(tmpMaxMatch > 0.7)
					printf("\nindex: %d__tmpMaxMatch : %f", iIndex, tmpMaxMatch);
				**/
			}
		}
		
		// nbWinSearch --> (nbWinIndex - nbWinSearch)
		// Note: nbFullWinCompare = (nbWinIndex - nbWinSearch)
		for(iIndex = nbWinSearch; iIndex < nbFullWinCompare; iIndex++)
		{
			//printf("\nSecond Part: nbWinSearch %d", nbWinSearch);
			// A new set of searchedDesc is about to start
			// So we want a brand new sequence begining asap.
			// In order to do so, let's make like we start a
			// new set of windows comparisons.
			inSequence = FALSE;
			tmpMaxMatch = 0;
			iTmpIndex = iIndex;
			
			for(iSearch = 0; iSearch < nbWinSearch; iSearch++)
			{
				// If the matching rate is higher than the configuration variable, we take it into account
				tmpMatch = compareWindows(searchedDesc->histogram[iSearch], indexedDesc->histogram[iTmpIndex]);
				if((tmpMatch >= globs_minWindowMatch))
				{
					// Begin or continue a sequence of matches
					inSequence = TRUE;
					tmpMaxMatch += scalePercent;
					// Updating maxMatch of this window
					if(tmpMaxMatch > maxMatch)
						maxMatch = tmpMaxMatch;
					if(iTmpIndex < nbWinIndex)
						iTmpIndex++;
					else
						break;	// The sequence is finished because we've reached the end of indexedDesc
				}
				else
				{
					inSequence = FALSE;
					tmpMaxMatch = 0.0;
				}
				/** Improvement to know where was the match to implement... 
				if(tmpMaxMatch > 0.7)
					printf("\nindex: %d__tmpMaxMatch : %f", iIndex, tmpMaxMatch);
				**/
			}
		}
		
		// 0 --> nbWinSearch
		iSearchMax = nbWinSearch - 1;
		for(; iIndex < nbWinIndex; iIndex++, iSearchMax--)
		{
			// A new set of searchedDesc is about to start
			// So we want a brand new sequence begining asap.
			// In order to do so, let's make like we start a
			// new set of windows comparisons.
			inSequence = FALSE;
			tmpMaxMatch = 0;
			iTmpIndex = iIndex;
			
			for(iSearch = 0; iSearch < iSearchMax; iSearch++)
			{
				// If the matching rate is higher than the configuration variable, we take it into account
				tmpMatch = compareWindows(searchedDesc->histogram[iSearch], indexedDesc->histogram[iTmpIndex]);
				if((tmpMatch >= globs_minWindowMatch))
				{
					// Begin or continue a sequence of matches
					inSequence = TRUE;
					tmpMaxMatch += scalePercent;
					// Updating maxMatch of this window
					if(tmpMaxMatch > maxMatch)
						maxMatch = tmpMaxMatch;
					if(iTmpIndex < nbWinIndex)
						iTmpIndex++;
					else
						break;	// The sequence is finished because we've reached the end of indexedDesc
				}
				else
				{
					inSequence = FALSE;
					tmpMaxMatch = 0.0;
				}
				/** Improvement to know where was the match to implement... 
				if(tmpMaxMatch > 0.7)
					printf("\nindex: %d__tmpMaxMatch : %f", iIndex, tmpMaxMatch);
				**/
			}
		}
	}

	return maxMatch;
}

float compareWindows(int* window1, int* window2)
{
	int i = 0, nbMatch = 0;
	int doubleNbInterval =  2 * globs_nbInterval;
	
	for(; i < globs_nbInterval; i++)
	{
		if(window2[i] < window1[i])
		{
			if((((float)window2[i]) / window1[i]) >= globs_minQuantifMatch)
				nbMatch++;
		}
		else if(window1[i] == 0 && window2[i] == 0)
			nbMatch++;
		else if(window1[i] == 0 || window2[i] == 0)
			continue;
		else if((((float)window1[i]) / window2[i]) >= globs_minQuantifMatch)	// window1[i] <= window2[i]
			nbMatch++;
	}
	
	return  ((float)nbMatch) / globs_nbInterval;
}
