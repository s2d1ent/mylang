#ifndef INTERPRETER_H
#define INTERPRETER_H
#define TRANSLATE_MODE_CMPL
#include <stdio.h>
#include <stdlib.h>

char* read(FILE*);

void start(FILE *file){
    #ifdef TRANSLATE_MODE_INTPTR



    #endif /* TRANSLATE_MODE_INTPTR */
    #ifdef TRANSLATE_MODE_CMPL
        printf("You can not compile, this functional is not released.\n");
    #endif /* TRANSLATE_MODE_CMPL */
}

#endif /* INTERPRETER_H */