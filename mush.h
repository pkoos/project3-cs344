#ifndef __mush__h
#define __mush__h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#define DEBUG true

#define MAX_LENGTH 2048
#define WORD_COUNT 128
const char * EXIT = "exit";
const char * DELIM = " \t\n";

char * input;
char * split[WORD_COUNT];
const char * prompt = "MUSH >>";

void tokenize(char **, char *);

#endif