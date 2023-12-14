#include "main.h"

/**
 * main - Demonstrates the use of fork system call.
 *
 * Return: Always 0.
 */

int main(void)
{
    pid_t child_pid;

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
    }
    else
    {
        // Code for the parent process
        printf("This is the parent process (PID: %d) of child %d\n", getpid(), child_pid);
    }

    // This part of the code is executed by both parent and child
    printf("After fork, both processes continue running from here\n");

    return 0;
}
