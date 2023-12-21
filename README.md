Simple Shell
Overview
This repository contains the source code for a simple UNIX command line interpreter (shell) developed as a project for Holberton School. The shell, named simple_shell, is designed to meet specific requirements and progressively implements additional features in different versions.

Project Requirements
Compilation
All files are compiled with gcc 4.8.4 using the flags: -Wall -Werror -Wextra -pedantic.

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
Betty Coding Style
All files are written in C and follow the Betty coding style.

Allowed Functions and System Calls
The shell makes use of the following allowed functions and system calls:

All functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
Project Structure
The project is organized into different versions, each implementing additional features. The current versions and their features are as follows:

Simple Shell 0.1
Handles command lines with arguments.
Simple Shell 0.2
Handles the PATH.
Fork is not called if the command doesn't exist.
Simple Shell 0.3
Implements the exit built-in, which exits the shell.
Usage: exit. No arguments are handled for the built-in exit.
Simple Shell 0.4
Implements the env built-in, which prints the current environment.
Usage
To use the shell in interactive mode:

bash
Copy code
$ ./simple_shell
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
To use the shell in non-interactive mode:

bash
Copy code
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
Simple Shell 0.4 Example
bash
Copy code
$ ./simple_shell
$ env
USER=username
HOME=/home/username
SHELL=/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
$ exit
$
Building on Simple Shell 0.4
The shell is currently under development and will continue to incorporate additional features based on the project requirements.

Authors
Pedro Laguna
Robert Santana
