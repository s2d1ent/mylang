#include "./includes/common.h"

long flen(FILE *file){
    long result = 0;
    char c = 0;
    while((c = getc(file)) != EOF){
        ++result;
    }
    fseek(file, 0, SEEK_SET);
    return result;
}

long str_len(char* str){
    long result = 0;
    char c = 0;
    while((c = str[result]) != '\0'){
        ++result;
    }
    return result;
}

char* file_to_string(FILE *file){
    char* result = NULL;
    long len = flen(file);
    result = malloc(len + 1);
    result[len] = '\0';
    for(int i = 0; i < len; ++i){
        result[i] = getc(file);
    }
    return result;
}