#ifndef TRANSLATOR_C
#define TRANSLATOR_C 1
#include <stdio.h>
#include "headers/lang_types.h"
#include "headers/string_builder.h"
#include "common.c"
#include "preprocessor.c"

int lang_init(FILE *file){

   while(1){
      char *string = frstr(file);
      char is_comment = 0;
   }
   return 1;
}

#endif