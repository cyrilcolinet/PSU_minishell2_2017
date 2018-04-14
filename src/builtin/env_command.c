/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** env_command functions
*/

# include "minishell.h"

int env_command(char *stdin, char **arg, shell_t *shell)
{
	(void)stdin;
	(void)arg;

	print_environment(shell);
	return (1);
}
