#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

typedef enum prpcs_types{
    PRPCS_NONE,
    IMPORT,
    DEFINE,
    START_IF,
    END_IF
} prpcs_types_t;

char *prpcs_operators[] = {
    "@import",
    "@define",
    "@global"
};
void prpcs_import();
void prpcs_define();
void prpcs_global();


#endif /* PREPROCESSOR_H */