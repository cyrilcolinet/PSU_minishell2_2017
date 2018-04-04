/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** exit_command functions
*/

# include "minishell.h"

int exit_command(char *stdin, char **arg, shell_t *shell)
{
	int res = -1;
	(void)stdin;

	if (arg[1] == NULL)
		shell->status = shell->cmd_ret;
	else
		shell->status = my_atoi(arg[1]);

	return (res);
}
