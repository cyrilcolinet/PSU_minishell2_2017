/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** env_manager functions
*/

# include "minishell.h"

char **convert_list_to_array(env_t *envlist)
{
	char **env = NULL;
	int count = 0, i = 0;
	char *data = NULL;
	env_t *tmp = envlist;

	while (tmp->next != NULL)
		tmp = tmp->next, count++;
	if (count == 0)
		return (NULL);
	env = malloc(sizeof(*env) * (count + 1));
	tmp = envlist;
	while (tmp->next) {
		data = my_strjoin_clear(my_strjoin_char(tmp->next->variable, \
		'='), tmp->next->content, 0);
		env[i++] = my_strdup(data);
		free(data);
		tmp = tmp->next;
	}
	env[count] = NULL;
	return (env);
}

env_t *new_environment_entry(char *var, char *content, env_t *env)
{
	env = malloc(sizeof(env_t));

	if (env == NULL || var == NULL || content == NULL)
		return (NULL);

	env->variable = var;
	env->content = content;
	env->next = NULL;
	return (env);
}

void print_environment(shell_t *shell)
{
	env_t *tmp = shell->env;

	while (tmp->next != NULL) {
		my_putstr(tmp->next->variable);
		my_putstr("=");
		my_putstr(tmp->next->content);
		my_putstr("\n");
		tmp = tmp->next;
	}
}

void fill_environment(env_t *env_s, char **env)
{
	env_t *tmp = env_s;
	char **arr = NULL;
	char *var = NULL;
	char *content = NULL;

	while (*env != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;

		arr = my_strtok(*env, '=');
		var = my_strdup(arr[0]);
		content = join_next_values(arr);
		tmp->next = new_environment_entry(var, content, tmp->next);
		my_freetab(arr);

		if (tmp->next == NULL)
			return;

		env++;
	}
}
