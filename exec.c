#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Displays the shell prompt.
 */
int display_prompt(void)
{
    printf("simple_shell$ ");
    fflush(stdout);
}

/**
 * execute_command - Forks a child process to execute the given command.
 * @command: The command to be executed.
 */
int execute_command(const char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        char *args[] = {(char *)command, NULL};
        char *envp[] = {NULL}; // You may add your environment variables here

        if (execve(command, args, envp) == -1)
        {
            // If exec fails, print an error message
            perror("exec");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            // Child exited normally
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            // Child process terminated by a signal
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }
}

/**
 * main - Entry point for the simple shell program.
 * Return: EXIT_SUCCESS on successful execution, otherwise EXIT_FAILURE.
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

        // Remove the newline character
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n')
        {
            command[len - 1] = '\0';
        }

        // Execute the command
        execute_command(command);
    }

    printf("Exiting the simple_shell\n");
    return EXIT_SUCCESS;
}
