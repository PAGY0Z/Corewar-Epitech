/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_get_header
*/

#include "tests_include_header.h"

Test(get_header, tests_get_header, .init=redirect, .timeout=1) {
    cr_assert_eq(get_header(NULL, NULL), false);
    cr_assert_eq(get_header(NULL, "tests/asm_tests/valid_files/valid_file.s"), false);
    header_t header = {0};
    cr_assert_eq(get_header(&header, NULL), false);
    cr_assert_eq(get_header(&header, ""), false);
    cr_assert_eq(get_header(&header, "non existent"), false);
    cr_assert_eq(get_header(&header, "tests/tests_files/filled_readable"), false);
    header_t header2 = {0};
    cr_assert_eq(get_header(&header2, "tests/asm_reference_binaries/champions/abel.cor"), true);
    cr_assert_str_eq(header2.prog_name, "Abel");
    cr_assert_str_eq(header2.comment, "L'amer noir.");
    cr_assert_eq(reverse_int(header2.magic), MAGIC_NUMBER_VALUE);
}