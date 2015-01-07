/**
 * \file Type_SoundDescriptor.h
 * \brief Sound Descriptor Type
 * \author Morgan Chabaud
 */


#ifndef TYPE_SOUND_DESCRIPTOR
#define TYPE_SOUND_DESCRIPTOR

/**
 * \struct SoundDescriptor
 * \brief A sound descriptor
 *
 * A sound descriptor is a descriptor. It is used to define
 * a sound file. This is kind of a summary of it with some losses.
 */
typedef struct{
  int address;       /*!< The address in the descriptor base. Idendifier of the descriptor. It is unique. */
  int nbWindows;	/*!< The number of Windows stored in the histogram */
  int** histogram;   /*!< This histogram sizes k*m.
                            k : Windows number
                            m : Intervals number */
}SoundDescriptor;

#endif
