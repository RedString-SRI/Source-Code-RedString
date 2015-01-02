/**
 * \file SoundDesc.h
 * \brief Sound desc manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file declares all functions available for sound descs.
 */

#include "Type_SoundDesc.h"
#include "FileManager.h"


#ifndef SOUND_Desc
#define SOUND_Desc

#define SIZEDOUBLE 8

// SoundDesc
extern int globs_windowSize;
extern int globs_nbInterval; 
extern double globs_minFrequency; 
extern double globs_maxFrequency; 

/**
 * \brief Create a sound desc
 * 
 * Given a file with a pointer at the begining, this function
 * returns a SoundDesc. This desc contains a
 * histogram resulting from a quantification of values described
 * in the sound file.
 * \param file The file desc pointing at the begining of
 * the sound file
 */
SoundDesc * createSoundDesc(FILE* file);

/**
 * \brief Give the size (when written in a file) of the desc
 *
 * When written in a file with the function writeSoundDesc,
 * the size of the sound desc could be different that
 * his in-memory size. So this function returns the needed size
 * to write it into a file. 
 * \param desc The desc to have its size
 * \return The in-file size of the desc
 */
int soundDescSize(SoundDesc const * desc);

/**
 * \brief Print a sound desc in console
 * 
 * \param desc The desc to be displayed
 */
void printSoundDesc(SoundDesc const * desc);

/**
 * \brief Write a sound desc to a file
 * 
 * Write desc to file (at the current position), so file
 * needs to be opened in the approriate writing mode
 * \param file The file you want to be written
 * \param desc The desc which is going to be
 * appended to the file
 */
void writeSoundDesc(FILE* file, SoundDesc* desc);

/**
 * \brief Read a sound desc from a file
 * 
 * Read a sound desc from a file (at the current position)
 * and returns it, so the file needs to be opened in
 * the approriate reading mode
 * \param file The file you want to be read
 * \return The desc which is going to store the read one
 */
SoundDesc * readSoundDesc(FILE* file);
#endif

