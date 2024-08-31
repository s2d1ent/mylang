#ifndef LANG_LEXER_C
#define LANG_LEXER_C 1
#include "translator_share.c"
// TODO
int init_lexer(char *input_string, analyzer_data *data){
//check integral types
   if(type_is_select() == 0){
      types_checker(input_string);
      if(type_is_select() == 1){
         return 1;
      }
   }
   
   return 1;
}

#endif