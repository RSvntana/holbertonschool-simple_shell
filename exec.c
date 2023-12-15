#include "main.h"

/**
 * display_prompt - displays the shells prompt
 * Return: Success (0)
*/

int display_prompt(void)
{
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		printf("Simple Shell $ "); /* Shell display */

		if (getline(&input, &input_size, stdin) == -1)
		{
			printf("Error reading input, Exit Shell.\n");
			break; /* Handles error or end */
		}

		input[strcspn(input, "\n")] = '\0'; /* Remove newline char from input */

		if (strcmp(input, "exit") == 0)
		{
			break; /* Checks if user wishes to exit */
		}

		printf("ENTERED: %s\n", input); /* This echoes the input */
	}

	free(input); /* Free dynamically allocated memory */
	return (0);
}

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	display_prompt();

	char *argv[] = {"/bin/", NULL};/* Example command and arguments */

	if (execve(argv[0], argv, NULL) == -1)
	{
		return (0);
	}
}
