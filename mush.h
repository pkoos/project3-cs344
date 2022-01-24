#ifndef __mush__h
#define __mush__h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdarg.h>

#define DEBUG true

#define MAX_LENGTH 2048
#define WORD_COUNT 128
const char * EXIT = "exit";
const char * DELIM = " \t\n";
const char * prompt = "MUSH >>";

char * input;
char * split[WORD_COUNT];
pid_t fork_pid;
char d_val[MAX_LENGTH];

void tokenize(char *dest[WORD_COUNT], char * src) {
    char * tok = strtok(src, DELIM);
    int i = 0;
    while(tok != NULL) {
        dest[i] = (char *) malloc(sizeof(char) * strlen(tok));

        strcpy(dest[i++], tok);
        tok = strtok(NULL, DELIM);
    }
    dest[i] = NULL;
}

void printDebug(int argLen, ...) {
    if(DEBUG) {
        int i;
        va_list args;
        va_start(args, argLen);
        char *label[argLen];
        char *value[argLen];
        printf("DEBUG\n");
        for(i = 0;i<argLen; i++) { // first values are labels
            label[i] = va_arg(args, char*);
        }
        for(i = 0;i < argLen;i++) { // next values are values
            value[i] = va_arg(args, char*);
        }
        for(i = 0;i < argLen;i++) { // print out labels and values
            printf("%d: %s: %s\n", i, label[i], value[i]);
        }
        va_end(args);
    }
}

#endif