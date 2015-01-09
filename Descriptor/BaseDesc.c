/**
 * \file BaseDesc.c
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
 * \brief A list of Descriptors
=======
 * \brief A list of descs
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
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
        /** Error **/;
    else{
        BaseDesc ptr_p = base;
        // We are using the pointer to travel few every element of the list until the last one
        while(ptr_p!=NULL){
            printElement(ptr_p->element);
            ptr_p = ptr_p->next;
        }
    }
}

//===================================================================================================
Bool listIsEmpty(BaseDesc base){
    return(base==NULL);
}

//===================================================================================================
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
void addDescriptor(BaseDesc *base, void * structDesc, FileType type){
	BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct Desc));    
=======
void addDesc(BaseDesc *base, void * structDesc, FileType type){
	BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct desc));    
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
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
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
=======
    // DO THE SAME ON THE FILE BASEDesc
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
	FILE * fileAdd;
	SoundDescriptor * desc;
	switch(type){
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
		/*case TEXT: TextDescriptor * desc = (TextDescriptor*)structDesc;
			fileAdd = fopen("TextBaseDesc.db", "a");
        break;
        case PICTURE: PictureDescriptor * desc = (PictureDescriptor*)structDesc;
			fileAdd = fopen("PictureBaseDesc.db", "a");
        break;*/
        case SOUND: 
				SoundDescriptor * desc = (SoundDescriptor*)structDesc;
				fileAdd = fopen("SoundBaseDesc.db", "a");
=======
		case TEXT: TextDesc * desc = (TextDesc*)structDesc;
			fileAdd = fopen("TextBaseDesc", "a");
        break;
        case PICTURE: PictureDesc * desc = (PictureDesc*)structDesc;
			fileAdd = fopen("PictureBaseDesc", "a");
        break;
        case SOUND: SoundDesc * desc = (SoundDesc*)structDesc;
			fileAdd = fopen("SoundBaseDesc", "a");
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
        break; 
	}
	writeFile(fileAdd, desc);
	fclose(fileAdd);
}

//===================================================================================================
BaseDesc initBaseDesc(FileType fileType){
	BaseDesc newBase;
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
	char * FileDesc;
	int size_t = sizeof(struct Desc *);
	FILE * baseDesc = fopen(FileDesc, "r");
	void * structDesc;
	BaseDesc ptr_p;
	switch(type){
		/*case TEXT: TextDescriptor * desc = (TextDescriptor*)structDesc;
			fileAdd = fopen("TextBaseDesc.db", "a");
			size_t += sizeof(TextDesc);
=======
	char * fileDesc;
	switch(fileType){
		case TEXT: fileDesc = "TextBaseDesc";
        break;
        case PICTURE: fileDesc = "PictureBaseDesc";
        break;
        case SOUND: fileDesc = "SoundBaseDesc";
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
        break;
        case PICTURE: PictureDescriptor * desc = (PictureDescriptor*)structDesc;
			fileAdd = fopen("PictureBaseDesc.db", "a");
			size_t += sizeof(PictureDesc);
        break;*/
        case SOUND: 
				SoundDescriptor * desc = (SoundDescriptor*)structDesc;
				fileAdd = fopen("SoundBaseDesc.db", "a");
				size_t += sizeof(SoundDesc);
        break; 
	}
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
	while(structDesc = readFile(baseDesc)){
		BaseDesc ptr_add = (BaseDesc) malloc(size_t);    
=======
	FILE * baseDesc = fopen(fileDesc, "r");
	void * structDesc;
	BaseDesc ptr_p;
	while(structDesc = readFile(baseDesc)){
		BaseDesc ptr_add = (BaseDesc) malloc(sizeof(struct desc));    
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
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
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
ListBaseDesc initListBaseDesc(FileType fileType){
	char * fileDesc;	
	switch(fileType){
		/*case TEXT: strcpy(fileDesc,"TextListBaseDesc.db");
		break;
		case PICTURE: strcpy(fileDesc, "PictureListBaseDesc.db");
		break;*/
		case SOUND: strcpy(fileDesc, "SoundListBaseDesc.db");
		break;
=======
ListeBaseDesc initListBaseDesc(FileType fileType){
	char * fileDesc;	
	switch(fileType){
		case TEXT: fileDesc = "TextListBaseDesc";
        break;
        case PICTURE: fileDesc = "PictureListBaseDesc";
        break;
        case SOUND: fileDesc = "SoundListBaseDesc";
        break;
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
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
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
		Bool trouve = False;
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
=======
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
		while(ptr_pres != NULL){
			fprintf(fileList, "%ld\t%s\t%d\n", ptr_pres->address, ptr_pres->path, ptr_pres->date);
			if(ptr_pres->address > address && !trouve){
				ptr_add->next = ptr_pres;
				if(*base->next == NULL)
					*base = ptr_add;
				else
					ptr_prev->next = ptr_add;
				trouve = True;
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
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
}

//===================================================================================================
void removeDesc(BaseDesc * base, FileType type){
    if(listIsEmpty(*base))
        /** error **/;
    else{
		char * FileDesc;
		switch(fileType){
			/*case TEXT: strcpy(FileDesc, "TextBaseDesc.db");
		    break;
		    case PICTURE: strcpy(FileDesc, "PictureBaseDesc.db");
		    break;*/
		    case SOUND: strcpy(FileDesc, "SoundBaseDesc.db");
		    break;
		}
		FILE * baseDesc = fopen(FileDesc, "w+");
=======
	//DO THE SAME ON THE FILE LISTBASEDesc
}

//===================================================================================================
void remove(DescBase * p){
    if(listIsEmpty(*p))
        /** error **/;
    else{
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
        BaseDesc ptr_p = *base;
        do{
			writeFile(baseDesc, ptr_p->element);
            if(ptr_p->next == NULL)
                break;
            ptr_p = ptr_p->next;
        }while(ptr_p != NULL);
        free(ptr_p->next)
<<<<<<< HEAD:Descriptor/BaseDescriptor.c
		fclose(baseDesc);    
	}
}

//===================================================================================================
void writeList(BaseDesc * p, fileType t){
    switch(t){
        /*case TEXT: ptr_p = TextDescriptor e;
        break;
        case PICTURE: ptr_p = PictureDescriptor e;
        break;*/
        case SOUND: ptr_p = SoundDescriptor e;
=======
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
>>>>>>> c37d8666579de8b8d1c9081b28837de2c104d40b:Descriptor/BaseDesc.c
        break;
    }
    char choice = 0;
    do{
        addDesc(p, writeElement(&e), t)
        printf("Do you want to add another desc (Y,N)?\n");
        scanf("%s", &choice);
    }while(choice != "n" && choice != "N");
}