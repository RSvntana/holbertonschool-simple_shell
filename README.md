# Simple Shell

A simple UNIX command line interpreter.

## Overview

The Simple Shell is a minimalist UNIX shell that provides a basic command line interface.

## Project Requirements

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again after each command execution.
- The command lines are simple; no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors and the "end of file" condition (Ctrl+D).

### Additional Concepts

- Command lines with arguments.
- Handling the PATH; fork must not be called if the command doesn’t exist.
- Implementing the exit built-in that exits the shell. Usage: . No arguments are handled for the built-in exit.
- Implementing the env built-in that prints the current environment.

## Compilation

Compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

## Usage

Run the shell:

```bash
./simple_shell
```

## Example

```bash
$ ./simple_shell
:) /bin/ls
file1 file2 file3
:) ls
file1 file2 file3
:) ls -l /tmp
total 20
-rw------- 1 user user    0 Dec  5 12:09 example1
drwx------ 3 root root 4096 Dec  5 12:09 example2
-rw-rw-r-- 1 user user    0 Dec  5 12:09 example3
:) exit
$
```
## Authors

- Robert Santana
- Pedro Laguna
