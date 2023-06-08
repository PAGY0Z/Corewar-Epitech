/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_adresses_check
*/

#include "tests_include_header.h"

Test(one_adress_is_set, tests_one_adress_is_set, .init=redirect, .timeout=1) {
    cr_assert_eq(one_adress_is_set(NULL), false);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 3);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->load_address = -1;
    params_progs[1] = malloc(sizeof(params_progs_t));
    params_progs[1]->load_address = -1;
    params_progs[2] = NULL;
    cr_assert_eq(one_adress_is_set(params_progs), false);
    params_progs[0]->load_address = 0;
    cr_assert_eq(one_adress_is_set(params_progs), true);
    params_progs[0]->load_address = -1;
    params_progs[1]->load_address = 0;
    cr_assert_eq(one_adress_is_set(params_progs), true);
}
    
Test(all_adresses_are_set, tests_all_adresses_are_set, .init=redirect, .timeout=1) {
    cr_assert_eq(all_adresses_are_set(NULL), false);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 3);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->load_address = -1;
    params_progs[1] = malloc(sizeof(params_progs_t));
    params_progs[1]->load_address = -1;
    params_progs[2] = NULL;
    cr_assert_eq(all_adresses_are_set(params_progs), false);
    params_progs[0]->load_address = 0;
    cr_assert_eq(all_adresses_are_set(params_progs), false);
    params_progs[0]->load_address = -1;
    params_progs[1]->load_address = 0;
    cr_assert_eq(all_adresses_are_set(params_progs), false);
    params_progs[0]->load_address = 0;
    params_progs[1]->load_address = 0;
    cr_assert_eq(all_adresses_are_set(params_progs), true);
}