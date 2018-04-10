cmake_minimum_required(VERSION 3.10)
project(PSU_minishell2_2017 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib/my/include)

add_executable(PSU_minishell2_2017
        include/minishell.h
        include/my.h
        include/structs.h
        lib/my/include/my.h
        lib/my/src/my_atoi.c
        lib/my/src/my_countwords.c
        lib/my/src/my_freetab.c
        lib/my/src/my_put_nbr.c
        lib/my/src/my_putchar.c
        lib/my/src/my_putnstr.c
        lib/my/src/my_putstr.c
        lib/my/src/my_str_isalpha.c
        lib/my/src/my_str_isnum.c
        lib/my/src/my_strcat.c
        lib/my/src/my_strcmp.c
        lib/my/src/my_strconfigure.c
        lib/my/src/my_strcpy.c
        lib/my/src/my_strdup.c
        lib/my/src/my_strendswith.c
        lib/my/src/my_strequ.c
        lib/my/src/my_strjoin.c
        lib/my/src/my_strjoin_char.c
        lib/my/src/my_strjoin_clear.c
        lib/my/src/my_strlen.c
        lib/my/src/my_strstartswith.c
        lib/my/src/my_strtok.c
        src/actions/environment_actions.c
        src/builtin/cd_command.c
        src/builtin/echo_command.c
        src/builtin/env_command.c
        src/builtin/exit_command.c
        src/builtin/printenv_command.c
        src/builtin/setenv_command.c
        src/builtin/unsetenv_command.c
        src/handlers/signal_handler.c
        src/managers/check_binaries.c
        src/managers/command_manager.c
        src/managers/env_manager.c
        src/managers/prompt_manager.c
        src/managers/redirect_manager.c
        src/utils/get_next_line.c
        src/utils/parsing_utils.c
        src/utils/struct_utils.c
        src/main.c
        src/minishell.c
        tests/minishell_tests.c)
