/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_progs_number_check
*/

#include "tests_include_header.h"

Test(get_next_valid_prog_nbr, tests_get_next_valid_prog_nbr, .init=redirect, .timeout=1) {
    cr_assert_eq(get_next_valid_prog_nbr(NULL), -1);
    params_progs_t **progs = malloc(sizeof(params_progs_t *) * 3);
    progs[0] = malloc(sizeof(params_progs_t));
    progs[0]->prog_nbr = 0;
    progs[1] = malloc(sizeof(params_progs_t));
    progs[1]->prog_nbr = -1;
    progs[2] = NULL;
    cr_assert_eq(get_next_valid_prog_nbr(progs), 1);
    free(progs[0]);
}

Test(set_prog_numbers, tests_set_prog_numbers, .init=redirect, .timeout=1) {
    set_prog_numbers(NULL);
    params_progs_t **progs = malloc(sizeof(params_progs_t *) * 5);
    progs[0] = malloc(sizeof(params_progs_t));
    progs[0]->prog_nbr = -1;
    progs[1] = malloc(sizeof(params_progs_t));
    progs[1]->prog_nbr = 25;
    progs[2] = malloc(sizeof(params_progs_t));
    progs[2]->prog_nbr = -1;
    progs[3] = malloc(sizeof(params_progs_t));
    progs[3]->prog_nbr = 1;
    progs[4] = NULL;
    set_prog_numbers(progs);
    cr_assert_eq(progs[0]->prog_nbr, 0);
    cr_assert_eq(progs[1]->prog_nbr, 25);
    cr_assert_eq(progs[2]->prog_nbr, 2);
    cr_assert_eq(progs[3]->prog_nbr, 1);
    free(progs[0]);
    free(progs[1]);
    free(progs[2]);
    free(progs[3]);
}

Test(mulitple_prog_nbr_checker, tests_mulitple_prog_nbr_checker, .init=redirect, .timeout=1) {
    cr_assert_eq(mulitple_prog_nbr_checker(NULL, 0, 0), false);
    params_progs_t **progs = malloc(sizeof(params_progs_t *) * 5);
    progs[0] = malloc(sizeof(params_progs_t));
    progs[0]->prog_nbr = 0;
    progs[1] = malloc(sizeof(params_progs_t));
    progs[1]->prog_nbr = 1;
    progs[2] = malloc(sizeof(params_progs_t));
    progs[2]->prog_nbr = 2;
    progs[3] = malloc(sizeof(params_progs_t));
    progs[3]->prog_nbr = 3;
    progs[4] = NULL;
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 0, 0), true);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 1, 1), true);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 2, 2), true);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 3, 3), true);
    progs[0]->prog_nbr = 1;
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 0, 1), false);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 1, 1), false);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 2, 2), true);
    cr_assert_eq(mulitple_prog_nbr_checker(progs, 3, 3), true);
    free(progs[0]);
    free(progs[1]);
    free(progs[2]);
    free(progs[3]);
    free(progs);
}

Test(mulitple_prog_nbr, tests_mulitple_prog_nbr, .init=redirect, .timeout=1) {
    cr_assert_eq(mulitple_prog_nbr(NULL), true);
    params_progs_t **progs = malloc(sizeof(params_progs_t *) * 5);
    progs[0] = malloc(sizeof(params_progs_t));
    progs[0]->prog_nbr = 0;
    progs[1] = malloc(sizeof(params_progs_t));
    progs[1]->prog_nbr = 1;
    progs[2] = malloc(sizeof(params_progs_t));
    progs[2]->prog_nbr = 2;
    progs[3] = malloc(sizeof(params_progs_t));
    progs[3]->prog_nbr = 3;
    progs[4] = NULL;
    cr_assert_eq(mulitple_prog_nbr(progs), false);
    progs[0]->prog_nbr = 1;
    cr_assert_eq(mulitple_prog_nbr(progs), true);
    free(progs[0]);
    free(progs[1]);
    free(progs[2]);
    free(progs[3]);
    free(progs);
}