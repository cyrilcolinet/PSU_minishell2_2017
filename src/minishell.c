/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

char **split_commands_input(char *stdin)
{
	char **ret = my_strtok(stdin, ';');

	if (ret == NULL) {
		ret = malloc(sizeof(*ret));
		ret[0] = NULL;
		return (ret);
	}

	return (ret);
}

void minishell(shell_t *shell)
{
	char *stdin = NULL;
	int result = 0;
	char **splited_input = NULL;

	while (result != -1) {
		signal(SIGINT, signal_handler);
		display_prompt();
		redirect_stdin(&stdin);
		if (stdin == NULL) {
			shell->status = shell->cmd_ret;
			break;
		}
		splited_input = split_commands_input(stdin);
		result = command_executor(splited_input, false, shell);
		env_check_home_change(shell);
		my_freetab(splited_input);
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
