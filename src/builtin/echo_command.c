/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** echo_command functions
*/

# include "minishell.h"

void echo_output(char **arg, int index)
{
	int len = my_strlen(arg[index]);
	bool starts_with = IS_QUOTE(*arg[index]);
	bool ends_with = IS_QUOTE(arg[index][len - 1]);

	if (starts_with && ends_with) {
		my_putnstr(arg[index] + 1, -1);
	} else if (ends_with) {
		my_putnstr(arg[index], -1);
	} else if (starts_with) {
		my_putstr(arg[index] + 1);
	} else {
		my_putstr(arg[index]);
	}

	if (arg[index + 1])
		my_putstr(" ");
}

int echo_command(char *stdin, char **arg, shell_t *shell)
{
	bool flagged = false;
	int i = 1;
	(void)shell;

	if (!arg[1]) {
		my_putstr("\n");
		return (1);
	} else if (my_strequ(*arg, "-n")) {
		flagged = true;
		i++;
	}

	while (arg[i++]) {
		echo_output(arg, i);
		if (!arg[i + 1] && !flagged)
			my_putstr("\n");
	}

	return (1);
}
