/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_replace_labels
*/

#include "tests_include_header.h"

Test(replace_values_in_buffer, tests_replace_values_in_buffer, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t) * 4);
    replace_values_in_buffer(asm_s, 0x12345678, 0, 4);
    cr_assert_eq(asm_s->buffer[0], 0x12);
    cr_assert_eq(asm_s->buffer[1], 0x34);
    cr_assert_eq(asm_s->buffer[2], 0x56);
    cr_assert_eq(asm_s->buffer[3], 0x78);
    replace_values_in_buffer(asm_s, 0x6789, 2, 2);
    cr_assert_eq(asm_s->buffer[2], 0x67);
    cr_assert_eq(asm_s->buffer[3] & 0xff, 0x89);
}


Test(replace_labels, tests_replace_labels, .init=redirect, .timeout=1) {

}