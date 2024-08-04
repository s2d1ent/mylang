#ifndef LANG_STRING_BUILDER_H
#define LANG_STRING_BUILDER_H 1
#define DEFAULT_STRBLD {0, NULL}
// Max count string_builder_symbol in 1 Mb
#define MAX_LEN_STRBLD 116508
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct string_builder_symbol_s{
    char value;
    struct string_builder_symbol_s *next;
} string_builder_symbol;

typedef struct string_builder_s{
    size_t size;
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



string_builder *init_strbld(){
    return ((string_builder*)malloc(sizeof(string_builder)));
}

long size_strbld(string_builder *string_builder){
    return string_builder->size;
}

int is_empty_strbld(string_builder *string_builder){
    return (string_builder->size == 0 ? 1 : 0);
}

char* get_strbld(string_builder *string_builder){
    char *result = NULL;
    string_builder_symbol *tmp = NULL;
    if(string_builder->size == 0){
        return NULL;
    }
    result = (char*)malloc(string_builder->size + 1);
    result[string_builder->size+1] = '\0';
    tmp = string_builder->root;
    for(int i = 0; i < string_builder->size; ++i){
        result[i] = tmp->value;
        tmp = tmp->next;
    }
    return result;
}

string_builder_symbol *get_last_strbld(string_builder *string_builder){
    string_builder_symbol *result = NULL;
    if(string_builder == NULL){
        return NULL;
    }
    if(string_builder->size == 0){
        return NULL;
    }
    if(string_builder->size == 1){
        return string_builder->root;
    }
    result = string_builder->root;
    while(1){
        if(result->next == NULL){
            break;
        }
        result = result->next;
    }
    return result;
}

int set_symbol(string_builder *string_builder,char in_symbol){
    string_builder_symbol *tmp_symbol = NULL;
    if(string_builder == NULL){
        return 0;
    }
    if(string_builder->root == NULL){
        string_builder->root = (string_builder_symbol*)malloc(sizeof(string_builder_symbol));
        string_builder->root->value = in_symbol;
        string_builder->size++;
        return 1;
    }
    tmp_symbol = get_last_strbld(string_builder);
    tmp_symbol->next = (string_builder_symbol*)malloc(sizeof(string_builder_symbol));
    tmp_symbol->next->value = in_symbol;
    string_builder->size++;
    return 1;
}

int set_string(string_builder *string_builder,char *in_string){
    int size = strlen(in_string);
    if(string_builder == NULL){
        return 0;
    }
    if(strlen(in_string) == 0){
        return 0;
    }
    if(!is_empty_strbld(string_builder)){
        clear_strbld(string_builder);
    }
    for(int i = 0 ; i < size; ++i){
        set_symbol(string_builder, in_string[i]);
    }
    return 1;
}

void free_smbls(string_builder_symbol *string_builder_symbol){
    if(string_builder_symbol == NULL){
        return;
    }
    if(string_builder_symbol->next != NULL){
        free_smbls(string_builder_symbol->next);
    }
    string_builder_symbol->next = NULL;
    free(((void*)string_builder_symbol));
}

void clear_strbld(string_builder *string_builder){
    free_smbls(string_builder->root);
    string_builder->size = 0;
    string_builder->root = NULL;
}
void free_strbld(string_builder *string_builder){
    if(string_builder == NULL){
        return;
    }
    if(!is_empty_strbld(string_builder)){
        clear_strbld(string_builder);
    }
    free(string_builder);
}

#endif