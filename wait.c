#include "main.h"

/**
 * main - Demonstrates the use of wait system call.
 *
 * Return: Always 0.
 */

int main(void)
{
    pid_t child_pid;
    int status;

    printf("Before fork\n");

    // Create a new process (child)
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        // Code for the child process
        printf("This is the child process (PID: %d)\n", getpid());
        sleep(2); // Simulating some work in the child process
        exit(42); // Child exits with status 42
    }
    else
    {
        // Code for the parent process
        printf("This is the parent process (PID: %d) of child %d\n", getpid(), child_pid);

        // Wait for the child to terminate
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }

    // This part of the code is executed only by the parent
    printf("After fork, both processes continue running from here\n");

    return 0;
}
