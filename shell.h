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
char *trim(char *str);
void Tokenize(char *token, char **env);
void exec_com(char *comd, char **env);
void free_token(char **tok, int index);
void free_paths(char **paths, int number_paths);
char *get_path(char *comd_name);
void child_make(char **tokens, char **env);

#endif /* SHELL_H */
