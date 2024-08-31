#ifndef LANG_PREPROCC_DEFINE_H
#define LANG_PREPROCC_DEFINE_H 1
#include <stdlib.h>

typedef struct define_item_s
{
    char *name;
    char *value;
    struct define_item_s *next;
} define_item;

struct
{
    int count;
    define_item *first;
    define_item *last;
} define_list;

void free_define();
void free_define_rec(define_item*);
void add_define(char*, char*);
char *get_value_define(char*);


#endif