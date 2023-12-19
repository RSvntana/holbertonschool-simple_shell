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

int main(int ac, char **av, char **env);
char *cut(char *str);
void Tokenize(char *tok, char **env);
void exec_comd(char *command, char **env);
void free_tok(char **tok, int index);
void free_paths(char **paths, int n_paths);
char *get_path(char *comd_name);
void child_make(char **tokens, char **env);

#endif 
