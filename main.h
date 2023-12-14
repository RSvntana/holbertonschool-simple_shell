
#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt();
void execute_command(const char *command);
int main(void);

#endif
