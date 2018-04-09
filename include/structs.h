/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** structs header file
*/

# ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

struct 	env_t;
struct 	shell_t;

typedef int (*builtin_fct_t[])(char *, char **, struct shell_t *);

typedef enum cmd_t {
	cmdExit,
	cmdCD,
	cmdEnv,
	cmdSetenv,
	cmdUnsetenv,
	cmdPrintenv
}	cmd_t;

typedef struct env_t {
	char 			*variable;
	char 			*content;
	struct env_t 	*next;
} 	env_t;

typedef struct shell_t {
	int 			status;
	char 			*path;
	int 			cmd_ret;
	env_t 			*env;
	builtin_fct_t	cmd;
} 	shell_t;

# endif
