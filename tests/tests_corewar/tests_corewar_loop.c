/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_corewar_loop
*/

#include "tests_include_header.h"

Test(different_champ_alive, tests_different_champ_alive, .init=redirect, .timeout=1) {
    corewar_t *global = malloc(sizeof(corewar_t));
    global->champ = malloc(sizeof(champ_t *) * 5);
    global->champ[0] = malloc(sizeof(champ_t));
    global->champ[0]->pc = -1;
    global->champ[1] = malloc(sizeof(champ_t));
    global->champ[1]->pc = 1;
    global->champ[1]->prog_nbr = 1;
    global->champ[2] = malloc(sizeof(champ_t));
    global->champ[2]->pc = 2;
    global->champ[2]->prog_nbr = 1;
    global->champ[3] = malloc(sizeof(champ_t));
    global->champ[3]->pc = 3;
    global->champ[3]->prog_nbr = 3;
    global->champ[4] = NULL;
    cr_assert_eq(different_champ_alive(global), true);
    cr_assert_eq(different_champ_alive(NULL), false);
    global->champ[3]->prog_nbr = 1;
    cr_assert_eq(different_champ_alive(global), false);
}

Test(corewar_loop_condition, tests_corewar_loop_condition, .init=redirect, .timeout=1) {
    cr_assert_eq(corewar_loop_condition(NULL), false);
    corewar_t *global = malloc(sizeof(corewar_t));
    global->dump_nbr_cycles = -1;
    global->champ = malloc(sizeof(champ_t *) * 5);
    global->champ[0] = malloc(sizeof(champ_t));
    global->champ[0]->pc = -1;
    global->champ[1] = malloc(sizeof(champ_t));
    global->champ[1]->pc = 1;
    global->champ[1]->prog_nbr = 1;
    global->champ[2] = malloc(sizeof(champ_t));
    global->champ[2]->pc = 2;
    global->champ[2]->prog_nbr = 1;
    global->champ[3] = malloc(sizeof(champ_t));
    global->champ[3]->pc = 3;
    global->champ[3]->prog_nbr = 3;
    global->champ[4] = NULL;
    cr_assert_eq(corewar_loop_condition(global), true);
    global->champ[3]->prog_nbr = 1;
    cr_assert_eq(corewar_loop_condition(global), false);
    global->champ[3]->prog_nbr = 3;
    global->dump_nbr_cycles = 1;
    cr_assert_eq(corewar_loop_condition(global), true);
    global->dump_nbr_cycles = 0;
    global->arena = malloc(sizeof(byte_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        global->arena[i] = 0;
    global->arena[0] = 100;
    cr_assert_eq(corewar_loop_condition(global), false);
}

Test(dump_memory, tests_dump_memory, .init=redirect, .timeout=1) {
    dump_memory(NULL);
    byte_t *arena = malloc(sizeof(byte_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = 0;
    arena[0] = 100;
    dump_memory(arena);
}

Test(display_winner, tests_display_winner_00, .init=redirect, .timeout=1) {
    display_winner(NULL);
    corewar_t *global = malloc(sizeof(corewar_t));
    global->champ = malloc(sizeof(champ_t *) * 5);
    global->champ[0] = malloc(sizeof(champ_t));
    global->champ[0]->prog_nbr = 1;
    global->champ[1] = malloc(sizeof(champ_t));
    global->champ[1]->prog_nbr = 2;
    global->champ[1]->name = my_strdup("toto", 1);
    global->champ[2] = malloc(sizeof(champ_t));
    global->champ[2]->prog_nbr = 3;
    global->champ[3] = malloc(sizeof(champ_t));
    global->champ[3]->prog_nbr = 4;
    global->champ[4] = NULL;

    global->last_alive = 2;
    display_winner(global);
    cr_assert_stdout_eq_str("The player 2(toto) has won.\n");
}

Test(display_winner, tests_display_winner_01, .init=redirect, .timeout=1) {
    display_winner(NULL);
    corewar_t *global = malloc(sizeof(corewar_t));
    global->champ = malloc(sizeof(champ_t *) * 5);
    global->champ[0] = malloc(sizeof(champ_t));
    global->champ[0]->prog_nbr = 1;
    global->champ[1] = malloc(sizeof(champ_t));
    global->champ[1]->prog_nbr = 2;
    global->champ[1]->name = my_strdup("toto", 1);
    global->champ[2] = malloc(sizeof(champ_t));
    global->champ[2]->prog_nbr = 3;
    global->champ[3] = malloc(sizeof(champ_t));
    global->champ[3]->prog_nbr = 4;
    global->champ[4] = NULL;

    global->last_alive = -1;
    display_winner(global);
    cr_assert_stdout_eq_str("No winner.\n");
}
