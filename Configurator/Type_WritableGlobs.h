/**
 * \file Type_WritableGlobs.h
 * \brief Writable Globs Type
 * \author Morgan Chabaud
 */


#ifndef TYPE_WRITABLE_GLOBS
#define TYPE_WRITABLE_GLOBS

/**
 * \struct WritableGlobs
 * \brief A structure used to load/save global variables
 *
 * This structure is used to store global variable temporally.\n
 * Writing mode: Variables will be there until they are all initialised.
 * Then, the structure will be stored in a configuration file.\n
 * Reading mode: The configuration file will be stored directly in this
 * structure. Eventually the global variables will be initialised with
 * the corresponding ones in this structure.
 */
typedef struct{
	// ListBaseDesc
	int listBaseDesc_maxPathLength; /*!< The maximum path length for an indexed file */
	
	// TextDesc
	int textDesc_occurThreshold; /*!< The minimum occurrences (in the indexed file) to store a word in a desc  */
	int textDesc_maxTerms; /*!< The number of word to keep in the desc */
	
	// PictureDesc
	int pictureDesc_nbWeightyBits; /*!< The number of weighty bits to get on each pixel component */
	int pictureDesc_compTolerance; /*!< The comparison tolerance value for pictures */
	
	// SoundDesc
	int soundDesc_windowSize; /*!< The sound signal will be split in x windows. So it is their size. */
	int soundDesc_nbInterval; /*!< The number of intervals in a window. */
	double soundDesc_minFrequency; /*!< The minimum frequency of a sound file */
	double soundDesc_maxFrequency; /*!< The maxmimum frequency of a sound file */
	float soundDesc_minWindowMatch; /*!< The minimum matching percentage of the average quantification
						value in the histogram */
	float soundDesc_minQuantifMatch; /*!< The minimum matching percentage of a quantification value
						in a window to be considered as similar */
				
	
}WritableGlobs;

#endif
