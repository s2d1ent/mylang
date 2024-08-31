#ifndef LANG_STRINGS_C
#define LANG_STRINGS_C 1
#include <stdlib.h>
#include "headers/string_builder.h"
/*
    translator get string:
    -   use string_builder
    -   parse to lang_string
    -   translator got lang_string
    -   translator analyze string in lang_string
    -   translator translate to byte_code
    ...
*/

typedef struct lang_word_s {
    char *value;
    struct lang_word_s *next;
} lang_word;

typedef struct lang_string_s {
    size_t count;
    lang_word *root;
} lang_string;

lang_string* init_lngstr();
lang_string* pasrse_strbld(string_builder*);

void append(lang_string*,char*);

void clear_lngwrd(lang_word*);
void clear_lngwrds(lang_string*);
void free_lngstr(lang_string*);

lang_string* init_lngstr(){
    lang_string *result = (lang_string*)malloc(sizeof(lang_string));
    result->count = 0;
    result->root = NULL;
    return result;
}

#endif