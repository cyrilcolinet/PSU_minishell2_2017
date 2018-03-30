/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** redirect_manager functions
*/

# include "minishell.h"

void redirect_stdin(char **stdin)
{
	*stdin = get_next_line(0);

	if (*stdin == NULL)
		return;

	*stdin = replace_char(*stdin, '\t', ' ');
}
