/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** signal_handler functions
*/

# include "minishell.h"

void print_signal(char *sig)
{
	if (my_strequ(sig, "Floating point exception")) {
		my_putstr("Floating exception");
		return;
	}

	my_putstr(sig);
}

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

void signal_ret_checker(pid_t pid, shell_t *shell)
{
	int wait_ret = -1;
	int termsig = 0;
	int status = 0;

	wait_ret = waitpid(pid, &status, 0);

	if (WIFSIGNALED(status)) {
		termsig = WTERMSIG(status);

		if (termsig != 0 && termsig != SIGINT) {
			print_signal(strsignal(termsig));
			if (WCOREDUMP(status))
				my_putstr(" (core dumped)");
			my_putstr("\n");
			shell->cmd_ret = termsig + 128;
		}
	}

	kill(wait_ret, SIGKILL);
}
