/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** error functions
*/

# include "minishell.h"

void manage_command_error(shell_t *shell)
{
	if (errno) {
		my_putstr(strerror(errno));
		my_putstr("\n");
	}

	shell->cmd_ret = 1;
}
