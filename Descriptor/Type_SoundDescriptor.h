/**
 * \file Type_SoundDescriptor.h
 * \brief Sound Descriptor Type
 * \author Morgan Chabaud
 */

#include "Type_WritingMode.h"

#ifndef TYPE_SOUNDDESCRIPTOR
#define TYPE_SOUNDDESCRIPTOR

/**
 * \struct SoundDescriptor
 * \brief A sound descriptor
 *
 * A sound descriptor is a descriptor. It is used to define
 * a sound file. This is kind of a summary of it with some losses.
 */
typedef struct{
  int id;       /*!< Idendifier of the descriptor. It is unique. */
  Mode writingMode;     /*!< This is the writing mode. */
  double** histogram;   /*!< This histogram sizes k*m.
                            k : Windows number
                            m : Intervals number */
}SoundDescriptor;
