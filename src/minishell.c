/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

void minishell(shell_t *shell)
{
	char *stdin = NULL;
	int result = 0;

	while (result != -1) {
		signal(SIGINT, signal_handler);
		display_prompt();
		redirect_stdin(&stdin);
		if (stdin == NULL) {
			shell->status = shell->cmd_ret;
			break;
		}
		result = command_executor(stdin, shell);
		env_check_home_change(shell);
		free(stdin);
	}
}

int main_minishell(int ac, char **av, char **env)
{
	shell_t *shell = configure(env);
	int status = 0;
	(void)ac, (void)av;

	if (shell == NULL)
		return (84);

	minishell(shell);
	status = shell->status;
	free_all(shell);
	return (status);
}
