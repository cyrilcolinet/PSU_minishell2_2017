/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** signal_handler functions
*/

# include "minishell.h"

void signal_handler(int signo)
{
	if (signo == SIGINT) {
		my_putstr("\n");
		display_prompt();
		signal(SIGINT, signal_handler);
	}
}

void proc_signal_handler(int signo)
{
	if (signo == SIGINT) {
		my_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}
