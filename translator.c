#ifndef TRANSLATOR_C
#define TRANSLATOR_C 1
#define ANALYZER_DATA_DEFAULT {NULL, NULL}
#include <stdio.h>

#include "headers/lang_types.h"
#include "headers/string_builder.h"
#include "common.c"
#include "preprocessor.c"

struct
{
   int is_type          :1; /* user type */
   int is_func          :1;
   int is_struct        :1;
   int is_const         :1;
   int is_unsigned      :1;
   int is_null          :1;
   int is_char          :1;
   int is_short         :1;
   int is_int           :1;
   int is_long          :1;
   int is_float         :1;
   int is_double        :1;
   int is_global_view   :1;
   int is_local_view    :1;
   int create           :1;
   int is_exist         :1;
   int is_reserved_1    :1;
   //16 bit
} analyzer_types;

typedef struct analyzer_data_s{
   char* name;
   char* value;
} analyzer_data;

int lang_parser(char*);
int lang_lexer(char*);
void types_checker(char*);
int type_selected();
void drop_analyzer_types();

int lang_init(FILE *fin, FILE *fout){
   drop_analyzer_types();
   while(feof(fin) == 0){
      char *string;

      string = read_fstr(fin);
      if(string == NULL){
         break;
      }
      if(string[0] == '#'){
         free((void*)string);
         continue;
      }
      /*
         anylize string
      */
      lang_parser(string);

      free((void*)string);
   }
   return 1;
}
// TODO
// If dont have problems return 1
int lang_parser(char* input_string){
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

      lang_lexer(tmp_str);

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

int lang_lexer(char* lex_string){
   //check integral types
   if(type_selected() == 0){
      types_checker(lex_string);
      if(type_selected() == 1){
         return 1;
      }
   }
   
   return 1;
}

int type_selected(){
   if(analyzer_types.is_func     == 1) return 1;
   if(analyzer_types.is_struct   == 1) return 1;
   if(analyzer_types.is_const    == 1) return 1;
   if(analyzer_types.is_unsigned == 1) return 1;
   if(analyzer_types.is_null     == 1) return 1;
   if(analyzer_types.is_char     == 1) return 1;
   if(analyzer_types.is_short    == 1) return 1;
   if(analyzer_types.is_int      == 1) return 1;
   if(analyzer_types.is_long     == 1) return 1;
   if(analyzer_types.is_float    == 1) return 1;
   if(analyzer_types.is_double   == 1) return 1;
   return 0;
}

void types_checker(char* check_str){
   if(check_str == lang_types[0])       analyzer_types.is_char     = 1;
   else if(check_str == lang_types[1])  analyzer_types.is_char     = 1;
   else if(check_str == lang_types[2])  analyzer_types.is_short    = 1;
   else if(check_str == lang_types[3])  analyzer_types.is_int      = 1;
   else if(check_str == lang_types[4])  analyzer_types.is_long     = 1;
   else if(check_str == lang_types[5])  analyzer_types.is_float    = 1;
   else if(check_str == lang_types[6])  analyzer_types.is_double   = 1;
   else if(check_str == lang_types[7])  analyzer_types.is_const    = 1;
   else if(check_str == lang_types[8])  analyzer_types.is_unsigned = 1;
   else if(check_str == lang_types[9])  analyzer_types.is_null     = 1;
   else if(check_str == lang_types[10]) analyzer_types.is_func     = 1;
   else if(check_str == lang_types[11]) analyzer_types.is_struct   = 1;
   else                                 analyzer_types.is_type     = 1;
}

void drop_analyzer_types(){
   //analyzer_types
   analyzer_types.is_type        = 0;
   analyzer_types.is_func        = 0;
   analyzer_types.is_struct      = 0;
   analyzer_types.is_const       = 0;
   analyzer_types.is_unsigned    = 0;
   analyzer_types.is_null        = 0;
   analyzer_types.is_char        = 0;
   analyzer_types.is_short       = 0;
   analyzer_types.is_int         = 0;
   analyzer_types.is_long        = 0;
   analyzer_types.is_float       = 0;
   analyzer_types.is_double      = 0;
   analyzer_types.is_global_view = 0;
   analyzer_types.is_local_view  = 0;
   analyzer_types.create         = 0;
   analyzer_types.is_exist       = 0;
   analyzer_types.is_reserved_1  = 0;
   //analyzer_types 16 bits
}

#endif