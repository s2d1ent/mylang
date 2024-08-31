#ifndef LANG_ANALYZER_C
#define LANG_ANALYZER_C 1
#include "translator_share.c"
#include "lexer.c"

int init_analyzer(char *input_string){
int length = strlen(input_string);
   int cur_pos = 0;
   int cur_pos_old = 0;
   char* c = NULL;
   analyzer_data data = ANALYZER_DATA_DEFAULT;
   string_builder* sb = init_strbld(); 
   
   if(input_string == NULL){
      return 0;
   }
   
   c = input_string;
   
   while(1){
      char* tmp_str = NULL;
      if(*c == '\0') {
         break;
      }
      while((*c != ' ' && *c != '\0')){
         ++c;
         ++cur_pos;
      }
      tmp_str = (char*)malloc(cur_pos - cur_pos_old + 1);
      for(int i = 0, j = cur_pos_old; i < (cur_pos - cur_pos_old); ++i, ++j){
         tmp_str[i] = input_string[j];
      }
      tmp_str[cur_pos - cur_pos_old] = '\0';

      init_lexer(tmp_str, &data);

      if(*c == ' '){
         ++c;
         ++cur_pos;
      }
      cur_pos_old = cur_pos;
      free((void*)tmp_str);
   }

   if(data.name != NULL){
      free((void*)data.name);
   }
   if(data.value != NULL){
      free((void*)data.value);
   }
   return 1;
}

#endif