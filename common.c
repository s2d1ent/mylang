#ifndef LANG_COMMON_H
#define LANG_COMMON_H 1
#include <stdio.h>
#include <stdlib.h>
char* frword(FILE*);
char* frstr(FILE*);

char* frword(FILE *file){
    char *result;
    char c;
    short length = 0;
    while (1){
        c = getc(file);
        if(c == ' ' || c == EOF || c == '\n'){
            break;
        }
        ++length;
    }
    c = 0;
    fseek(file, -(length+1), SEEK_CUR);
    result = (char*)malloc(length+1);
    result[length] = '\0';
    for(int i = 0; i < length ; ++i){
        *(result+i) = (char)getc(file);
    }
    getc(file);
    return result;
}

char* frstr(FILE *file){
    char* result = NULL;
    char c = 0;
    short length = 0;
    if(feof(file) != 0){
        return NULL;
    }
    while(1){
        c = getc(file);
        if(c == EOF){
            break;
        }        
        if(c == '\n' || c == '\0'){
            ++length;
            break;
        }
        ++length;
    }
    if(c == EOF){
        result = (char*)malloc(length+1);
    } else {
        result = (char*)malloc(length);
    }
    fseek(file, -(length), SEEK_CUR);

    for(int i = 0; i < length; ++i){   
        result[i] = getc(file);
    }

    if(c == EOF){
        result[length] = '\0';
        while(feof(file) == 0){
            getc(file);
        }
    } else {
        result[length-1] = '\0';
    }
    return result;
}

#endif