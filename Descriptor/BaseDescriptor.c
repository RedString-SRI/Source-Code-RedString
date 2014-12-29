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
	BaseDescriptor ptr_add = (BaseDescriptor) malloc(sizeof(struct Descriptor));    
	ptr_add->element = structDescriptor;
	if(listIsEmpty(*base))
        *base = ptr_add;
    else{
        BaseDescriptor ptr_p = *base;
		// We will go to the last element of the chained list to add next to it the new element
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        ptr_p->next = ptr_add;
    }
    // DO THE SAME ON THE FILE BASEDESCRIPTOR
	FILE * fileAdd;
	switch(type){
		case TEXT: TextDescriptor * desc = (TextDescriptor*)structDescriptor;
			fileAdd = fopen("TextBaseDescriptor", "a");
        break;
        case PICTURE: PictureDescriptor * desc = (PictureDescriptor*)structDescriptor;
			fileAdd = fopen("PictureBaseDescriptor", "a");
        break;
        case SOUND: SoundDescriptor * desc = (SoundDescriptor*)structDescriptor;
			fileAdd = fopen("SoundBaseDescriptor", "a");
        break; 
	}
	writeFile(fileAdd, desc);
	fclose(fileAdd);
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
	FILE * baseDesc = fopen(fileDescriptor, "r");
	void * structDescriptor;
	BaseDescriptor ptr_p;
	while(structDescriptor = readFile(baseDesc)){
		BaseDescriptor ptr_add = (BaseDescriptor) malloc(sizeof(struct Descriptor));    
		ptr_add->element = structDescriptor;
		if(listIsEmpty(newBase)){
		    newBase = ptr_add;
			ptr_p = newBase;
		}
		else{
			ptr_p->next = ptr_add;
			ptr_p = ptr_p->next;
		}
	}
	fclose(baseDesc);
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
		/** Error **/;
	else{
		ListBaseDesc newList;
		long adress;
		int date;
		char path[globs_maxPathLength];
		while(fscanf(fileList, "%ld\t%s\t%d", &address, path, &date) != EOF)
			addListBaseDesc(&newList, path, adress, date);
	}
	fclose(filelist);
	return newList;
}

//===================================================================================================
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date){
	BaseDescriptor ptr_add = (BaseDescriptor) malloc(sizeof(struct FileDescriptor));
	ptr_add->path = path;
	ptr_add->address = address;
	ptr_add->date = date;
	ptr_add->next = NULL;
	// if the list is empty
	if(listIsEmpty(*listBaseDesc))
		base = ptr_add;
	else{
		// We create two traveler pointers, one which check the address with the one from the new element : ptr_pres, 
		// and another to do again chaining : ptr_prev
		BaseDescriptor ptr_prev = *base;
		BaseDescriptor ptr_pres = *base;
		while(ptr_pres != NULL){
			if(ptr_pres->address > address){
				ptr_add->next = ptr_pres;
				if(*base->next == NULL)
					*base = ptr_add;
				else
					ptr_prev->next = ptr_add; 				
				break;
			}
			ptr_prev = ptr_pres;
			ptr_pres = ptr_pres->next;
		}
		// If the new address is bigger than any of the list
		if(ptr_pres == NULL)
			ptr_prev->next = ptr_add;
	}
	//DO THE SAME ON THE FILE LISTBASEDESCRIPTOR
}

//===================================================================================================
void remove(DescriptorBase * p){
    if(listIsEmpty(*p))
        /** error **/;
    else{
        BaseDescriptor ptr_p = *base;
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p->next)
    }
    // DO THE SAME ON THE FILE BASEDESCRIPTOR
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
        printf("Do you want to add another descriptor (Y,N)?\n");
        scanf("%s", &choice);
    }while(choice != "n" && choice != "N");
}
