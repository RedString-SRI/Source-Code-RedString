/**
 * \file Globals.c
 * \brief Configuration global variables
 * 
 * Those globals are initialised by the function initGlobals() in Configurator
 * \author Morgan Chabaud \n
 * How to use : http://c.developpez.com/faq/?page=Les-variables-globales
 */
//=================================================================================================== 
// TextDescriptor
int globs_occurThreshold; // The minimum occurrences (in the indexed file) to store a word in a descriptor 
int globs_maxTerms; // The number of word to keep in the descriptor
//===================================================================================================
// SoundDescriptor
int globs_windowSize; // The sound signal will be split in x windows. So it is their size.
int globs_nbInterval; // The number of intervals in a window.
double globs_minFrequency; // The minimum frequency of a sound file
double globs_maxFrequency; // The maximum frequency of a sound file
//===================================================================================================
// PictureDescriptor
int globs_nbWeightyBits; // The number of weighty bits to get on each pixel component
int globs_compTolerance;  // The comparison tolerance for pixels
                          // Ex : 1 means that two average pixels can have maximum 1 "point" difference
                          //      so they are considered equals.
