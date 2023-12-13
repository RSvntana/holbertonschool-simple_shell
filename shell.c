#include "main.h"

/**
 *
 *
 *
 *
 */

#define MAX_COMMAND_LENGTH 100

void display_prompt() {
    printf("simple_shell$ ");
    fflush(stdout);
}

void execute_command(const char *command) {
    pid_t pid = fork();

    if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
        execlp(command, command, (char *)NULL);

        perror("exec");
        exit(EXIT_FAILURE);
	}
	else
	{
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
		{
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
		   	printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
	{
        display_prompt();

        if (fgets(command, sizeof(command), stdin) == NULL)
		{
		   	printf("\n");
		   	break;
        }

        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}
        execute_command(command);
    }

    printf("Exiting the simple_shell\n");
    return EXIT_SUCCESS;
}
