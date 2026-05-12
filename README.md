Simple C Shell
A minimal, interactive Unix shell implemented in C. This project was created to understand the inner workings of process management, system calls, and the lifecycle of a shell (Read-Evaluate-Print Loop).

Features
REPL Loop: Continuously reads input, parses it, and executes commands.

Dynamic Memory: Handles variable-length input commands and arguments using malloc and realloc.

Process Management: Uses fork(), execvp(), and waitpid() to execute system programs.

Built-in Commands: Supports an internal exit command to terminate the session.

Error Handling: Basic error reporting for memory allocation failures and invalid commands.

How it Works
The shell operates in three main stages:

Read: The shell reads a line of input from standard input using getchar().

Parse: The input string is broken down into "tokens" (program name and arguments) using strtok().

Execute:

If the command is a built-in (like exit), it executes immediately.

Otherwise, the shell forks a child process. The child uses execvp() to run the command, while the parent waits for the process to finish.

Prerequisites
To compile and run this project, you need a C compiler (like gcc) and a Unix-like environment (Linux, macOS, or WSL on Windows).

Getting Started
1. Clone the repository
Bash
git clone https://github.com/PanzuHoss/simple-shell.git
cd simple-shell

2. Compile the shell
Use gcc to compile the shell.c file:
gcc shell.c -o shell

3. Run the shell
Bash
./shell

Usage
Once inside the shell, you can run standard Unix commands:

Bash
> ls -l
> pwd
> echo Hello World
> exit

Acknowledgments
This project was built following the tutorial by Danish Prakash.
