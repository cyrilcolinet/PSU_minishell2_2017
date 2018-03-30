/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** struct_utils functions
*/

# include "minishell.h"

void free_all(shell_t *shell)
{
	env_t *tmp = NULL;

	while (shell->env != NULL) {
		tmp = shell->env;
		shell->env = shell->env->next;
		free(tmp->variable);
		free(tmp->content);
		free(tmp);
	}

	free(env_home);
	free(shell->path);
	free(shell);
}

env_t *configure_env(char **env)
{
	env_t *env_s = malloc(sizeof(env_t));

	if (env_s == NULL)
		return (NULL);

	env_s->variable = NULL;
	env_s->content = NULL;
	env_s->next = NULL;
	fill_environment(env_s, env);
	return (env_s);
}

shell_t *configure(char **env)
{
	shell_t *shell = NULL;

	if (*env == NULL)
		return (NULL);

	shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (NULL);

	shell->status = 0;
	shell->env = configure_env(env);

	if (shell->env == NULL)
		return (NULL);

	shell->path = my_strdup(env_get_variable("PATH", shell));
	env_home = my_strdup(env_get_variable("HOME", shell));

	return (shell);
}
