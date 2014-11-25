
#include "BaseDescriptor.h"

//Permit to clear out the buffer : Use to secure datas
void clearBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

//Send an error adapted message
void messageError(int i){
    switch(i){
        case 1: printf("The stack is empty\n");
        break;
        case 2: printf("The memory is full\n");
        // We'll see every messages to put later...
    }
}

BOOL pathExist(char[] path) {
    int answer;
    char sentence[50]="[ ! -f ";
    char sentenceEnd[5]=" ]";
    strcat(sentence,path);
    strcat(sentence,sentenceEnd);
    answer=system(sentence);
    if(answer==0)
        return FALSE;
    else
        return TRUE;
}

//Check if the path is right
BOOL pathExist(String path){
    
}

// Initializes a stack with a null pointer p
void initStack(DescriptorBase * p){
    *p = NULL;
}

// Prints every elements of the stack
void printStack(DescriptorBase p){
    // If the stack is empty
    if(stackIsEmpty(p))
        messageError(1);
    else{
        void * ptr_p = p;
        // We are using the pointer to travel few every element of the stack until the last one
        while(p!=NULL){
            printElement(ptr_p->element);
            ptr_p = ptr_p->next;
        }
    }
}

// Checks if the the stack is empty
BOOL stackIsEmpty(DescriptorBase p){
    return(p==NULL);
}

// Stack an element into p
void stack(DescriptorBase * p, void e, fileType t){
    void * ptr_p;
    switch(t){
        case TEXT: ptr_p = malloc(sizeof(TextDescriptor));
        break;
        case IMAGE: ptr_p = malloc(sizeof(PictureDescriptor));
        break;
        case SOUND: ptr_p = malloc(sizeof(SoundDescriptor));
        break;
    }
    if(ptr_p==NULL)
        messageError(2);
    else{
        ptr_p->next = *p;
        *p = ptr_p;
        affectElement(&(ptr_p->element), e);
    }
}

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
