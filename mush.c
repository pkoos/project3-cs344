#include "mush.h"

void tokenize(char *dest[WORD_COUNT], char * src) {
    char * tok = strtok(src, DELIM);
    int i = 0;
    while(tok != NULL) {
        dest[i] = (char *) malloc(sizeof(char) * strlen(tok));

        strcpy(dest[i++], tok);
        tok = strtok(NULL, DELIM);
    }
    dest[i] = NULL;
    if(DEBUG) {
        for(;i>=0;i--) {
            printf("Output[%d]: %s\n", i, dest[i]);
        }
    }
}

int main(void) {
    while(1) {
        printf("%s", prompt);
        
        input = (char *) malloc(MAX_LENGTH);
        fgets(input, MAX_LENGTH, stdin);
        if(DEBUG) {
            printf("input: %s\nExit: %s\n", input, EXIT);
        }
        tokenize(split, input);
        if(DEBUG) {
            printf("split_input[0]: %s\n", split[0]);
        }
        int exit_comp = strcmp(input, EXIT);
        if(DEBUG) {
            printf("Exit comp: %d\n", exit_comp);
        }
        free(input);
        if(exit_comp == 0) {
            exit(0);
        }
        if(DEBUG) {
            printf("split[0]: %s\n", split[0]);
        }
        execvp(split[0], split);
    }
    
    return 0;
}