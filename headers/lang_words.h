#ifndef LANG_WORDS_H
#define LANG_WORDS_H 1
#include <stdlib.h>
#include "common.h"

typedef struct lang_words{
    int count;
    char **words;
    struct lang_words *next;
} t_lang_words;

typedef struct root_lang_words{
    int count;
    struct lang_words *next;
} t_root_lang_words;
void free_words(t_lang_words*);
int add_words(t_lang_words*,t_lang_words*);
t_lang_words* rwords(char*);
t_lang_words* parse_str_lngwds(char*);


typedef enum e_lang_types {
    CHAR,
    BYTE,
    SHORT,
    INT,
    LONG,
    FLOAT,
    DOUBLE,
    CONST, // SET CONST FLAG
    UNSIGNED, // SET UNSIHNED FLAG
    L_NULL, // DOES VALUE VARIABLE IS NULL
    FUNC
} t_lang_types;

#endif