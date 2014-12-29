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
SoundDescriptor * createSoundDesc(FILE* file);

/**
 * \brief Print a sound descriptor in console
 * 
 * \param desc The descriptor to be displayed
 */
void printSoundDesc(SoundDescriptor const * desc);

/**
 * \brief Write a sound descriptor to a file
 * 
 * Write desc to file (at the current position), so file
 * needs to be opened in the approriate writing mode
 * \param file The file you want to be written
 * \param desc The descriptor which is going to be
 * appended to the file
 */
void writeSoundDesc(FILE* file, SoundDescriptor* desc);

/**
 * \brief Read a sound descriptor from a file
 * 
 * Read a sound descriptor from a file (at the current position)
 * and returns it, so the file needs to be opened in
 * the approriate reading mode
 * \param file The file you want to be read
 * \return The descriptor which is going to store the read one
 */
SoundDescriptor * readSoundDesc(FILE* file);
#endif

