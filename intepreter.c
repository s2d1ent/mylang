#include <stdio.h>
#include <stdlib.h>

#include "./includes/interpreter.h"

void start(FILE *file){
    #ifdef TRANSLATE_MODE_INTPTR
        char* str = file_to_string(file);
        long len = str_len(str);
        int i = -1;
        while(++i < len){
            char c = str[i];
            if(c == ';'){
                continue;
            } else {
                printf("%c", c);
            }
        }
        free(str);
    #endif /* TRANSLATE_MODE_INTPTR */
    #ifdef TRANSLATE_MODE_CMPL
        printf("You can not compile, this functional is not released.\n");
    #endif /* TRANSLATE_MODE_CMPL */
}