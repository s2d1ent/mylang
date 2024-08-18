#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.c"
#include "translator.c"
#include "lang_words.c"

int main(int argc, char **argv){
    printf("ALPHA MyLang.\n");
    printf("Version 0.1\n");
    printf("ONLY INTERPRETER MODE\n");
    FILE *input_file = fopen("./source/main.lng", "r");
    FILE *output_file = fopen("a.out", "w");

    //lang_init(fp);
    
    string_builder *sb = init_strbld();
    set_string(sb, "   Hello, World!");
    /*
        13
    */

    printf("%s\n", get_strbld(sb));

    fclose(input_file);
    fclose(output_file);
    return 0;
}