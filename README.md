README
# 0x16.C -Simple Shell
# `C` `Group project` `Syscall`
## Learning Objectives
At the end of this project, my team mate and I aare expected to be able to explain to anyone, **without the help
of google:**
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language(the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF`/"end-of-file"?

## PROJECT DETAILS
-----
Welcome, to this `simple shell` project!!. This shell can be compiled and launched from the command line
### HOW TO COMPILE
----
The shell should be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
### SYNTAX
-----
When using this shell, the syntax for running any command is the same with the syntax for running commands on the
bash shell.

It is important that we let you know that this shell doesn't incorporate all the functions and possible commands
the bash shell has.

### COMMANDS
-----
This shell supports a few builtin commands:
`cd` - change directory
`env` - list the current environment variable
`exit` - exits the shell

The other commands this shell supports are the files contained in the bin file

### AUTHORS
---
Ebenezer Emmanuel Emonueje (https://github.com/Emonueje)
-
George Akonjom (https://github.com/georgeAkonjom)
-
