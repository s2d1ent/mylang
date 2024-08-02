#include <stdio.h>
#include <stdlib.h>
#include "common.c"
#include "byte_code.c"
#include "lang_words.c"
#include "string_builder.c"

string_builder_symbol *func(string_builder_symbol *string_builder){
    string_builder_symbol *result = string_builder;
    while(1){
        if(result->next == NULL){
            break;
        }
        result = result->next;
    }
    return result;
}

int main(int argc, char **argv){
    printf("ALPHA MyLang.\n");
    printf("Version 0.1\n");
    printf("ONLY INTERPRETER MODE\n");
    FILE *fp = fopen("./source/main.lng", "r");

    //byte_init(fp);
    
    //t_lang_words *a = rwords("int a = 5");
   //t_string_builder sb = DEFAULT_STRBLD;
    string_builder *sb = init_strbld();
    char *str = "Hello, World!";
    set_symbol(sb, 'H');
    set_symbol(sb, 'e');
    set_symbol(sb, 'l');
    set_symbol(sb, 'l');
    set_symbol(sb, 'o');
    set_symbol(sb, ',');
    set_symbol(sb, ' ');
    set_symbol(sb, 'w');
    set_symbol(sb, 'o');
    set_symbol(sb, 'r');
    set_symbol(sb, 'l');
    set_symbol(sb, 'd');
    set_symbol(sb, '!');
    printf("%s\n", get_strbld(sb));
    set_string(sb, "I'am so bad developer and i would like to be better version myself. I dont't will scream or cry. I will calm/relax everytime.");
    printf("%s\n", get_strbld(sb));
    set_string(sb, "Hi guys!");
    printf("%s\n", get_strbld(sb));
    

    free_strbld(sb);
    fclose(fp);
    //free_words(a);
    return 0;
}