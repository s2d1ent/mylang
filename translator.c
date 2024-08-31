#ifndef TRANSLATOR_C
#define TRANSLATOR_C 1
#include <stdio.h>
#include "common.c"
#include "preprocessor.c"

#include "translator/translator_share.c"
#include "translator/lexer.c"
#include "translator/analyzer.c"

int init_lang(FILE *fin, FILE *fout){
   int preproc_fin = init_preprocessor();
   data_segment = init_strbld();
   static_data_segment = init_strbld();
   text_segment = init_strbld();
   drop_analyzer_types();
   drop_analyzer_operations();
   if(preproc_fin == 0){
      printf("Error: preprocessor\n");
      return 0;
   }
   while(feof(fin) == 0){
      char *string;

      string = frstr(fin);
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
      init_analyzer(string);

      free((void*)string);
   }
   return 1;
}

#endif