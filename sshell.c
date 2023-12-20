#include "shell.h"
/**
 * main - Entry point for the simple shell program
 * @ac: The argument count (unused)
 * @av: The argument vector (unused)
 * @env: The environment variables
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
char *input = NULL;
size_t size = 0;
ssize_t read;
char *trimmed;

while (1)
{
if (isatty(0))
write(STDOUT_FILENO, "😀  ", 5);
(void)ac; /* Suppress unused parameter warning */
(void)av; /* Suppress unused parameter warning */
read = getline(&input, &size, stdin); /* Read user input */
if (read == -1)
break;
/* Trim leading and trailing whitespace */
trimmed = trim(input);
if (strcmp(trimmed, "exit") == 0 || strcmp(trimmed, "quit") == 0)
{
printf("Exiting... BYE BYE\n");
break;
}
if (trimmed[0] == '\0')
continue;
Tokenize(trimmed, env); /* Execute the command entered by the user */
free(input); /* Free allocated memory */
}
return (0);	 /* Exit the shell */
}

/**
 * trim - Remove leading and trailing whitespace from a string
 * @str: The string to trim
 * Return: A pointer to the trimmed string
 */
char *trim(char *str)
{
char *end = str + strlen(str) - 1; /*Pointer to the end of the string */
/* Remove leading whitespace */
while (isspace((unsigned char)(*str)))
str++;
/* Remove trailing whitespace */
while (end > str && isspace((unsigned char)*end))
end--;
/* Null-terminate the trimmed string */
*(end + 1) = '\0';
return (str); /* Return the trimmed string */
}

/**
 * free_token - Frees memory allocated for token array and token strings
 * @tok: The token array to be freed
 * @index: The number of tokens in the array
 */
void free_token(char **tok, int index)
{
int i;

for (i = 0; i < index; i++)
{
free(tok[i]);
}
free(tok);
}

/**
 * free_paths - Frees memory allocated for the paths array
 * @paths: The paths array to be freed
 * @number_paths: The number of paths in the array
 */
void free_paths(char **paths, int number_paths)
{
int i;

for (i = 0; i < number_paths; i++)
{
free(paths[i]);
}
free(paths);
}
