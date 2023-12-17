
#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 100

typedef struct {
    char command[MAX_INPUT_LENGTH];
    char arguments[MAX_ARGS][MAX_INPUT_LENGTH];
    int num_args;
} ParsedInput;

int main(void);
void display_prompt(void);
void parse_input(const char *input, ParsedInput *parsed);

#endif
