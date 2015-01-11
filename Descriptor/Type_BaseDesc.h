/**
 * \file Type_BaseDesc.h
 * \brief Base desc and List Base desc Type
 * \author Maxime Sanmartin
 */
#ifndef TYPE_BASEDESC_H_INCLUDED
#define TYPE_BASEDESC_H_INCLUDED

/**
 * \struct desc
 * \brief A desc base
 *
 * This structure is a chained list of descs. It is used
 * to manage every desc by his type
 */
typedef struct desc{
  void * element;
  struct desc * next;
} *BaseDesc; // BaseDesc is represented by a list of generic descs, and is a pointer to the first element of the list

/**
 * \struct FileDesc
 * \brief A list file-Desc
 *
 * This structure make the link between a file and his desc as a list.
 * The date is the time when the file was indexed
 */
typedef struct FileDesc{
    long address; // the address of the desc
    int date; // the last date of indexation
    char * path; // path of the file
    struct FileDesc * next;
} *ListBaseDesc; //ListBaseDesc is an ordered chained list of file-Desc structure 

#endif // TYPE_BASEDESC_H_INCLUDED
