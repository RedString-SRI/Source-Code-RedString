
#include "BaseDescriptor.h"
/*
//Permit to clear out the buffer : Use to secure datas
void clearBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}
*/

// Initializes a list with a null pointer p
void initList(BaseDescriptor * base){
    *base = NULL;
}
//===================================================================================================
// Prints every elements of the list, just using this for debugging
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
// Checks if the the list is empty
Bool listIsEmpty(BaseDescriptor base){
    return(base==NULL);
}
//===================================================================================================
// Add a descriptor into the base
void addDescriptor(BaseDescriptor * base, void * structDescriptor, FileType type){
    BaseDescriptor ptr_p;
    switch(type){
        case TEXT: ptr_p = malloc(sizeof(TextDescriptor));
        break;
        case IMAGE: ptr_p = malloc(sizeof(PictureDescriptor));
        break;
        case SOUND: ptr_p = malloc(sizeof(SoundDescriptor));
        break;
    }
    if(*base==NULL)
        /** Error **/
    else{
        ptr_p->next = *base;
        *base = ptr_p;
        affectElement(&(ptr_p->element), *e);
    }
}
//===================================================================================================
// Unstack the first element
void unstack(DescriptorBase * p){
    if(stackIsEmpty(*p))
        messageError(1);
    else{
        void * ptr_p = *p;
        *p = ptr_p->next;
        free(ptr_p);
    }
}
//===================================================================================================
// The user has to give elements to stack into the DescriptorBase
void writeStack(DescriptorBase * p, fileType t){
    switch(t){
        case TEXT: ptr_p = TextDescriptor e;
        break;
        case IMAGE: ptr_p = PictureDescriptor e;
        break;
        case SOUND: ptr_p = SoundDescriptor e;
        break;
    }
    char choice = 0;
    do{
        stack(p, writeElement(&e), t)
        printf("Do you wan't to add another element (Y,N)?\n");
        scanf("%s", &choice);
    }while(choice != "n" && choice != "N");
}
