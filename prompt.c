#include "main.h"

/**
 * display_prompt - displays the shells prompt
 * Return - Success (0)
*/

int display_prompt()
{
char *input = NULL;
size_t input_size = 0;

while (1)
{
printf("Simple SHell $ ");/*shell dsiplay*/

if (getline(&input, &input_size, stdin) == -1)
{
    printf("Error readinf input, Exit Shell.\n");
    break;/*handles error or end*/
}

input[strcspn(input, "\n")] = '\0';/*remove newline char  from input*/

if (strcmp(input, "exit") == 0)
{
printf("EXIT SHELL.\n");
break;/*Checks if user wishes to exit*/
}
printf("ENTERED: %s\n", input);/*this echoes the input*/
}
free(input);/*frees dynam alloc memory*/
return (0);
}
