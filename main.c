#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.c"
#include "translator.c"
#include "lang_words.c"
#include "./headers/string_builder.h"

int main(int argc, char **argv){
    printf("ALPHA MyLang.\n");
    printf("Version 0.1\n");
    printf("ONLY INTERPRETER MODE\n");
    FILE *fp = fopen("./source/main.lng", "r");

    //lang_init(fp);
    
    fclose(fp);
    return 0;
}