/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** command_manager functions
*/

# include "minishell.h"

void signal_ret_checher(pid_t pid, shell_t *shell)
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

bool run_command(char *bin_path, char **arg, shell_t *shell)
{
	pid_t pid = fork();
	char **env = NULL;

	signal(SIGINT, proc_signal_handler);
	if (pid == 0) {
		if ((env = convert_list_to_array(shell->env)) != NULL)
			execve(bin_path, arg, env);
		my_freetab(env);
	} else if (pid < 0) {
		free(bin_path);
		return (false);
	}
	signal_ret_checher(pid, shell);
	if (bin_path)
		free(bin_path);
	return (true);
}

int builtin(char *stdin, char **arg, shell_t *shell)
{
	int res = 0;

	if (my_strequ(arg[0], "exit"))
		res = exit_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "cd"))
		res = cd_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "env"))
		res = env_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "setenv"))
		res = setenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "unsetenv"))
		res = unsetenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "printenv"))
		res = printenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "echo"))
		res = echo_command(stdin, arg, shell);

	return (res);
}

int command_exists(int *res, char **arg, char *stdin, shell_t *shell)
{
	stat_t info;

	if ((*res = builtin(stdin, arg, shell)) == 1 || bins(arg, shell)) {
		my_freetab(arg);
		return (*res);
	} else if (*res < 0) {
		my_freetab(arg);
		return (-1);
	}

	if (lstat(arg[0], &info) != -1) {
		if (info.st_mode & S_IXUSR && !S_ISDIR(info.st_mode)) {
			run_command(my_strdup(arg[0]), arg, shell);
			my_freetab(arg);
			return (1);
		}
	}

	return (-2);
}

int command_executor(char **commands, shell_t *shell)
{
	int res = 1;
	char **arg = NULL;
	int cmd = 0;

	for (cmd = 0; commands[cmd]; cmd++) {
		arg = my_strtok(commands[cmd], ' ');
		if (arg[0] == NULL) {
			my_freetab(arg);
			return (1);
		}

		if (command_exists(&res, arg, commands[cmd], shell) == -2) {
			my_putstr(arg[0]);
			my_putstr(": Command not found.\n");
			shell->cmd_ret = 1;
			my_freetab(arg);
		}
	}

	return (res);
}
