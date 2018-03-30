/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell unitary tests
*/

# include "minishell.h"
# include <fcntl.h>
# include <criterion/criterion.h>
# include <criterion/redirect.h>

void redirect_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(minishell, fail_copy_environment, .init = redirect_std)
{
	int res = minishell(1, NULL, NULL, 0);

	cr_assert_eq(res, 84);
	cr_assert_stdout_eq_str("Environment copy failed. Aborded.");
}