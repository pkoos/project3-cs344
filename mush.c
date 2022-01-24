#include "mush.h"

int main(void) {
    while(1) {
        printf("%s", prompt);
        
        input = (char *) malloc(MAX_LENGTH);
        fgets(input, MAX_LENGTH, stdin);
        // printDebug(2, "Input", "Exit", input, EXIT);
        
        tokenize(split, input);

        // printDebug(1, "split_input[0]", split[0]);

        int exit_comp = strcmp(input, EXIT);

        // sprintf(d_val, "%d", exit_comp);
        // printDebug(1, "Exit comp", d_val);
        free(input);
        if(exit_comp == 0) {
            exit(0);
        }
        // printDebug(1, "split[0]", split[0]);
        fork_pid = fork();

        sprintf(d_val, "%d", fork_pid);
        printDebug(1, "fork_pid", d_val);
        if(fork_pid == 0) {
            if(DEBUG) {
                printf("Child process here\n");
            }
            int exec_id = execvp(split[0], split);
            if (exec_id == -1) {
                perror("Error with ExecVP\n");
                exit(1);
            }

        }
        else if(fork_pid == -1) {
            perror("Error with forking\n");
        }
        else {
            if(DEBUG) {
                printf("Parent waiting\n");
            }    
            wait(NULL);
        }
        
    }
    
    return 0;
}