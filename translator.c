#ifndef TRANSLATOR_C
#define TRANSLATOR_C 1
#include <stdio.h>
#include "common.c"
#include "headers/lang_types.h"
#include "headers/string_builder.h"

char translation_mode = 0;
/*
0 - interpreter
1 - translate to NASM
2 - compile
*/

int lang_init(FILE*);

int lang_init(FILE *file){
   
     while(1){
        char *string = frstr(file);
        char is_comment = 0;

     }

    return 1;
}

#endif