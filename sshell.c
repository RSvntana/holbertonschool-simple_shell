#include "shell.h"
/**
 * main - Entry point for the simple shell program
 * @av: The argument vector
 * @ac: The argument count
 * @env: The environment variables
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char *input = NULL;
	size_t size = 0;
	ssize_t read;
	char *trimmed;

	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, "😀  ", 5);
		read = getline(&input, &size, stdin); /* Read input */

		if (read == -1)
			break;

		/* Trim leading & trailing Whitespace */
		trimmed = trim(input);

		if (strcmp(trimmed, "exit") == 0 || strcmp(trimmed, "quit") == 0)
			exit(0);

		if (trimmed[0] == '\0')
			continue;

		Tokenize(trimmed, env);
	}
	free(input);
	return (0);	 /* Exit */
}

/**
 * trim - trim whitespace from a string
 * @str: string to trim
 * Return: A pointer to the trimmed string
 */
char *trim(char *str)
{
	char *end = str + strlen(str) - 1; /*Pointer to the end of the string */


	/* trim leading whitespace */
	while (isspace((unsigned char)(*str)))
		str++;

	/* trim trailing whitespace */
	while (end > str && isspace((unsigned char)*end))
		end--;


	/* Null terminate the trimmed string */
	*(end + 1) = '\0';
	return (str); /* Return trimmed string */
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
