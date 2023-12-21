#Simple Shell

##Overview
This repository contains the source code for a basic UNIX command line interpreter (shell) named simple_shell. The shell was developed as a project for Holberton School, following specific requirements and evolving with each version to incorporate additional features.

##Project Structure
The project is structured into different versions, each introducing new functionality. The current versions and their features are outlined below:

###Simple Shell 0.1

Handles command lines with arguments.

###Simple Shell 0.2

Handles the PATH.
Does not call fork if the command doesn't exist.

###Simple Shell 0.3

Implements the exit built-in for shell termination.
Usage: exit. No arguments are handled for the built-in exit.

###Simple Shell 0.4

Implements the env built-in, which prints the current environment.

##Project Concepts and Understanding

1. Command Execution: Understanding how to execute commands using the execve system call.

2. Process Creation: Utilizing fork to create child processes for command execution.

3. Built-in Functions: Implementing built-in shell functions, such as exit and env.

4. Error Handling: Managing and displaying error messages appropriately.

5. Interactive and Non-Interactive Modes: Handling shell input both interactively and non-interactively.

6. Parsing and Tokenization: Tokenizing user input to understand and execute commands.

7. Environment Variables: Managing and printing environment variables.

##Usage
####To use the shell interactively:

$ ./simple_shell
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

####To use the shell non-interactively:

$ echo "/bin/ls" | ./simple_shell
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./simple_shell
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

##Example (Simple Shell 0.4)

$ ./simple_shell
$ env
USER=username
HOME=/home/username
SHELL=/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
$ exit
$

##Development

The shell is a work in progress and will continue to evolve to meet project requirements and incorporate additional features.

##Authors

Pedro Laguna
Robert Santana
