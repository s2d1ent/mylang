#ifndef COMMON_H
#define COMMON_H 
#define TRANSLATE_MODE_INTPTR
/*
TRANSLATE_MODE_INTPTR - for intepretation code
TRANSLATE_MODE_CMPL - for compile code
*/
#include <stdio.h>
#include <stdlib.h>

long str_len(char* str);
long flen(FILE*);
char* file_to_string(FILE*);

#endif // !COMMON_H