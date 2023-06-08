/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_update_champ_params
*/

#include "tests_include_header.h"

Test(update_champ_params, tests_update_champ_params, .init=redirect, .timeout=1) {
    champ_t *champ = malloc(sizeof(champ_t));
    champ->params = malloc(sizeof(byte_t) * 14);
    byte_t *arena = malloc(sizeof(byte_t) * 4096);
    champ->pc = 0;
    for (int i = 0; i < 4096; i++)
        arena[i] = 0;
    arena[0] = 1; champ->params[0] = 0; 
    arena[1] = 2; champ->params[1] = 0; 
    arena[2] = 3; champ->params[2] = 0; 
    arena[3] = 4; champ->params[3] = 0; 
    arena[4] = 5; champ->params[4] = 0; 
    arena[5] = 6; champ->params[5] = 0; 
    arena[6] = 7; champ->params[6] = 0; 
    arena[7] = 8; champ->params[7] = 0; 
    arena[8] = 9; champ->params[8] = 0; 
    arena[9] = 10; champ->params[9] = 0; 
    arena[10] = 11; champ->params[10] = 0; 
    arena[11] = 12; champ->params[11] = 0; 
    arena[12] = 13; champ->params[12] = 0; 
    arena[13] = 14; champ->params[13] = 0; 
    update_champ_params(arena, champ);
    cr_assert_eq(champ->params[0], 1);
    cr_assert_eq(champ->params[1], 2);
    cr_assert_eq(champ->params[2], 3);
    cr_assert_eq(champ->params[3], 4);
    cr_assert_eq(champ->params[4], 5);
    cr_assert_eq(champ->params[5], 6);
    cr_assert_eq(champ->params[6], 7);
    cr_assert_eq(champ->params[7], 8);
    cr_assert_eq(champ->params[8], 9);
    cr_assert_eq(champ->params[9], 10);
    cr_assert_eq(champ->params[10], 11);
    cr_assert_eq(champ->params[11], 12);
    cr_assert_eq(champ->params[12], 13);
    cr_assert_eq(champ->params[13], 14);
    free(champ->params);
    free(champ);
    free(arena);
}

Test(reset_champ_params, tests_reset_champ_params, .init=redirect, .timeout=1) {
    champ_t *champ = malloc(sizeof(champ_t));
    champ->params = malloc(sizeof(byte_t) * 14);
    champ->params[0] = 0; 
    champ->params[1] = 1; 
    champ->params[2] = 2; 
    champ->params[3] = 3; 
    champ->params[4] = 4; 
    champ->params[5] = 5; 
    champ->params[6] = 6; 
    champ->params[7] = 7; 
    champ->params[8] = 8; 
    champ->params[9] = 9; 
    champ->params[10] = 10; 
    champ->params[11] = 11; 
    champ->params[12] = 12; 
    champ->params[13] = 13; 
    reset_champ_params(champ);
    cr_assert_eq(champ->params[0], 0);
    cr_assert_eq(champ->params[1], 0);
    cr_assert_eq(champ->params[2], 0);
    cr_assert_eq(champ->params[3], 0);
    cr_assert_eq(champ->params[4], 0);
    cr_assert_eq(champ->params[5], 0);
    cr_assert_eq(champ->params[6], 0);
    cr_assert_eq(champ->params[7], 0);
    cr_assert_eq(champ->params[8], 0);
    cr_assert_eq(champ->params[9], 0);
    cr_assert_eq(champ->params[10], 0);
    cr_assert_eq(champ->params[11], 0);
    cr_assert_eq(champ->params[12], 0);
    cr_assert_eq(champ->params[13], 0);
    free(champ->params);
    free(champ);
}

