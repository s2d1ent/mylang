#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.c"
#include "translator.c"

int main(int argc, char **argv){
    printf("ALPHA MyLang.\n");
    printf("Version 0.1\n");
    printf("ONLY INTERPRETER MODE\n\n");
    FILE *input_file = fopen("./source/main.lng", "r");
    FILE *output_file = fopen("./source/a.out", "w");

    init_lang(input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0;
}