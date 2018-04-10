/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions (header file)
*/

# ifndef MINISHELL_H
# define MINISHELL_H

# define IS_QUOTE(x)    (x == '\"' || x == '\'')

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct stat stat_t;

# include "my.h"
# include "structs.h"

char 	*env_home;

// minishell.c
void 	minishell(shell_t *shell);
int 	main_minishell(int ac, char **av, char **env);

// utils/struct_utils.c
void 	free_all(shell_t *shell);
env_t 	*configure_env(char **env);
shell_t *configure(char **env);

// utils/parsing_utils.c
char 	*realloc_char(char *ptr, unsigned int size);
char 	*join_next_values(char **array);
char 	*get_next_line(int fdesc);
char 	*path_join(char *str1, char *str2);
char 	*replace_char(char *str, char find, char replace);

// builtin/exit_command.c
int 	exit_command(char *stdin,  char **arg,  shell_t *shell);
int 	cd_command(char *stdin, char **arg, shell_t *shell);
int     env_command(char *stdin, char **arg, shell_t *shell);
int 	setenv_command(char *stdin, char **arg, shell_t *shell);
int 	unsetenv_command(char *stdin, char **arg, shell_t *shell);
int 	printenv_command(char *stdin, char **arg, shell_t *shell);
int 	echo_command(char *stdin, char **arg, shell_t *shell);

// actions/environment_actions.c
void 	env_del_variable(char *var, shell_t *shell);
void 	env_set_variable(char *var, char *content, shell_t *shell);
char 	*env_get_variable(char *var, shell_t *shell);
void 	env_check_home_change(shell_t *shell);

// managers/env_manager.c
char 	**convert_list_to_array(env_t *envlist);
env_t 	*new_environment_entry(char *var, char *content, env_t *env);
void 	print_environment(shell_t *shell);
void 	fill_environment(env_t *env_s, char **env);

// managers/prompt_manager.c
char 	*parse_cwd(char *buffer);
void 	display_prompt(void);

// managers/check_binaries.c
bool 	can_be_executed(char *path, stat_t i, char **arg, shell_t *shell);
bool    bins(char **arg, shell_t *shell);

// managers/command_manager.c
void    signal_ret_checker(pid_t pid, shell_t *shell);
bool 	run_command(char *bin_path, char **arg, shell_t *shell);
int 	builtin(char *stdin, char **arg, shell_t *shell);
int     command_exists(int *res, char **arg, char *stdin, shell_t *s);
int 	command_executor(char **commands, shell_t *shell);

// managers/redirect_manager.c
void 	redirect_stdin(char **stdin);

// handlers/signal_handler.c
void    print_signal(char *signal);
void 	signal_handler(int signo);
void 	proc_signal_handler(int signo);

# endif
