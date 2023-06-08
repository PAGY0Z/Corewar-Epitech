/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_exits_init_params
*/

#include "tests_include_header.h"

Test(e_init_params, tests_e_init_params, .init=redirect, .timeout=1) {
    params_t *params = malloc(sizeof(params_t));

    cr_assert_null(e_init_params(params));
    cr_assert_null(e_init_params(NULL));
}
