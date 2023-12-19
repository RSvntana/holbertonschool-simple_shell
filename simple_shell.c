#include "shell.h"

/**
 * get_path - Get the full path of a command
 * @com_name: The name of the command
 * Return: A dynamically allocated string containing the full path
 *         NULL if the command is not found
 */
char *get_path(char *comd_name)
{
	char *comd_path = "/bin/";
	char *conpath;

	if (access(comd_name, X_OK) == 0)
	{
		conpath = strdup(comd_name);
		if (conpath == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		return (conpath);
	}
	conpath = malloc(strlen(comd_path) + strlen(comd_name) + 1);
	if (conpath == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	sprintf(conpath, "%s%s", comd_path, comd_name);
	if (access(conpath, X_OK) != 0)
	{
		perror("Command not found");
		free(conpath);
		return (NULL);
	}
	return (conpath);
}


/**
 * Tokenize - Tokenize a command string and execute it
 * @tokI: The command string to tokenize
 * @env: The environment variables
 */
void Tokenize(char *token, char **env)
{
	char *tok = NULL;
	char **tokens = NULL;
	int index = 0;
	char *all_path;

	tok = strtok(token, " \n"); /* Tokenize the command string */
	if (tok == NULL)
		return;

	while (tok != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (index + 1));
		if (tokens == NULL)
		{
			perror("realloc");
			return;
		}
		tokens[index] = strdup(tok); /* Store token in tokens array */
		index++;					   /* Increment the token count */
		tok = strtok(NULL, " \n");	   /* Get next token from command string */
	}
	tokens = realloc(tokens, sizeof(char *) * (index + 1));
	if (tokens == NULL)
	{
		perror("realloc");
		return;
	}
	tokens[index] = NULL; /* Set next element in the array to NULL */
	all_path = get_path(tokens[0]); /* Get the full path of the command */
	if (all_path == NULL)
	{
		free_token(tokens, index);
		return;
	}
	free(tokens[0]);
	tokens[0] = all_path;
	child_make(tokens, env);
	free_token(tokens, index);
}

/**
 * child_make - Create a child process and execute the command
 * @tokens: The tokenized command and arguments
 * @env: The environment variables
 */
void child_make(char **tokens, char **env)
{
	pid_t pid = fork(); /* Create a child process */
	int status;

	if (pid == -1)
	{
		perror("fork"); /* Print error message if fork fails */
		return;
	}
	if (pid == 0)
	{
		execve(tokens[0], tokens, env); /* Execute the command using execve */
		perror("error ");				/* Print an error message if execve fails */
		exit(EXIT_FAILURE);				/* Exit child process with failure status */
	}
	else
	{
		/* Wait specifically for the child process to complete */
		waitpid(pid, &status, 0);
	}
}
