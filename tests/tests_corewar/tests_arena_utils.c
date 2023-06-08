/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_arena_utils
*/

#include "tests_include_header.h"

Test(get_4b_mem, tests_get_4b_mem, .init = redirect, .timeout = 1) {
    corewar_t *global = malloc(sizeof(corewar_t));
    global->arena = malloc(sizeof(byte_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        global->arena[i] = 0x00;
    
    global->arena[MEM_SIZE - 1] = 0x00;
    global->arena[0] = 0x00;
    global->arena[1] = 0x00;
    global->arena[2] = 0x01;

    cr_assert_eq(get_4b_mem(global, (MEM_SIZE - 1)), 1);
}