/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_progs_check_update
*/

#include "tests_include_header.h"

Test(params_check_update, tests_params_check_update, .init=redirect, .timeout=1) {
    cr_assert_eq(params_check_update(NULL), false);
    params_t *params = malloc(sizeof(params_t));
    params->prog_nbr = 2;
    params->dump_nbr_cycles = -1;
    params->progs = malloc(sizeof(params_progs_t *) * 3);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->load_address = -1;
    params->progs[0]->prog_nbr = -1;
    params->progs[1] = malloc(sizeof(params_progs_t));
    params->progs[1]->load_address = -1;
    params->progs[1]->prog_nbr = -1;
    params->progs[2] = NULL;
    cr_assert_eq(params_check_update(params), true);
    cr_assert_eq(params->progs[0]->load_address, 0 * (MEM_SIZE / 2));
    cr_assert_eq(params->progs[0]->prog_nbr, 0);
    cr_assert_eq(params->progs[1]->load_address, 1 * (MEM_SIZE / 2));
    cr_assert_eq(params->progs[1]->prog_nbr, 1);
    params->progs[0]->load_address = 0;
    params->progs[1]->load_address = -1;
    cr_assert_eq(params_check_update(params), false);
    params->progs[0]->load_address = 0;
    params->progs[1]->load_address = 0;
    cr_assert_eq(params_check_update(params), true);
    params->progs[0]->prog_nbr = 0;
    params->progs[1]->prog_nbr = 0;
    cr_assert_eq(params_check_update(params), false);
}