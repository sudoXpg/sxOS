#include "memset.h"


void *memset(void *ptr, int c, size_t size){
    unsigned char *char_ptr=(unsigned char*)ptr;     // cast it to char to use indexing
    for(int i=0;i<size;i++){
        char_ptr[i]=(unsigned char)c;
    }
    return ptr;
}