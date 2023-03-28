#ifndef TYPES_H
#define TYPES_H

char *operators[] = {
    "func",
    "*"
};

typedef enum types{
    TYPES_NONE,
    INT,
    FLOAT,
    STRING,
    STRUCT,
    CLASS,
    ARRAY
} types_t;

typedef struct element{
    char *name;
    void *value;
    types_t type;
    types_t type1;
} element_t;

typedef struct tokens_tree{

} token_tree_t;

typedef struct tokens_tree_root{

} token_tree_root_t;

#endif /* TYPES_H */