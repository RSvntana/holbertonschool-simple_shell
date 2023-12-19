#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

int main(int argc, char **argv);
char *remove_whitespace(char *str);
void free_token_array(char **tokens, int num_tokens);
void free_paths_array(char **paths, int num_paths);
char *get_full_path(char *command_name);
void tokenize_and_execute(char *command_string, char **environment);
void create_child_process_and_execute(char **tokens, char **environment);
void free_tokens_array(char **tokens);

#endif /*SHELL_H*/
