/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** echo_command functions
*/

# include "minishell.h"

int echo_command(char *stdin, char **arg, shell_t *shell)
{
	if (arg[1] && my_strequ(arg[1], "$?")) {
		my_put_nbr(shell->cmd_ret);
		my_putstr("\n");
		return (1);
	}

	return (0);
}
