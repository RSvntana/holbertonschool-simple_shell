#include "shell.h"

char *get_full_path(char *command_name)
{
    char *path_prefix = "/bin/";
    char *full_path;

    if (access(command_name, X_OK) == 0)
    {
        return strdup(command_name);
    }

    full_path = malloc(strlen(path_prefix) + strlen(command_name) + 1);
    if (full_path == NULL)
    {
        perror("malloc");
        return NULL;
    }
    sprintf(full_path, "%s%s", path_prefix, command_name);

    if (access(full_path, X_OK) != 0)
    {
        perror("Command not found");
        free(full_path);
        return NULL;
    }

    return full_path;
}

void tokenize_and_execute(char *command_string, char **environment)
{
    char *token = NULL;
    char **tokens = NULL;
    int token_count = 0;
    char *full_path;

    token = strtok(command_string, " \n");
    if (token == NULL)
    {
        return;
    }

    while (token != NULL)
    {
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        if (tokens == NULL)
        {
            perror("realloc");
            return;
        }
        tokens[token_count] = strdup(token);
        if (tokens[token_count] == NULL)
        {
            perror("strdup");
            return;
        }
        token_count++;
        token = strtok(NULL, " \n");
    }
    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    if (tokens == NULL)
    {
        perror("realloc");
        return;
    }
    tokens[token_count] = NULL;

    full_path = get_full_path(tokens[0]);
    if (full_path == NULL)
    {
        free_tokens_array(tokens);
        return;
    }

    free(tokens[0]);
    tokens[0] = full_path;

    create_child_process_and_execute(tokens, environment);

    free_tokens_array(tokens);
}

void create_child_process_and_execute(char **tokens, char **environment)
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        execve(tokens[0], tokens, environment);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

void free_tokens_array(char **tokens)
{
    int i;
    if (tokens == NULL)
    {
        return;
    }
    for (i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}
