# Mini Shell - to the 42sh and beyond...

[![Build Status](https://travis-ci.org/mrlizzard/PSU_minishell1_2017.svg?branch=master)](https://travis-ci.org/mrlizzard/PSU_minishell1_2017)
[![codecov](https://codecov.io/gh/mrlizzard/PSU_minishell1_2017/branch/master/graph/badge.svg?token=SKCL9EDKjB)](https://codecov.io/gh/mrlizzard/PSU_minishell1_2017)

- **Binary name:** mysh
- **Repository name:** PSU_minishell1_2017
- **Repository rigths:** ramassage-tek
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

You have to program a **UNIX command interpreter**.

The interpreter is expected to display a prompt ($>, for example) and then wait for you to write a command line, which
must be validated by a newline.
The prompt must be displayed again only after the command execution.

Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).

You must implement the following builtins: **cd, setenv, unsetenv, env, exit**.

> :bulb: The reference shell is **tcsh**

> :bulb: Read man pages

## Authorized functions

- malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, fstat, open, close, getline
- read, write, execve, isatty, wait, waitpid
- wait3, wait4, signal, kill, getpid, strerror, perror, strsignal
