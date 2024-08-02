#ifndef LANG_STRING_BUILDER_H
#define LANG_STRING_BUILDER_H 1
#define DEFAULT_STRBLD {0, NULL}
// 1 Mb
#define MAX_LEN_STRBLD 1048576
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct string_builder_symbol_s{
    char value;
    struct string_builder_symbol_s *next;
} string_builder_symbol;

typedef struct string_builder_s{
    long size;
    string_builder_symbol *root;
} string_builder;

string_builder *init_strbld();
long size_strbld(string_builder*);
int is_empty_strbld(string_builder*);
char* get_strbld(string_builder*);
int set_symbol(string_builder*,char);
int set_string(string_builder*,char*);
string_builder_symbol *get_last_strbld(string_builder*);
void clear_strbld(string_builder*);
void free_strbld(string_builder*);

#endif