/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** enviroment_actions functions
*/

# include "minishell.h"

void env_del_variable(char *var, shell_t *shell)
{
	env_t *tmp = shell->env;
	env_t *tmp2 = NULL;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, var)) {
			free(tmp->next->variable);
			free(tmp->next->content);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			return;
		}
		tmp = tmp->next;
	}
}

void env_set_variable(char *variable, char *content, shell_t *shell)
{
	env_t *tmp = shell->env;
	char *tmp_cont = NULL, *v = NULL, *c = NULL;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, variable)) {
			tmp_cont = realloc_char(my_strdup(content),
			my_strlen(content));
			free(tmp->next->content);
			tmp->next->content = my_strdup(tmp_cont);
			free(tmp_cont);
			return;
		}
		tmp = tmp->next;
	}

	v = my_strdup(variable), c = my_strdup(content);
	tmp->next = new_environment_entry(v, c, tmp->next);
}

char *env_get_variable(char *variable, shell_t *shell)
{
	env_t *tmp = shell->env;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, variable))
			return (tmp->next->content);
		tmp = tmp->next;
	}

	return ("");
}

void env_check_home_change(shell_t *shell)
{
	char *home = env_get_variable("HOME", shell);

	if (home == NULL || my_strequ(home, env_home))
		return;

	free(env_home);
	env_home = my_strdup(home);
}
