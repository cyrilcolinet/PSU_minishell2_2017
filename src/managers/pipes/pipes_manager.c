/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** pipes_manager
*/

# include "minishell.h"

void get_piped_commands(char *cmd, shell_t *shell)
{
	if (shell->pipes->cmds != NULL)
		my_freetab(shell->pipes->cmds);

	shell->pipes->cmd_count = my_countwords(cmd, '|') - 1;

	if (shell->pipes->cmd_count <= 0) {
		shell->pipes->cmds = NULL;
		return;
	}

	shell->pipes->cmds = my_strtok(cmd, '|');
}

int perform_pipes(char *cmd, char **arg, shell_t *shell)
{
	int res = 0;

	get_piped_commands(cmd, shell);
	if (shell->pipes->cmd_count > 0) {
		res = 1;
		command_executor(shell->pipes->cmds, true, shell);
	}

	if (res)
		my_freetab(arg);
	return (res);
}
