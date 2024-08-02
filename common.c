#include "headers/common.h"

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

char* frword(FILE *file){
    char *result;
    char c;
    short length = 0;
    while (1){
        c = getc(file);
        if(c == ' ' || c == EOF || c == '\n'){
            break;
        }
        ++length;
    }
    c = 0;
    fseek(file, -(length+1), SEEK_CUR);
    result = (char*)malloc(length+1);
    result[length] = '\0';
    for(int i = 0; i < length ; ++i){
        *(result+i) = (char)getc(file);
    }
    getc(file);
    return result;
}

char* frstr(FILE *file){
    char *result;
    char c;
    short length = 0;
    while (1){
        c = getc(file);
        if(c == EOF || c == '\n' || c == '\0'){
            break;
        }
        ++length;
    }
    c = 0;
    fseek(file, -(length+1), SEEK_CUR);
    result = (char*)malloc(length+1);
    result[length] = '\0';
    for(int i = 0, c = getc(file); i < length ; c = getc(file), ++i){
        *(result+i)=c;
    }
    getc(file);
    return result;
}

///  
/// define list
///

void free_define(){
    if(define_list.first == NULL){
        return;
    }
    free_define_rec(define_list.first);
}

void free_define_rec(t_define_item *item){
    if(item->next != NULL){
        free_define_rec(item->next);
    }
    free(item);
}

void add_define(char *name, char *value){
    t_define_item *item = malloc(sizeof(t_define_item));
    item->name = name;
    item->value = value;
    if(define_list.first == NULL){
        define_list.first = item;
        define_list.last = item;
        define_list.count++;
    } else {
        define_list.last->next = item;
        define_list.last = item;
        define_list.count++;
    }
}
char *get_value_define(char *define_name){
    char *result;

    return result;
}

//
//  variable list
//

//
//  
//