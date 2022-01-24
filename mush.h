#ifndef __mush__h
#define __mush__h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdbool.h>

// Numeric constants
#define ERR_LEN 256
#define MAX_LEN 2048
#define WORD_COUNT 128

// String constants
#define PROMPT "MUSH >>"
#define EXIT "exit"
#define CHDIR "cd"

void tokenize(char **, char *);
bool isEOF();
void processInput(char **);
void forkAndExec(char **);
void changeDirectory(char *);

#endif
