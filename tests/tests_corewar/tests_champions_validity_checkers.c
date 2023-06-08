/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_champions_validity_checkers
*/

#include "tests_include_header.h"

Test(check_header_magic_number_prog_size, tests_check_header_magic_number_prog_size, .init=redirect, .timeout=1) {
    header_t header = {0};
    header.magic = 0;
    cr_assert_eq(check_header_magic_number_prog_size(header, 100), false);
    header.magic = 0xF383EA00;
    header.prog_size = 100;
    cr_assert_eq(check_header_magic_number_prog_size(header, 100), false);
    header.prog_size = 0x64000000;
    cr_assert_eq(check_header_magic_number_prog_size(header, 2292), true);
}

Test(check_header_prog_name, tests_check_header_prog_name, .init=redirect, .timeout=1) {
    header_t header = {0};
    header.magic = 0;
    header.prog_size = 0;
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        header.prog_name[i] = 'a';
    for (int i = PROG_NAME_LENGTH; i < PROG_NAME_LENGTH + 4; i++)
        header.prog_name[i] = '\0';
    cr_assert_eq(check_header_prog_name(header), true);
    header.prog_name[0] = '\0';
    cr_assert_eq(check_header_prog_name(header), true);
    header.prog_name[1] = 1;
    cr_assert_eq(check_header_prog_name(header), false);
    header.prog_name[1] = 127;
    cr_assert_eq(check_header_prog_name(header), false);
    header.prog_name[1] = 0;
    header.prog_name[PROG_NAME_LENGTH] = 'a';
    cr_assert_eq(check_header_prog_name(header), false);
}

Test(check_header_comment, tests_check_header_comment, .init=redirect, .timeout=1) {
    header_t header = {0};
    header.magic = 0;
    header.prog_size = 0;
    for (int i = 0; i < COMMENT_LENGTH; i++)
        header.comment[i] = 'a';
    for (int i = COMMENT_LENGTH; i < COMMENT_LENGTH + 4; i++)
        header.comment[i] = '\0';
    cr_assert_eq(check_header_comment(header), true);
    header.comment[0] = '\0';
    cr_assert_eq(check_header_comment(header), true);
    header.comment[1] = 1;
    cr_assert_eq(check_header_comment(header), false);
    header.comment[1] = 127;
    cr_assert_eq(check_header_comment(header), false);
    header.comment[1] = 0;
    header.comment[COMMENT_LENGTH] = 'a';
    cr_assert_eq(check_header_comment(header), false);
}

Test(champions_validity_checkers, tests_champions_validity_checkers, .init=redirect, .timeout=1) {
    cr_assert_eq(champions_validity_checkers(NULL), false);
    params_progs_t *params = malloc(sizeof(params_progs_t));
    params->prog_name = NULL;
    cr_assert_eq(champions_validity_checkers(params), false);
    params->prog_name = my_strdup("tests/tests_files/filled_readable", 1);
    cr_assert_eq(champions_validity_checkers(params), false);
}