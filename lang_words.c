#ifndef LANG_WORDS_C
#define LANG_WORDS_C 1
#define SENTENCE_STD {0, NULL}
#define SENTENCE_WORD_STD {NULL, NULL}
#include "headers/string_builder.h"

typedef struct sentence_word_s {
    string_builder *root;
    struct sentence_word_s *next;
} sentence_word;

typedef struct sentence_s {
    size_t size;
    sentence_word *root;
} sentence;

sentence* init_sntnc();
sentence_word* init_sntnc_word();
void add_sntnc(sentence*,string_builder*);
size_t size_sntnc(sentence*);
void free_sntnc(sentence*);
void clear_sntnc_words(sentence_word*);
sentence* parse_strbld(string_builder*);
sentence_word* last_sntnc(sentence*);
int is_empty_sntnc(sentence*);

sentence* init_sntnc(){
    sentence* result = (sentence*)malloc(sizeof(sentence));
    result->size = 0;
    result->root = NULL;
    return result;
}

sentence_word* init_sntnc_word(){
    sentence_word* result = (sentence_word*)malloc(sizeof(sentence_word));
    result->root = NULL;
    result->next = NULL;
    return result;
}

size_t size_sntnc(sentence* sentence){
    return sentence->size;
}

int is_empty_sntnc(sentence *sentence){
    return (size_sntnc(sentence) == 0 ? 1 : 0);
}

sentence_word* last_sntnc(sentence *sentence){
    sentence_word *result = NULL;
    if(sentence == NULL){
        return NULL;
    }
    if(sentence->size == 0){
        return NULL;
    }
    if(sentence->root == NULL){
        return NULL;
    }
    result = sentence->root;
    while(1){
        if(result->next == NULL){
            break;
        }
        result = result->next;
    }

    return result;
}

void add_sntnc(sentence* sentence, string_builder* string_builder){
    sentence_word *tmp = NULL;
    if(sentence == NULL){
        return;
    }
    if(string_builder == NULL){
        return;
    }
    if(is_empty_sntnc(sentence)){
        tmp = (sentence_word*)malloc(sizeof(sentence_word));
        tmp->root = string_builder;
        sentence->root = tmp;
        sentence->size++;
        return;
    }
    tmp = last_sntnc(sentence);
    tmp->next = (sentence_word*)malloc(sizeof(sentence_word));
    tmp->next->root = string_builder;
    sentence->size++;
}
// TODO
sentence* parse_strbld(string_builder* string_builder){
    sentence *result = NULL;
    sentence_word *tmp = NULL;
    if(string_builder == NULL){
        return NULL;
    }
    if(string_builder->size == 0 || string_builder->root == NULL){
        return NULL;
    }
    result = (sentence*)malloc(sizeof(sentence));
    while(1){

    }
    return result;
}

void free_sntnc(sentence* sentence){
    if(sentence->size > 0){
        clear_sntnc_words(sentence->root);
        sentence->root = NULL;
        sentence->size = 0;
    }
    free(sentence);
}

void clear_sntnc_words(sentence_word* sentence_word){
    if(sentence_word == NULL){
        return;
    }
    if(sentence_word->next != NULL){
        clear_sntnc_words(sentence_word->next);
        sentence_word->next = NULL;
    }
    if(sentence_word->root != NULL){
        free_strbld(sentence_word->root);
        sentence_word->root = NULL;
    }
    free(sentence_word);
}

#endif