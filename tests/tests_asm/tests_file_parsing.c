/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_file_parsing
*/

#include "tests_include_header.h"

Test(add_name, tests_add_name, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_name(NULL), false);
    asm_s->file_lines = malloc(sizeof(char*));
    asm_s->file_lines[0] = NULL;
    asm_s->line_index = 0;
    cr_assert_eq(add_name(asm_s), false);
    free(asm_s->file_lines);
    free(asm_s->buffer);
    free(asm_s);
}

Test(file_parsing, tests_file_parsing, .init=redirect, .timeout=1) {
        asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("USELESS", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(file_parsing(NULL), false);
    asm_s->index = -14;
    cr_assert_eq(file_parsing(asm_s), false);
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char*) * 4);
    asm_s->file_lines[0] = my_strdup(".name \"test\"", 1);
    asm_s->file_lines[1] = my_strdup(".comment \"test\"", 1);
    asm_s->file_lines[2] = my_strdup("ntm", 1);
    asm_s->file_lines[3] = NULL;
    asm_s->line_index = 0;
    cr_assert_eq(file_parsing(asm_s), false);
    free(asm_s->file_lines[0]);
    free(asm_s->file_lines);
    free(asm_s->buffer);
    free(asm_s);
}
