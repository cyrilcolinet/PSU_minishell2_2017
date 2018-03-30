/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line functions
*/

#include "minishell.h"

static int get_character(int fdesc, char *str)
{
	static int off = 0;
	static char buff[READ_SIZE];
	static int reader = READ_SIZE;

	if (off >= reader || off == 0) {
		off = 0;
		reader = read(fdesc, buff, READ_SIZE);
		if (reader == 0)
			return (0);
	}
	if (reader == 0) {
		*str = 0;
		off = -1;
	} else {
		if (buff[off] == '\n' || buff[off] == '\0')
			*str = 0, off++;
		else
			*str = buff[off++];
	}
	return (reader);
}

static char *return_freed(char *ptr, char *ret)
{
	if (ptr != NULL)
		free(ptr);

	return (ret);
}

char *get_next_line(int fdesc)
{
	char *line = my_strconfigure(READ_SIZE);
	int i = 0;
	int reader = get_character(fdesc, &line[i]);

	if (reader == 0 || line == NULL || fdesc < 0)
		return (return_freed(line, NULL));

	while (line[i]) {
		if (i % READ_SIZE == 0) {
			line = realloc_char(line, i + READ_SIZE + 1);

			if (line == NULL)
				return (return_freed(line, NULL));
		}

		reader = get_character(fdesc, &line[++i]);
	}

	line[++i] = 0;
	return (line);
}
