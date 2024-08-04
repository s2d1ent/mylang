#include "headers/common.h"

long strlen(char *string){
    long result = 0;
    if(string == NULL){
        return 0;
    }
    while(1){
        if(string[result] == '\0'){
            break;
        }
        ++result;
    }

    return result;
}

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
    char *result;
    char c;
    short length = 0;
    while (1){
        c = getc(file);
        if(c == EOF || c == '\n' || c == '\0'){
            break;
        }
        ++length;
    }
    c = 0;
    fseek(file, -(length+1), SEEK_CUR);
    result = (char*)malloc(length+1);
    result[length] = '\0';
    for(int i = 0, c = getc(file); i < length ; c = getc(file), ++i){
        *(result+i)=c;
    }
    getc(file);
    return result;
}