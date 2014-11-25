/**
 * \file SoundDescriptor.h
 * \brief Sound descriptor manager
 * \author Morgan Chabaud
 * \date 25 november 2014
 * 
 * This file defines all functions available for sound descriptors.
 */
#include "ModeType.h"

#ifndef STRUCT_SOUND_DESCRIPTOR
#define STRUCT_SOUND_DESCRIPTOR


/**
 * \struct SoundDescriptor
 * \brief A sound descriptor
 * 
 * A sound descriptor is a descriptor. So it is used to define
 * a sound file. This is kind of a summary of it with some losses.
 */
typedef struct{
  int id;	/*!< Idendifier of the descriptor. It is unique. */
  Mode writingMode;	/*!< This is the writing mode. */
  double** histogram;	/*!< This histogram sizes k*m.
			    k : Windows number
			    m : Intervals number */
}SoundDescriptor;


#endif

