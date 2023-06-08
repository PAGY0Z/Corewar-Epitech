/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_exits_init_asm
*/


#include "tests_include_header.h"

Test(e_init_buffer, tests_e_init_buffer, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    cr_assert_null(e_init_buffer(asm_s));
}

Test(e_init_file_name, tests_e_init_file_name, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(char) * 1);
    cr_assert_null(e_init_file_name(asm_s));
}

Test(e_init_file_lines, tests_e_init_file_lines, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(char) * 1);
    asm_s->file_name = malloc(sizeof(char) * 1);
    cr_assert_null(e_init_file_lines(asm_s));
}

Test(e_init_init_labels, tests_e_init_init_labels, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(char) * 1);
    asm_s->file_name = malloc(sizeof(char) * 1);
    asm_s->file_lines = malloc(sizeof(char *) * 2);
    asm_s->file_lines[0] = malloc(sizeof(char) * 1);
    asm_s->file_lines[1] = NULL;
    cr_assert_null(e_init_init_labels(asm_s));
}

Test(e_init_asm_programm, tests_e_init_asm_programm, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(char) * 1);
    asm_s->file_name = malloc(sizeof(char) * 1);
    asm_s->file_lines = malloc(sizeof(char *) * 2);
    asm_s->file_lines[0] = malloc(sizeof(char) * 1);
    asm_s->file_lines[1] = NULL;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[1] = NULL;
    asm_s->labels[0]->nbcalls = 0;
    asm_s->labels[0]->name = NULL;
    cr_assert_eq(e_init_asm_programm(asm_s), 84);
    cr_assert_eq(e_init_asm_programm(NULL), 84);
}