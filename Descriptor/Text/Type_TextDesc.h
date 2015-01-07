/**
 * \file Type_TextDesc.h
 * \brief 
 * \author 
 * \date 
 */

#include "Type_Term.h"

#ifndef TYPE_TEXTDesc
#define TYPE_TEXTDesc

/**
 * \struct TextDesc
 * \brief 
 *
 * This type is used to ...
 */
typedef struct{
	int id;
	Term *terms;
	int nbTerms;
	int nbWords;
}TextDesc;

#endif
