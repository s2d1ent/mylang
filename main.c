#include <stdio.h>
#include <stdlib.h>
#include "common.c"
#include "byte_code.c"
#include "./headers/string_builder.h"

int main(int argc, char **argv){
    printf("ALPHA MyLang.\n");
    printf("Version 0.1\n");
    printf("ONLY INTERPRETER MODE\n");
    FILE *fp = fopen("./source/main.lng", "r");

    byte_init(fp);
    
    fclose(fp);
    return 0;
}