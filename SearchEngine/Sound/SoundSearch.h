/**
 * \file SoundSearch.h
 * \brief Sound searching manager
 * \author Morgan Chabaud
 * 
 * This file declares all functions available for managing sound searching.
 */

#include "math.h"

#include "Type_SoundDesc.h"


#ifndef SOUND_SEARCH
#define SOUND_SEARCH

extern int globs_nbInterval;
float globs_minWindowMatch = 60/100;	// The minimum matching percentage of the average quantification
					// value in the histogram
float globs_minQuantifMatch = 95/100;	// The minimum matching percentage of a quantification value
					// in a window to be considered as similar

/**
 * \brief Compare two sound descriptors
 * 
 * This function compares two sound descriptors. It compares
 * searchedDesc to indexedDesc and returns the matching percentage.
 * \param searchedDesc The descriptor you want to search in the database
 * \param indexedDesc An indexed descriptor of the database
 * \return The matching percentage between searchedDesc and indexedDesc
 */
float compareSoundDesc(SoundDesc *searchedDesc ,SoundDesc *indexedDesc);

/**
 * \brief Compare two windows are return their matching percentage
 * 
 * \param win1 One window you want to compare
 * \param win2 The other window to compare
 * \return The matching percentage
 */
float compareWindows(int* window1, int* window2);

#endif