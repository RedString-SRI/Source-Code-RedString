/**
 * \file Type_BaseDescriptor.h
 * \brief Base Descriptor and List Base Descriptor Type
 * \author Maxime Sanmartin
 */
#ifndef TYPE_BASEDESCRIPTOR_H_INCLUDED
#define TYPE_BASEDESCRIPTOR_H_INCLUDED

/**
 * \struct Descriptor
 * \brief A descriptor base
 *
 * This structure is a chained list of descriptors. It is used
 * to manage every descriptor by his type
 */
typedef struct Descriptor{
  void * element;
  struct Descriptor * next;
} *BaseDescriptor; // DescriptorBase is represented by a list of generic Descriptors, and is a pointer to the first element of the list

/**
 * \struct FileDescriptor
 * \brief A list file-descriptor
 *
 * This structure make the link between a file and his descriptor as a list.
 * The date is the time when the file was indexed
 */
typedef struct FileDescriptor{
    long address; // the address of the descriptor
    int date; // the last date of indexation
    char path[globs_maxPathLength]; // path of the file
    struct FileDescriptor * next;
} *ListeBaseDesc; //ListBaseDesc is an ordered chained list of file-descriptor structure 

#endif // TYPE_BASEDESCRIPTOR_H_INCLUDED
