#include <stdio.h>
#include <stdlib.h>

#include "./includes/interpreter.h"

char isEnd = 0;

char* getstr(FILE *file){

    char c = 0;
    char *str = NULL;
    int length = 0, i = -1;
    while((c = getc(file)) != '\n'){
        if(c == EOF){
            isEnd = 1;
            ++length;
            break;
        }
        ++length;
    }
    printf("%d\n", length);
    fseek(file, (length + 1) * -1, SEEK_CUR);
    str = malloc(length + 1);
    str[length] = '\0';
    while(++i < length){        
        str[i] = getc(file);
    }
    fseek(file, 1, SEEK_CUR);
    return str;
}

void start(FILE *file){
    #ifdef TRANSLATE_MODE_INTPTR
    char* str = NULL;

    while(isEnd != 1){
        str = getstr(file);
        printf("%s\n", str);    

        free(str);
    }
    #endif /* TRANSLATE_MODE_INTPTR */
    #ifdef TRANSLATE_MODE_CMPL
        printf("You can not compile, this functional is not released.\n");
    #endif /* TRANSLATE_MODE_CMPL */
}