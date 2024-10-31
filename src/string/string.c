#include "string.h"

int strlen(const char *str){    // provides the length of string 'str'
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}



