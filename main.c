#include <stdio.h>
#include <stdlib.h>

#include "./includes/interpreter.h"
#include "./includes/preprocessor.h"
#include "./includes/types.h"

FILE *file = NULL;
FILE *prpcs_file = NULL;

int main(int argc, char *argv[]){
    if(argc - 1 == 0){
        printf("Error: must be input file\n");
    } else {
        file = fopen(argv[1], "r");
        if(file == NULL){
            printf("Error: input file not found\n");
            return 0;
        }
        start(file);

        

        // close source file
        fclose(file);
    }
    return 0;
}