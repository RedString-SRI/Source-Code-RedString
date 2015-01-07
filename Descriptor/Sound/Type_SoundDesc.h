/**
 * \file Type_SoundDesc.h
 * \brief Sound desc Type
 * \author Morgan Chabaud
 */


#ifndef TYPE_SOUND_Desc
#define TYPE_SOUND_Desc

/**
 * \struct SoundDesc
 * \brief A sound desc
 *
 * A sound desc is a desc. It is used to define
 * a sound file. This is kind of a summary of it with some losses.
 */
typedef struct{
  int address;       /*!< The address in the desc base. Idendifier of the desc. It is unique. */
  int nbWindows;	/*!< The number of Windows stored in the histogram */
  int** histogram;   /*!< This histogram sizes k*m.
                            k : Windows number
                            m : Intervals number */
}SoundDesc;

#endif
