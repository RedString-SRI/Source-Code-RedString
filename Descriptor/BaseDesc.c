/**
 * \file BaseDesc.c
 * \brief A list of Descriptors
 * \author Maxime Sanmartin \n
 */

#include "BaseDesc.h"

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
void printList(BaseDesc base, FileType type){
    // If the list is empty
    if(listIsEmpty(base))
        printf("Your list is empty, sir...\n");
    else{
        BaseDesc ptr_p = base;
        // We are using the pointer to travel few every element of the list until the last one
        while(ptr_p!=NULL){
			switch(type){
				/*case TEXT: printTextDesc(ptr_p->element);
				break;
				case PICTURE: printIMGDesc(ptr_p->element);
				break;*/
				case SOUND: printSoundDesc(ptr_p->element);
				break;
			}
            ptr_p = ptr_p->next;
        }
    }
}

//===================================================================================================
Bool listIsEmpty(BaseDesc base){
    return(base==NULL);
}

//===================================================================================================
void addDesc(BaseDesc *base, void * structDesc, FileType type){
	int size = sizeof(struct desc *);
	FILE * fileAdd;
	void * desc;
	switch(type){
		/*case TEXT: 
				size += sizeof(TextDesc);
				desc = (TextDesc*)structDesc;
				fileAdd = fopen("TextBaseDesc.db", "a");
				writeTextDesc(fileAdd, desc);
		break;
		case PICTURE: 
				size += sizeof(PictureDesc);
				desc = (PictureDesc*)structDesc;
				fileAdd = fopen("PictureBaseDesc.db", "a");
				writePictureDesc(fileAdd, desc);
		break;*/
		case SOUND: 	
				size += sizeof(SoundDesc);
				desc = (SoundDesc*)structDesc;
				fileAdd = fopen("SoundBaseDesc.db", "a");
				writeSoundDesc(fileAdd, desc);
		break;
	}   
	fclose(fileAdd);
	BaseDesc ptr_add = (BaseDesc) malloc(size);
	ptr_add->element = structDesc;
	if(listIsEmpty(*base)){
        *base = ptr_add;
	}
    else{
        BaseDesc ptr_p = *base;
		// We will go to the last element of the chained list to add next to it the new element
        while(ptr_p != NULL){
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }
        ptr_p->next = ptr_add;
    }
}

//===================================================================================================
void * getDesc(BaseDesc base, long address, FileType type){
	BaseDesc ptr_dep = base;
	void * el_comp;
	while(ptr_dep != NULL){
		el_comp = ptr_dep->element;
		switch(type){
			/*case TEXT:
				if(((TextDesc*)(el_comp))->address == address)
					return el_comp;
			break;
			case PICTURE: 
				if(((PictureDesc*)(el_comp))->address == address)
					return el_comp;
			break;*/
			case SOUND:
				if(((SoundDesc*)(el_comp))->address == address)
					return el_comp;
			break;
		}
		ptr_dep = ptr_dep->next;
	}
	return NULL; // If we're leaving the loop
}

//===================================================================================================
ListBaseDesc getFileDesc(ListBaseDesc list, long address){
	ListBaseDesc ptr_dep = list;
	while(ptr_dep != NULL && ptr_dep->address < address){
		if(ptr_dep->address == address)
			return ptr_dep;
		ptr_dep = ptr_dep->next;
	}
	return NULL; // If we're leaving the loop
}

//===================================================================================================
char * getFileName(ListBaseDesc list, long address){
	ListBaseDesc listGet = getFileDesc(list, address);
	char * fileName;
	int pathSize = strlen(listGet->path);
	int i = 0;
	while(listGet->path[pathSize-i++] == '/');
	fileName = (char *) malloc(i * sizeof(char));
	int j;	
	for(j=1; j<i; j++)
		fileName[j] = listGet->path[pathSize-i+j];
	return fileName;
}

//===================================================================================================
long getAddress(ListBaseDesc list, char * path){
	ListBaseDesc ptr_dep = list;
	while(ptr_dep != NULL){
		if(strcmp(ptr_dep->path, path) == 0)
			return ptr_dep->address;
		ptr_dep = ptr_dep->next;
	}
	return 0;
}

//===================================================================================================
long descExists(ListBaseDesc list, char * path){
	ListBaseDesc ptr_dep = list;
	while(ptr_dep != NULL){
		if(strcmp(ptr_dep->path, path) == 0)
			return ptr_dep->address;
		ptr_dep = ptr_dep->next;
	}
	return 0; // If we're leaving the loop
}

//===================================================================================================
BaseDesc initBaseDesc(FileType fileType){
	BaseDesc newBase;
	int size = sizeof(struct desc *);
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
	while(structDesc != NULL){ // I'm not sure this is NULL or EOF, ' have to check with descriptors fonction
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
	FILE * fileList;
	switch(fileType){
		/*case TEXT: fileList = fopen("TextListBaseDesc.db", "r");
		break;
		case PICTURE: fileList = fopen("PictureListBaseDesc.db", "r");
		break;*/
		case SOUND: fileList = fopen("SoundListBaseDesc.db", "r");
		break;
	}
	ListBaseDesc newList = NULL;
	if(fileList == NULL)
		/** Error **/;
	else{
		long address;
		int date;
		char path[globs_maxPathLength];
		ListBaseDesc ptr_add;
		ListBaseDesc ptr_p;
		while(fscanf(fileList, "%ld\t%s\t%d", &address, path, &date) != EOF){
			ptr_add = (ListBaseDesc) malloc(sizeof(struct FileDesc));
			ptr_add->path = (char *) malloc(globs_maxPathLength * sizeof(char));
			strcpy(ptr_add->path, path);
			ptr_add->address = address;
			ptr_add->date = date;
			ptr_add->next = NULL;
			if(newList == NULL){
				newList = ptr_add;
				ptr_p = ptr_add;			
			}
			else
				ptr_p->next = ptr_add;
		}
	}
	fclose(fileList);
	return newList;
}

//===================================================================================================
void addListBaseDesc(ListBaseDesc * listBaseDesc, char path[globs_maxPathLength], long address, int date, FileType fileType){
	ListBaseDesc ptr_add = (ListBaseDesc) malloc(sizeof(struct FileDesc));
	ptr_add->path = (char *) malloc (globs_maxPathLength * sizeof(char));
	strcpy(ptr_add->path, path);
	ptr_add->address = address;
	ptr_add->date = date;
	ptr_add->next = NULL;
	FILE * fileList;
	switch(fileType){
		/*case TEXT: fileList = fopen("TextListBaseDesc.db", "w+");
	    break;
	    case PICTURE: fileList = fopen("PictureListBaseDesc.db", "w+");
	    break;*/
	    case SOUND: fileList = fopen("SoundListBaseDesc.db", "w+");
	    break;
	}
	// if the list is empty
	if(*listBaseDesc == NULL){
		*listBaseDesc = ptr_add;
		fprintf(fileList, "%ld\t%s\t%d\n", ptr_add->address, ptr_add->path, ptr_add->date);
	}
	else{
		// We create two traveler pointers, one which check the address with the one from the new element : ptr_pres, 
		// and another to do again chaining : ptr_prev
		ListBaseDesc ptr_prev = *listBaseDesc;
		ListBaseDesc ptr_pres = *listBaseDesc;	
		Bool done = FALSE;
		while(ptr_pres != NULL){
			if(ptr_pres->address > address && !done){
				ptr_add->next = ptr_pres;
				if(*listBaseDesc == ptr_prev)
					*listBaseDesc = ptr_add;
				else
					ptr_prev->next = ptr_add;
				done = TRUE;
				fprintf(fileList, "%ld\t%s\t%d\n", ptr_add->address, ptr_add->path, ptr_add->date);
			}
			fprintf(fileList, "%ld\t%s\t%d\n", ptr_pres->address, ptr_pres->path, ptr_pres->date);
			ptr_prev = ptr_pres;
			ptr_pres = ptr_pres->next;
		}
		// If the new address is bigger than any of the list
		if(ptr_prev->address < address){
			ptr_prev->next = ptr_add;
			fprintf(fileList, "%ld\t%s\t%d\n", ptr_add->address, ptr_add->path, ptr_add->date);
		}
	}
	fclose(fileList);
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
            if(ptr_p->next == NULL)
                break;
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
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p);
		fclose(baseDesc);    
	}
}
