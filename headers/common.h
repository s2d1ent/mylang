#ifndef LANG_COMMON_H
#define LANG_COMMON_H 1
#include <stdio.h>
#include <stdlib.h>
long strlen(char*);
char* frword(FILE*);
char* frstr(FILE*);

///  
/// define list
///
typedef struct define_item
{
    char *name;
    char *value;
    struct define_item *next;
} t_define_item;

struct
{
    int count;
    t_define_item *first;
    t_define_item *last;
} define_list;

void free_define();
void free_define_rec(t_define_item*);
void add_define(char*, char*);
char *get_value_define(char*);
#endif