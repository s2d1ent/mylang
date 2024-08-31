#ifndef LANG_TRANSLATOR_SHARE_C
#define LANG_TRANSLATOR_SHARE_C 1
#define LANG_TYPES_COUNT 12
#define ANALYZER_DATA_DEFAULT {NULL, NULL}
#include "../headers/string_builder.h"

void types_checker(char*);
int type_is_select();
void drop_analyzer_types();

void operation_checker(char*);
int operation_is_select();
void drop_analyzer_operations();

string_builder *data_segment;
string_builder *static_data_segment;
string_builder *text_segment;

typedef struct analyzer_data_s{
   char* name;
   char* value;
} analyzer_data;

char *lang_types[] = {
    "char",
    "byte",
    "short",
    "int",
    "long",
    "float",
    "double",
    "const",
    "unsigned",
    "null",
    "func",
    "struct"
};

struct analyzer_types_s
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

struct analyzer_operations_s
{
   /* math */
   int is_add            :1; /* + */
   int is_sub            :1; /* - */
   int is_mul            :1; /* * */
   int is_div            :1; /* / */
   int is_equal          :1; /* = */
   /* comparison */
   int is_more           :1; /* > */
   int is_less           :1; /* < */
   int is_mreq           :1; /* >= */
   int is_lseq           :1; /* <= */
   int is_dequal         :1; /* == */
   int is_comp_and       :1; /* && */
   int is_comp_or        :1; /* || */
   int is_comp_not       :1; /* ! */
   /* logic */
   int is_logic_and      :1; /* & */
   int is_logic_or       :1; /* | */
   int is_logic_not      :1; /* ! */
   int is_logic_xor      :1; /* ^ */
   int is_logic_lshift   :1; /* << */
   int is_logic_rshift   :1; /* >> */
   /* reserved */
   int is_reserved_20    :1;
   int is_reserved_21    :1;
   int is_reserved_22    :1;
   int is_reserved_23    :1;
   int is_reserved_24    :1;
   int is_reserved_25    :1;
   int is_reserved_26    :1;
   int is_reserved_27    :1;
   int is_reserved_28    :1;
   int is_reserved_29    :1;
   int is_reserved_30    :1;
   int is_reserved_31    :1;
   int is_reserved_32    :1;
   //32 bit
} analyzer_operations;

int type_is_select(){
   return (*((short*)&analyzer_types) > 0 ? 1 : 0);
}

int operation_is_select(){
   return (*((unsigned int*)&analyzer_operations) > 0 ? 1 : 0);
}

void drop_analyzer_types(){
  *((unsigned short*)&analyzer_types) = 0;
}

void drop_analyzer_operations(){
   *((unsigned int*)&analyzer_operations) = 0;
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

void operation_checker(char* symbol){
   if(symbol == "+" )      analyzer_operations.is_add          = 1;
   else if(symbol == "-" ) analyzer_operations.is_sub          = 1;
   else if(symbol == "*" ) analyzer_operations.is_mul          = 1;
   else if(symbol == "/" ) analyzer_operations.is_div          = 1;
   else if(symbol == "=" ) analyzer_operations.is_equal        = 1;
   else if(symbol == ">" ) analyzer_operations.is_more         = 1;
   else if(symbol == "<" ) analyzer_operations.is_less         = 1;
   else if(symbol == ">=") analyzer_operations.is_mreq         = 1;
   else if(symbol == "<=") analyzer_operations.is_lseq         = 1;
   else if(symbol == "==") analyzer_operations.is_dequal       = 1;
   else if(symbol == "&&") analyzer_operations.is_comp_and     = 1;
   else if(symbol == "||") analyzer_operations.is_comp_or      = 1;
   else if(symbol == "!" ) analyzer_operations.is_comp_not     = 1;
   else if(symbol == "&" ) analyzer_operations.is_logic_and    = 1;
   else if(symbol == "|" ) analyzer_operations.is_logic_or     = 1;
   else if(symbol == "~" ) analyzer_operations.is_logic_not    = 1;
   else if(symbol == "^" ) analyzer_operations.is_logic_xor    = 1;
   else if(symbol == "<<") analyzer_operations.is_logic_lshift = 1;
   else if(symbol == ">>") analyzer_operations.is_logic_rshift = 1;
}

#endif