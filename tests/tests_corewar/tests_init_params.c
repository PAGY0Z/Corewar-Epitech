/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_init_params
*/

#include "tests_include_header.h"

Test(get_dump_nbr_cycle, tests_get_dump_nbr_cycle, .init=redirect, .timeout=1) {
    cr_assert_eq(get_dump_nbr_cycle(NULL, NULL), FAILURE);
    params_t *params = malloc(sizeof(params_t));
    params->dump_nbr_cycles = -1;
    params->progs = NULL;
    params->prog_nbr = -1;
    cr_assert_eq(get_dump_nbr_cycle(NULL, params), FAILURE);
    char *argv[] = {"-dump", "0", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv, NULL), FAILURE);
    char *argv1[] = {"-dump", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv1, params), NONE);
    char *argv2[] = {"Hello World", "0", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv2, params), NONE);
    char *argv3[] = {"-dump", "wtf is this shit", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv3, params), FAILURE);
    char *argv4[] = {"-dump", "FF", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv4, params), SUCCESS);
    cr_assert_eq(params->dump_nbr_cycles, 255);
    char *argv5[] = {"-dump", "FFFFFFFF", NULL};
    cr_assert_eq(get_dump_nbr_cycle(argv5, params), SUCCESS);
    cr_assert_eq(params->dump_nbr_cycles, 1);
    free(params);
}

Test(get_params_prog_nbr, tests_get_params_prog_nbr, .init=redirect, .timeout=1) {
    cr_assert_eq(get_params_prog_nbr(NULL, NULL), false);
    params_t *params = malloc(sizeof(params_t));
    params->dump_nbr_cycles = -1;
    params->progs = NULL;
    params->prog_nbr = -1;
    cr_assert_eq(get_params_prog_nbr(NULL, params), false);
    char *argv[] = {NULL};
    cr_assert_eq(get_params_prog_nbr(argv, NULL), false);
    char *argv0[] = {"hello", "bye", "fuck it", NULL};
    cr_assert_eq(get_params_prog_nbr(argv0, params), false);
    char *argv1[] = {"hello.cor", NULL};
    cr_assert_eq(get_params_prog_nbr(argv1, params), false);
    char *argv2[] = {"hello.cor", "bye.cor", NULL};
    cr_assert_eq(get_params_prog_nbr(argv2, params), true);
    cr_assert_eq(params->prog_nbr, 2);
}

Test(init_params_progs, tests_init_params_progs, .init=redirect, .timeout=1) {
    cr_assert_eq(init_params_progs(NULL, 1), false);
    params_t *params = malloc(sizeof(params_t));
    params->prog_nbr = -15;
    cr_assert_eq(init_params_progs(params, 1), false);
    params->prog_nbr = 10;
    cr_assert_eq(init_params_progs(params, -1), false);
    cr_assert_eq(init_params_progs(params, 1), true);
}

Test(get_params_progs, tests_get_params_progs, .init=redirect, .timeout=1) {

}

Test(init_params, tests_init_params, .init=redirect, .timeout=1) {
    cr_assert_null(init_params(NULL, 1, 1));
    char *argv[] = {NULL};
    cr_assert_null(init_params(argv, -1, 1));
    char *argv1[] = {"-dump", "shit", NULL};
    cr_assert_null(init_params(argv1, 1, 1));
    char *argv2[] = {"-dump", "A", NULL};
    cr_assert_null(init_params(argv2, 1, 1));
    char *argv3[] = {"hello.cor", "caca.cor", NULL};
    cr_assert_null(init_params(argv3, 1, -1));
    // char *argv3[] = {"-n", "hello.cor", "caca.cor", NULL};
    // cr_assert_null(init_params(argv3, 1, 1));
    // char *argv3[] = {"-n", "hello.cor", "caca.cor", NULL};
    // cr_assert_null(init_params(argv3, 1, 1));
}
