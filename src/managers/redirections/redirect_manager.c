/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** redirections manager functions
*/

# include "minishell.h"

int perform_redirections(char *cmd, shell_t *shell)
{
	int len = my_countwords(cmd, '>');
	char **arr = NULL;
	char *tmp = NULL;
	int fd = -1;

	if (len == 2) {
		arr = my_strtok(cmd, '>');
		tmp = my_strdup(arr[1]);
		free(arr[1]);
		arr[1] = NULL;
		fd = open(tmp, O_CREAT | O_RDWR, 0664);
		dup2(fd, 1);
		command_executor(arr, false, shell);
		close(fd);
		my_freetab(arr);
		return (1);
	}

	return (0);
}
