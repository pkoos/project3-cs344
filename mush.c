#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 2048
const char * EXIT = "exit";
char * input;
char * prompt = "MUSH >>";

int main(void) {
    while(1) {
        printf("%s", prompt);
        input = (char *) malloc(MAX_LENGTH);
        fgets(input, MAX_LENGTH, stdin);

        printf("%s\n", input);
        printf("EXIT: %s\n", EXIT);
        int exit_comp = strcmp(input, EXIT);
        printf("Exit comp: %d\n", exit_comp);
        free(input);
        if(exit_comp == 0) {
            exit(0);
        }
    }
    
    return 0;
}