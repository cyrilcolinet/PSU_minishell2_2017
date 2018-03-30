/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** Main function
*/

# include "minishell.h"

int main(int ac, char **av, char **env)
{
	int res = 84;

	if (*env == NULL)
		return (res);

	res = main_minishell(ac, av, env);

	return (res);
}
