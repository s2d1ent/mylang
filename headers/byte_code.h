#ifndef BYTE_CODE_H
#define BYTE_CODE_H 1
#include <stdio.h>
#include "common.h"
#include "lang_types.h"
#include "string_builder.h"

int byte_init(FILE*);

struct {
    size_t size;
    string_builder *root;
    string_builder *last;
} lang_string;

string_builder* parse_string(char*);
void add_lstr(void*,char*);
void last_lstr(void*);
void size_lstr(void*);

#endif