/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_init_asm_programm
*/

#include "tests_include_header.h"

Test(init_asm_struct, tests_init_asm_struct, .init=redirect, .timeout=1) {
    char *line1 = NULL;
    char *line2 = "USELESS";
    char *line3 = "tests/tests_files/unreadable_file.cor";
    char *line4 = "tests/tests_files/filled_readable";
    cr_assert_eq(init_asm_struct(line1), NULL);
    cr_assert_eq(init_asm_struct(line2), NULL);
    cr_assert_eq(init_asm_struct(line3), NULL);
    cr_assert_eq(init_asm_struct(line4), NULL);
}

Test(init_asm_programm, tests_init_asm_programm, .init=redirect, .timeout=1) {
    char *line1 = NULL;
    char *line2 = "USELESS";
    char *line3 = "tests/tests_files/filled_readable";
    cr_assert_eq(init_asm_programm(line1), 84);
    cr_assert_eq(init_asm_programm(line2), 84);
    cr_assert_eq(init_asm_programm(line3), 84);
}
