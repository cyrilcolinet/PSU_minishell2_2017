/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** exit_command functions
*/

# include "minishell.h"

int exit_command(char *stdin, char **arg, shell_t *shell)
{
	(void)stdin;

	if (arg[1]) {
		if (arg[2]) {
			my_putstr("exit: Expression Syntax.\n");
			return (1);
		}

		shell->status = my_atoi(arg[1]);
		return (-1);
	}

	shell->status = shell->cmd_ret;
	return (-1);
}
