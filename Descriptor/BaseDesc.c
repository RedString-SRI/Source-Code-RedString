/**
 * \file BaseDesc.c
 * \brief A list of descs
 * \author Maxime Sanmartin \n
 */

#include "BaseDesc.h"

void initList(BaseDesc * base){
    *base = NULL;
}

//===================================================================================================
void printList(BaseDesc base){
    // If the list is empty
    if(listIsEmpty(base))
        /** Error **/
    else{
        BaseDesc ptr_p = base;
        // We are using the pointer to travel few every element of the list until the last one
        while(ptr_p!=NULL){
            printElement(*(ptr_p->element));
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
	BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct desc));    
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
    // DO THE SAME ON THE FILE BASEDesc
	FILE * fileAdd;
	switch(type){
		case TEXT: TextDesc * desc = (TextDesc*)structDesc;
			fileAdd = fopen("TextBaseDesc", "a");
        break;
        case PICTURE: PictureDesc * desc = (PictureDesc*)structDesc;
			fileAdd = fopen("PictureBaseDesc", "a");
        break;
        case SOUND: SoundDesc * desc = (SoundDesc*)structDesc;
			fileAdd = fopen("SoundBaseDesc", "a");
        break; 
	}
	writeFile(fileAdd, desc);
	fclose(fileAdd);
}

//===================================================================================================
BaseDesc initBaseDesc(FileType fileType){
	BaseDesc newBase;
	char * fileDesc;
	switch(fileType){
		case TEXT: fileDesc = "TextBaseDesc";
        break;
        case PICTURE: fileDesc = "PictureBaseDesc";
        break;
        case SOUND: fileDesc = "SoundBaseDesc";
        break;
	}
	FILE * baseDesc = fopen(fileDesc, "r");
	void * structDesc;
	BaseDesc ptr_p;
	while(structDesc = readFile(baseDesc)){
		BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct desc));    
		ptr_add->element = structDesc;
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
ListeBaseDesc initListBaseDesc(FileType fileType){
	char * fileDesc;	
	switch(fileType){
		case TEXT: fileDesc = "TextListBaseDesc";
        break;
        case PICTURE: fileDesc = "PictureListBaseDesc";
        break;
        case SOUND: fileDesc = "SoundListBaseDesc";
        break;
	}
	FILE * fileList = fopen(fileDesc, "r");
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
	BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct FileDesc));
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
		BaseDesc ptr_prev = *base;
		BaseDesc ptr_pres = *base;
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
	//DO THE SAME ON THE FILE LISTBASEDesc
}

//===================================================================================================
void remove(DescBase * p){
    if(listIsEmpty(*p))
        /** error **/;
    else{
        BaseDesc ptr_p = *base;
        do{
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p->next)
    }
    // DO THE SAME ON THE FILE BASEDesc
}

//===================================================================================================
void writeList(DescBase * p, fileType t){
    switch(t){
        case TEXT: ptr_p = TextDesc e;
        break;
        case PICTURE: ptr_p = PictureDesc e;
        break;
        case SOUND: ptr_p = SoundDesc e;
        break;
    }
    char choice = 0;
    do{
        addDesc(p, writeElement(&e), t)
        printf("Do you want to add another desc (Y,N)?\n");
        scanf("%s", &choice);
    }while(choice != "n" && choice != "N");
}
