/**
 * \file Type_TextDescriptor.h
 * \brief 
 * \author 
 * \date 
 */

#include "Type_WritingMode.h"
#include "Type_Term.h"

#ifndef TYPE_TEXTDESCRIPTOR
#define TYPE_TEXTDESCRIPTOR

/**
 * \struct TextDescriptor
 * \brief 
 *
 * This type is used to ...
 */
typedef struct{
	int id;
	Mode writingMode;
	Term *terms;
	int nbTerms;
	int nbWords;
}TextDescriptor;

#endif
