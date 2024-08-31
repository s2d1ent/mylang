#ifndef LANG_STRING_BUILDER_H
#define LANG_STRING_BUILDER_H 1
#define DEFAULT_STRBLD {0, NULL}
// Max count string_builder_symbol in 1 Mb
#define MAX_LEN_STRBLD 116508
#include <stdio.h>
#include <stdlib.h>

typedef struct string_builder_symbol_s{
    char value;
    struct string_builder_symbol_s *next;
} string_builder_symbol;

typedef struct string_builder_s{
    size_t size;
    string_builder_symbol *root;
} string_builder;

string_builder *init_strbld();
string_builder *slice_strbld(string_builder*, int, int);
string_builder_symbol *last_strbld(string_builder*);
string_builder_symbol *indexof_strbld(string_builder*, int);

long size_strbld(string_builder*);
int is_empty_strbld(string_builder*);
char* get_strbld(string_builder*);

int append_strbld(string_builder*,char);
int append_str_strbld(string_builder*,char*);
int set_string(string_builder*,char*);
void vkiller(string_builder*);

void clear_strbld(string_builder*);
int clear_smbl(string_builder*, string_builder_symbol*);
void free_strbld(string_builder*);

long strlen(char*);
int str_cpy(char*, char*);

long strlen(char *string){
    long result = 0;
    if(string == NULL){
        return 0;
    }
    while(1){
        if(string[result] == '\0'){
            break;
        }
        ++result;
    }

    return result;
}

int str_cpy(char* copy_from, char* copy_to){
    int length = 0;
    if(copy_from == NULL){
        return 0;
    }
    if(copy_to != NULL){
        free(copy_to);
    }
    length = strlen(copy_from);
    copy_to = (char*)malloc(length+1);
    for(int i = 0; i < length; ++i){
        copy_to[i] = copy_from[i];
    }
    copy_to[length] = '\0';
    return 1;
}

string_builder *init_strbld(){
    return ((string_builder*)malloc(sizeof(string_builder)));
}

string_builder *slice_strbld(string_builder *string_builder, int start_index, int count){
    struct string_builder_s *result = NULL;
    string_builder_symbol *tmp = NULL;
    if(string_builder == NULL){
        return NULL;
    }
    if(count == 0){
        return NULL;
    }
    if(start_index > string_builder->size){
        fprintf(stderr, "Override index");
        return NULL;
    }
    result = (struct string_builder_s*)malloc(sizeof(struct string_builder_s));
    tmp = indexof_strbld(string_builder, start_index);
    for(int i = 0; i < count; ++i){
        struct string_builder_symbol_s *buf = tmp;
        append_strbld(result, tmp->value);
        if(tmp->next == NULL){
            break;
        }
        tmp = tmp->next;
        clear_smbl(string_builder, buf);
    }

    return result;
}

string_builder_symbol *indexof_strbld(string_builder *string_builder, int index){
    string_builder_symbol *result = NULL;
    if(string_builder == NULL){
        return NULL;
    }
    if(string_builder->size == 0 || string_builder->root == NULL){
        return NULL;
    }
    if(index > (string_builder->size-1)){
        return NULL;
    }
    if(index == (string_builder->size-1)){
        return last_strbld(string_builder);
    }
    if(index == 0){
        return string_builder->root;
    }
    result = string_builder->root;
    for(int i = 0; i < index; ++i){
        result = result->next;
    }
    return result;
}

void trim(string_builder *string_builder){
    if(string_builder == NULL){
        return;
    }
    if(string_builder->size == 0 || string_builder->root == NULL){
        return;
    }
    while(string_builder->root->value <= (char)32){
        clear_smbl(string_builder, string_builder->root);
    }
    while((last_strbld(string_builder))->value <= (char)32){
        clear_smbl(string_builder, last_strbld(string_builder));
    }
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

string_builder_symbol *last_strbld(string_builder *string_builder){
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

int append_strbld(string_builder *string_builder,char in_symbol){
    string_builder_symbol *tmp_symbol = NULL;
    /*
    if(string_builder->size == MAX_LEN_STRBLD){
       return 0; 
    }
    */
    if(string_builder == NULL){
        return 0;
    }
    if(string_builder->root == NULL){
        string_builder->root = (string_builder_symbol*)malloc(sizeof(string_builder_symbol));
        string_builder->root->value = in_symbol;
        string_builder->size++;
        return 1;
    }
    tmp_symbol = last_strbld(string_builder);
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
    for(int i = 0 ; i < size && i <= MAX_LEN_STRBLD; ++i){
        append_strbld(string_builder, in_string[i]);
    }
    return 1;
}

int append_str(string_builder* string_builder,char* append_string){
    char* old_str = NULL;
    char* new_str = NULL;
    int new_str_length = 0;
    if(string_builder->size > 0){
        int i = 0;
        int pos_old = 0;
        int pos_add = 0;

        int len_old = string_builder->size;
        int len_add = strlen(append_string);
        new_str_length = len_old + len_add;

        old_str = get_strbld(string_builder);
        new_str = (char*)malloc(new_str_length+1);
        for(;i < new_str_length; ++i){
            if(pos_old < len_old){
                new_str[i] = old_str[pos_old];
                ++pos_old;
            }
            else {
                if(pos_add < len_add){
                    new_str[i] = append_string[pos_add];
                    ++pos_add;
                }
            }
        }

    } else {
        new_str = append_string;
    }
    
    set_string(string_builder, new_str);
    free(new_str);
    return 1;
}

int clear_smbl(string_builder *string_builder, 
                string_builder_symbol *string_builder_symbol){
    int result = 1;
    struct string_builder_symbol_s *tmp = NULL;
    struct string_builder_symbol_s *tmp2 = NULL;
    if(string_builder == NULL || string_builder_symbol == NULL){
        return 0;
    }
    if(string_builder->size == 0 || string_builder->root == NULL){
        return 0;
    }
    if(string_builder_symbol == string_builder->root){
        tmp2 = (string_builder_symbol->next == NULL ? 
            NULL : string_builder_symbol->next);
        string_builder->root = tmp2;
    } else {
        tmp = string_builder->root;
        tmp2 = (string_builder_symbol->next == NULL ? 
            NULL : string_builder_symbol->next);
        while(tmp->next != string_builder_symbol){
            if(tmp->next == NULL){
                return 0;
            }
            tmp = tmp->next;
        }
        tmp->next = tmp2;
    }

    string_builder_symbol->value = 0;
    string_builder_symbol->next  = NULL;
    free(string_builder_symbol);
    string_builder->size--;
    return result;
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