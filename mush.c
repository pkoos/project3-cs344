#include "mush.h"

void tokenize(char **dest, char * src) {
    char delim[4] = " \t\n";
    char * tok = strtok(src, delim);
    int i = 0;
    while(tok != NULL) {
        dest[i] = (char *) malloc(sizeof(char) * strlen(tok));

        strcpy(dest[i++], tok);
        tok = strtok(NULL, delim);
    }
    dest[i] = NULL;
}

void processInput(char * dest[128]) {
    char *input = (char *) malloc(MAX_LEN);
    fgets(input, MAX_LEN, stdin);
    tokenize(dest, input);
    free(input);
}

void forkAndExec(char ** args) {
    pid_t fork_pid;
    fork_pid = fork();

    if(fork_pid == 0) {
        int exec_id = execvp(args[0], args);
        if (exec_id == -1) {
            char errorString[ERR_LEN];
            sprintf(errorString, "[%s] is not a valid command!", args[0]);
            perror(errorString);
            exit(1);
        }
    }
    else if(fork_pid == -1) {
        perror("Error with forking");
    }
    else {
        wait(NULL);
    }
}

void changeDirectory(char * newDir) {
    char path[MAX_LEN];
    if(newDir == NULL) {
        strcpy(path, getenv("HOME"));
    } else {
        strcpy(path, newDir);
    }
    int chdir_val = chdir(path);
    if(chdir_val == -1) {
        perror("cd");
    }
}

int main(void) {
    while(1) {
        printf("%s", PROMPT);
        char * arguments[128];
        processInput(arguments);
        char * program = arguments[0];

        if(program == NULL)
            continue;
        if(strcmp(program, EXIT) == 0 || feof(stdin) != 0)
            exit(0);
        else if(strcmp(program, CHDIR) == 0) {
            char * path = arguments[1];
            changeDirectory(path);
        }
        else
            forkAndExec(arguments);
    }
}
