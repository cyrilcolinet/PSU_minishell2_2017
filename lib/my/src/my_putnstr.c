/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** my_putnstr function
*/

# include "my.h"

void my_putnstr(char *str, int n)
{
	int i = -1;

	if (n < 0) {
		while (str[++i] && i < my_strlen(str) + n)
			my_putchar(str[i]);
	} else {
		while (str[++i] && i < n)
			my_putchar(str[i]);
	}
}
