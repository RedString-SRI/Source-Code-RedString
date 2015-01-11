/**
 * \file BaseDesc.c
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#include "BaseDescriptor.h"

//===================================================================================================
void initList(BaseDesc * base){
    *base = NULL;
}

//===================================================================================================
void initListBase(struct FileDesc * list){
	list->path = (char *) malloc(globs_maxPathLength * sizeof(char));
	list->address = 0;
	list->date = 0;
	list->next = NULL;
}

//===================================================================================================
void printList(BaseDesc base){
    // If the list is empty
    if(listIsEmpty(base))
        /** Error **/;
    else{
        BaseDesc ptr_p = base;
        // We are using the pointer to travel few every element of the list until the last one
        while(ptr_p!=NULL){
            printSoundDesc(ptr_p->element);
            ptr_p = ptr_p->next;
        }
    }
}

//===================================================================================================
Bool listIsEmpty(BaseDesc base){
    return(base==NULL);
}

//===================================================================================================
void addDescriptor(BaseDesc *base, void * structDesc, FileType type){
	BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct Desc));    
	ptr_add->element = structDesc;
	if(listIsEmpty(*base))
        *base = ptr_add;
    else{
        BaseDesc ptr_p = *base;
		// We will go to the last element of the chained list to add next to it the new element
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        ptr_p->next = ptr_add;
    }
	FILE * fileAdd;
	void * desc;
	switch(type){
		/*case TEXT: 
				desc = (TextDesc*)structDesc;
				fileAdd = fopen("TextBaseDesc.db", "a");
				writeTextDesc(fileAdd, desc);
        break;
        case PICTURE: 
				desc = (PictureDesc*)structDesc;
				fileAdd = fopen("PictureBaseDesc.db", "a");
				writePictureDesc(fileAdd, desc);
        break;*/
        case SOUND: 
				desc = (SoundDesc*)structDesc;
				fileAdd = fopen("SoundBaseDesc.db", "a");
				writeSoundDesc(fileAdd, desc);
        break; 
	}
	fclose(fileAdd);
}

//===================================================================================================
BaseDesc initBaseDesc(FileType fileType){
	BaseDesc newBase;
	int size = sizeof(struct Desc *);
	FILE * baseDesc;
	void * structDesc;
	BaseDesc ptr_p;
	void * desc;
	switch(fileType){
		/*case TEXT:
				structDesc = readTextDesc(baseDesc);
				baseDesc = fopen("TextBaseDesc.db", "r");
				size += sizeof(TextDesc);
        break;
        case PICTURE:
				structDesc = readPictureDesc(baseDesc);
				baseDesc = fopen("PictureBaseDesc.db", "r");
				size += sizeof(PictureDesc);
        break;*/
        case SOUND:
				structDesc = readSoundDesc(baseDesc);
				baseDesc = fopen("SoundBaseDesc.db", "r");
				size += sizeof(SoundDesc);
        break; 
	}
	while(structDesc != NULL){ //I'm not sure this is NULL or EOF, ' have to check with descriptors fonction
		BaseDesc ptr_add = (BaseDesc) malloc(size);    
		ptr_add->element = structDesc;
		if(listIsEmpty(newBase)){
		    newBase = ptr_add;
			ptr_p = newBase;
		}
		else{
			ptr_p->next = ptr_add;
			ptr_p = ptr_p->next;
		}
		switch(fileType){
			/*case TEXT:
					structDesc = readTextDesc(baseDesc);
		    break;
		    case PICTURE:
					structDesc = readPictureDesc(baseDesc);
		    break;*/
		    case SOUND:
					structDesc = readSoundDesc(baseDesc);
		    break; 
		}
	}
	fclose(baseDesc);
	return newBase;
}

//===================================================================================================
ListBaseDesc initListBaseDesc(FileType fileType){
	char * fileDesc;	
	switch(fileType){
		/*case TEXT: strcpy(fileDesc,"TextListBaseDesc.db");
		break;
		case PICTURE: strcpy(fileDesc, "PictureListBaseDesc.db");
		break;*/
		case SOUND: strcpy(fileDesc, "SoundListBaseDesc.db");
		break;
	}
	FILE * fileList = fopen(fileDesc, "r");
	ListBaseDesc newList = NULL;
	if(fileList == NULL)
		/** Error **/;
	else{
		long address;
		int date;
		char path[globs_maxPathLength];
		while(fscanf(fileList, "%ld\t%s\t%d", &address, path, &date) != EOF)
			addListBaseDesc(&newList, path, address, date, fileType);
	}
	fclose(fileList);
	return newList;
}

//===================================================================================================
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date, FileType fileType){
	ListBaseDesc ptr_add = (ListBaseDesc) malloc(sizeof(struct FileDesc));
	strcpy(ptr_add->path, path);
	ptr_add->address = address;
	ptr_add->date = date;
	ptr_add->next = NULL;
	// if the list is empty
	if(*listBaseDesc == NULL)
		*listBaseDesc = ptr_add;
	else{
		// We create two traveler pointers, one which check the address with the one from the new element : ptr_pres, 
		// and another to do again chaining : ptr_prev
		ListBaseDesc ptr_prev = *listBaseDesc;
		ListBaseDesc ptr_pres = *listBaseDesc;
		Bool found = FALSE;
		char * fileDesc;	
		switch(fileType){
			/*case TEXT: strcpy(fileDesc,"TextListBaseDesc.db");
		    break;
		    case PICTURE: strcpy(fileDesc, "PictureListBaseDesc.db");
		    break;*/
		    case SOUND: strcpy(fileDesc, "SoundListBaseDesc.db");
		    break;
		}
		FILE * fileList = fopen(fileDesc, "w+");
		while(ptr_pres != NULL){
			fprintf(fileList, "%ld\t%s\t%d\n", ptr_pres->address, ptr_pres->path, ptr_pres->date);
			if(ptr_pres->address > address && !found){
				ptr_add->next = ptr_pres;
				if((*listBaseDesc)->next == NULL)
					*listBaseDesc = ptr_add;
				else
					ptr_prev->next = ptr_add;
				found = TRUE;
			}
			ptr_prev = ptr_pres;
			ptr_pres = ptr_pres->next;
		}
		// If the new address is bigger than any of the list
		if(ptr_prev->address < address){
			ptr_prev->next = ptr_add;
			fprintf(fileList, "%ld\t%s\t%d\n", ptr_add->address, ptr_add->path, ptr_add->date);
		}
		fclose(fileList);
	}
}

//===================================================================================================
void removeDesc(BaseDesc * base, FileType type){
    if(listIsEmpty(*base))
        /** error **/;
    else{
		char * FileDesc;
		switch(type){
			/*case TEXT: strcpy(FileDesc, "TextBaseDesc.db");
		    break;
		    case PICTURE: strcpy(FileDesc, "PictureBaseDesc.db");
		    break;*/
		    case SOUND: strcpy(FileDesc, "SoundBaseDesc.db");
		    break;
		}
		FILE * baseDesc = fopen(FileDesc, "w+");
        BaseDesc ptr_p = *base;
        do{
			switch(type){
				/*case TEXT:
						writeTextDesc(baseDesc, ptr_p->element);
				break;
				case PICTURE:
						writePictureDesc(baseDesc, ptr_p->element);
				break;*/
				case SOUND:
						writeSoundDesc(baseDesc, ptr_p->element);
				break; 
			}
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p->next);
		fclose(baseDesc);    
	}
}
