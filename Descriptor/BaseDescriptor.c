/**
 * \file BaseDescriptor.c
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#include "BaseDescriptor.h"

void initList(BaseDescriptor * base){
    *base = NULL;
}

//===================================================================================================
void printList(BaseDescriptor base){
    // If the list is empty
    if(listIsEmpty(base))
        /** Error **/
    else{
        BaseDescriptor ptr_p = base;
        // We are using the pointer to travel few every element of the list until the last one
        while(ptr_p!=NULL){
            printElement(*(ptr_p->element));
            ptr_p = ptr_p->next;
        }
    }
}

//===================================================================================================
Bool listIsEmpty(BaseDescriptor base){
    return(base==NULL);
}

//===================================================================================================
void addDescriptor(BaseDescriptor *base, void * structDescriptor, FileType type){
    if(listIsEmpty(*base))
        *base = structDescriptor;
    else{
        BaseDescriptor ptr_p = *base;
		// We will go to the last element of the chained list
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        ptr_p->next = structDescriptor;
    }
    /** DO THE SAME ON THE FILE BASEDESCRIPTOR **/
    FILE * fileAdd = fopen("BaseDescriptor", "a");
}

//===================================================================================================
BaseDescriptor initBaseDescriptor(FileType fileType){
	BaseDescriptor newBase;
	char * fileDescriptor;
	switch(fileType){
		case TEXT: fileDescriptor = "TextBaseDescriptor";
        break;
        case PICTURE: fileDescriptor = "PictureBaseDescriptor";
        break;
        case SOUND: fileDescriptor = "SoundBaseDescriptor";
        break; 
	}
	while(fgetc(fileDescriptor))
		addDescriptor(&newBase, readFile(fileDescriptor))
	return newBase;
}

//===================================================================================================
ListeBaseDesc initListBaseDescriptor(FileType fileType){
	char * fileDescriptor;	
	switch(fileType){
		case TEXT: fileDescriptor = "TextListBaseDescriptor";
        break;
        case PICTURE: fileDescriptor = "PictureListBaseDescriptor";
        break;
        case SOUND: fileDescriptor = "SoundListBaseDescriptor";
        break;
	}
	FILE * fileList = fopen(fileDescriptor, "r");
	if(fileList == NULL)
		/** Error **/
	else{
		ListBaseDesc newList;
		long adress;
		int date;
		FILE * path;
		while(fscanf(fileList, "%d %d %d", (long)adress, (FILE *)path, date) != EOF)
			addListBaseDesc(&newList, path, adress, date);
	}
	fclose(fileDescriptor);
	return newList;
}

//===================================================================================================
void addListBaseDesc(ListBaseDesc * listBaseDesc, char * path, long adress, int date){
	
}

//===================================================================================================
void remove(DescriptorBase * p){
    if(listIsEmpty(*p))
        /** error **/
    else{
        BaseDescriptor ptr_p = *base;
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p->next)
    }
    /** DO THE SAME ON THE FILE BASEDESCRIPTOR **/
}

//===================================================================================================
void writeList(DescriptorBase * p, fileType t){
    switch(t){
        case TEXT: ptr_p = TextDescriptor e;
        break;
        case PICTURE: ptr_p = PictureDescriptor e;
        break;
        case SOUND: ptr_p = SoundDescriptor e;
        break;
    }
    char choice = 0;
    do{
        addDescriptor(p, writeElement(&e), t)
        printf("Do you wan't to add another descriptor (Y,N)?\n");
        scanf("%s", &choice);
    }while(choice != "n" && choice != "N");
}
