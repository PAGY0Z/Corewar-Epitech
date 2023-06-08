/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_get_arena_adress
*/

#include "tests_include_header.h"

Test(get_arena_adress, tests_get_arena_adress, .init=redirect, .timeout=1) {
    cr_assert_eq(get_arena_adress(1), 1);
    cr_assert_eq(get_arena_adress(0), 0);
    cr_assert_eq(get_arena_adress(MEM_SIZE), 0);
    cr_assert_eq(get_arena_adress(MEM_SIZE + 1), 1);
    cr_assert_eq(get_arena_adress(-1), MEM_SIZE - 1);
    cr_assert_eq(get_arena_adress(-MEM_SIZE), 0);
    cr_assert_eq(get_arena_adress(-MEM_SIZE - 1), MEM_SIZE - 1);
    cr_assert_eq(get_arena_adress(-MEM_SIZE - 2), MEM_SIZE - 2);
    cr_assert_eq(get_arena_adress(-MEM_SIZE - 3), MEM_SIZE - 3);
    cr_assert_eq(get_arena_adress(MEM_SIZE * (-4)), 0);
}