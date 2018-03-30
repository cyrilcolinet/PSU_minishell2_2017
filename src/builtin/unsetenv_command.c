/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** unsetenv_command functions
*/

# include "minishell.h"

int unsetenv_command(char *stdin, char **arg, shell_t *shell)
{
	int i = 0;

	if (!arg[1]) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	}

	while (arg[i] != NULL)
		env_del_variable(arg[i++], shell);

	return (1);
}
