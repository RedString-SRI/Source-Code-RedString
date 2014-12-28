/**
 * \file SoundDescriptor.h
 * \brief Sound descriptor manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file declares all functions available for sound descriptors.
 */

#include "Type_SoundDescriptor.h"
#include "FileManager.h"


#ifndef SOUND_DESCRIPTOR
#define SOUND_DESCRIPTOR

#define SIZEDOUBLE 8

// SoundDescriptor
extern int globs_windowSize;
extern int globs_nbInterval; 
extern double globs_minFrequency; 
extern double globs_maxFrequency; 

/**
 * \brief Create a sound descriptor
 * 
 * Given a file with a pointer at the begining, this function
 * returns a SoundDescriptor. This descriptor contains a
 * histogram resulting from a quantification of values described
 * in the sound file.
 * \param file The file descriptor pointing at the begining of
 * the sound file
 */
SoundDescriptor * createDescriptor(FILE* file);

#endif

