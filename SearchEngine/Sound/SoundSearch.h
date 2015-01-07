/**
 * \file SoundSearch.h
 * \brief Sound searching manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file declares all functions available for managing sound searching.
 */

#include "Type_SoundDesc.h"


#ifndef SOUND_SEARCH
#define SOUND_SEARCH

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

#endif