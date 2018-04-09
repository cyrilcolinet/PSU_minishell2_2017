/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** check if string is alpha
*/

# include <stdbool.h>
# include "my.h"

bool my_str_isalpha(char *s)
{
	bool alpha = true;

	if (s == NULL)
		return (false);

	while (*s) {
		if (!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')
		|| (*s >= '0' && *s <= '9')))
			alpha = false;
		s++;
	}

	return (alpha);
}
