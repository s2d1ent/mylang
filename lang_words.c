#include "headers/lang_words.h"

// TODO
t_lang_words *rwords(char *in_string){
    t_lang_words *result = NULL;
    if(in_string == NULL){
        return NULL;
    }
    if(strlen(in_string) == 0){
        return NULL;
    }
    

    return result;
}

t_lang_words* parse_str_lngwds(char*){
    t_lang_words *result = (t_lang_words*)malloc(sizeof(t_lang_words));

    

    return result;
}

void free_words(t_lang_words *words){
    if(words == NULL) {
        return;
    }
    free_words(words->next);
    if(words->count != 0){
        for(int i = 0; i < words->count; ++i){
            free(*(words->words+i));
        }
        free(words->words);
    }
    free(words);
}

int add_words(t_lang_words *root, t_lang_words *words){
    if(root == words){
        return 0;
    }
    if(root->next == NULL){
        root->next = words;
    } else {
        t_lang_words *tmp = root;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = words;
    }
    return 1;
}