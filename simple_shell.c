#include "shell.h"

int main(int argc, char **argv)
{
    char *user_input = NULL;
    size_t input_length = 0;
    

    (void)argc; // Void unused parameter
    (void)argv; // Void unused parameter

   while (1)
	{
		printf("Simple Shell $ "); /* Shell display */

		if (getline(&user_input, &input_length, stdin) == -1)
		{
			printf("Error reading input, Exit Shell.\n");
			break; /* Handles error or end */
		}

		user_input[strcspn(user_input, "\n")] = '\0'; /* Remove newline char from input */

		if (strcmp(user_input, "exit") == 0)
		{
			printf("Exiting... BYE BYE\n");
			break; /* Checks if user wishes to exit */
		}
	}

	free(user_input); /* Free dynamically allocated memory */
	return (0);
}


char *remove_whitespace(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (isspace((unsigned char)(*start)))
        start++;

    while ((end > start) && isspace((unsigned char)(*end)))
        end--;

    *(end + 1) = '\0';

    return start;
}

void free_token_array(char **tokens, int num_tokens)
{
	int i;
    if (tokens == NULL)
        return;

    for (i = 0; i < num_tokens; i++) // Use i here
    {
        free(tokens[i]);
    }

    free(tokens);
}

void free_paths_array(char **paths, int num_paths)
{
	int i;
    if (paths == NULL)
        return;

    for (i = 0; i < num_paths; i++) // Use i here
    {
        free(paths[i]);
    }

    free(paths);
}
