/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** setenv_command functions
*/

# include "minishell.h"

int setenv_command(char *stdin, char **arg, shell_t *shell)
{
	(void)stdin;

	if (arg[1] && arg[2] && arg[3]) {
		my_putstr("setenv: Too many arguments.\n");
		shell->cmd_ret = 1;
	} else if (!arg[1]) {
		print_environment(shell);
	} else {
		if (!my_str_isalpha(arg[1])) {
			my_putstr("setenv: Variable name must contain ");
			my_putstr("alphanumeric characters.\n");
			shell->cmd_ret = 1;
			return (1);
		}
		env_set_variable(arg[1], ((arg[2]) ? arg[2] : ""), shell);
	}
	return (1);
}
