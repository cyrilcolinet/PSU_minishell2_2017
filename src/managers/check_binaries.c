/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** check_binaries functions
*/

# include "minishell.h"

bool can_be_executed(char *path, stat_t i, char **arg, shell_t *shell)
{
	if (i.st_mode & S_IFREG) {
		if (i.st_mode & S_IXUSR) {
			return (run_command(path, arg, shell));
		} else {
			my_putstr(arg[0]);
			my_putstr(" : Permission denied.\n");
			shell->cmd_ret = 1;
		}

		free(path);
		return (true);
	}

	free(path);
	return (false);
}

bool bins(char **arg, shell_t *shell)
{
	int i = -1;
	char **path = my_strtok(shell->path, ':');
	char *bin_path = NULL;
	stat_t info;

	while (path && path[++i]) {
		if (my_strstartswith(arg[0], path[i])) {
			bin_path = my_strdup(arg[0]);
		} else {
			bin_path = path_join(path[i], arg[0]);
		}
		if (lstat(bin_path, &info) < 0) {
			free(bin_path);
		} else {
			my_freetab(path);
			return (can_be_executed(bin_path, info, arg, shell));
		}
	}
	my_freetab(path);
	return (false);
}
