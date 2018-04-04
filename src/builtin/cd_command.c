/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** cd_command functions
*/

# include "minishell.h"

void change_dir(char *path, shell_t *shell)
{
	char buffer[4097];
	char *cwd = getcwd(buffer, 4096);

	if (!chdir(path)) {
		env_set_variable("OLDPWD", cwd, shell);
	} else {
		my_putstr("cd: ");
		if (access(path, F_OK) == -1) {
			my_putstr("no such file or directory: ");
		} else if (access(path, R_OK) == -1) {
			my_putstr("permission denied: ");
		} else {
			my_putstr("not a directory: ");
		}
		my_putstr(path);
		my_putstr("\n");
		shell->cmd_ret = 1;
	}
}

int cd_command(char *stdin, char **arg, shell_t *shell)
{
	if (arg[1] != NULL && arg[2] != NULL) {
		my_putstr("cd: too many arguuments\n");
		shell->cmd_ret = 1;
	} else {
		if (arg[1] == NULL || my_strequ(arg[1], "~")) {
			change_dir(env_home, shell);
		} else if (my_strequ(arg[1], "-")) {
			change_dir(env_get_variable("OLDPWD", shell), shell);
		} else {
			change_dir(arg[1], shell);
		}
	}
	return (1);
}
