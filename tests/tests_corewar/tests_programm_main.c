/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_programm_main
*/

#include "tests_include_header.h"

Test(display_corewar_help, tests_display_corewar_help, .init=redirect, .timeout=1) {
    cr_assert_eq(display_corewar_help((char **)corewar_help), SUC_OUT);
    cr_assert_eq(display_corewar_help(NULL), ERR_OUT);
    cr_assert_stderr_eq_str("Couldn't display the help message\n");
}

Test(check_corewar_args, tests_check_corewar_args, .init=redirect, .timeout=1) {
    cr_assert_eq(check_corewar_args(0, NULL), false);
    int argc1 = 1;
    char *argv1[] = {"-dump", NULL};
    cr_assert_eq(check_corewar_args(argc1, argv1), true);
    int argc2 = 1;
    char *argv2[] = {"-n", NULL};
    cr_assert_eq(check_corewar_args(argc2, argv2), true);
    int argc3 = 1;
    char *argv3[] = {"-a", NULL};
    cr_assert_eq(check_corewar_args(argc3, argv3), true);
    int argc4 = 1;
    char *argv4[] = {"0123456789ABCDEF", NULL};
    cr_assert_eq(check_corewar_args(argc4, argv4), true);
    int argc5 = 1;
    char *argv5[] = {"test.cor", NULL};
    cr_assert_eq(check_corewar_args(argc5, argv5), true);
    int argc6 = 1;
    char *argv6[] = {"test.txt", NULL};
    cr_assert_eq(check_corewar_args(argc6, argv6), false);
    cr_assert_stderr_eq_str("Error : [test.txt] : Invalid argument\n");
    cr_assert_eq(check_corewar_args(0, argv6), true);
}

Test(corewar_programm_main, tests_corewar_programm_main, .init=redirect, .timeout=1) {
    cr_assert_eq(corewar_programm_main(0, NULL), ERR_OUT);
    int argc1 = 1;
    char *argv1[] = {"./corewar", NULL};
    cr_assert_eq(corewar_programm_main(argc1, argv1), ERR_OUT);
    int argc2 = 2;
    char *argv2[] = {"./corewar", "-h", NULL};
    cr_assert_eq(corewar_programm_main(argc2, argv2), SUC_OUT);
    int argc3 = 2;
    char *argv3[] = {"./corewar", "-dazade", NULL};
    cr_assert_eq(corewar_programm_main(argc3, argv3), ERR_OUT);
    int argc4 = 2;
    char *argv4[] = {"./corewar", "-dump", NULL};
    cr_assert_eq(corewar_programm_main(argc4, argv4), ERR_OUT);
    int argc5 = 7;
    char *argv5[] = {"./corewar", "-a", "AAA", "corewar.cor", "test.cor", "tests2.cor", NULL};
    cr_assert_eq(corewar_programm_main(argc5, argv5), ERR_OUT);

}