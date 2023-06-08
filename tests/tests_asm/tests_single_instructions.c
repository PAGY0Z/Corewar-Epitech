/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_single_instructions
*/

#include "tests_include_header.h"

Test(add_direct, tests_add_direct, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_direct(NULL, "1234", 14), false);

    cr_assert_eq(add_direct(asm_s, "%zaer1", 14), false);

    asm_s->labels[0]->nbcalls = -15;
    cr_assert_eq(add_direct(asm_s, "%:123", 0), false);
    asm_s->labels[0]->nbcalls = 0;

    cr_assert_eq(add_direct(asm_s, "%:123", 0), true);
    cr_assert_eq(add_direct(asm_s, "%123", 0), true);
    free(asm_s->buffer);
    free(asm_s);
}

Test(add_direct_index, tests_add_direct_index, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[0]->callpos = NULL;
    asm_s->labels[0]->callsize = NULL;
    asm_s->labels[0]->cmdpos = NULL;
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_direct_index(NULL, "1234", 14), false);

    cr_assert_eq(add_direct_index(asm_s, "%zaer1", 14), false);

    asm_s->labels[0]->nbcalls = -15;
    cr_assert_eq(add_direct_index(asm_s, "%:123", 0), false);
    asm_s->labels[0]->nbcalls = 0;

    cr_assert_eq(add_direct_index(asm_s, "%:123", 0), true);
    cr_assert_eq(add_direct_index(asm_s, "%123", 0), true);
    free(asm_s->buffer);
    free(asm_s);
}

Test(add_indirect, tests_add_indirect, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    cr_assert_eq(add_indirect(NULL, "azef", 14), false);
    cr_assert_eq(add_indirect(NULL, "!%&", 14), false);
    cr_assert_eq(add_indirect(NULL, "!%&", 14), false);
    cr_assert_eq(add_indirect(NULL, "123er", 0), false);

    asm_s->labels[0] = NULL;
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_indirect(asm_s, ":123", 0), false);

    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[0]->callpos = NULL;
    asm_s->labels[0]->callsize = NULL;
    asm_s->labels[0]->cmdpos = NULL;

    asm_s->labels[0]->nbcalls = -14;
    cr_assert_eq(add_indirect(asm_s, ":123", 0), false);
    asm_s->labels[0]->nbcalls = 0;

    cr_assert_eq(add_indirect(asm_s, "+123", 0), true);
    cr_assert_eq(add_indirect(asm_s, "-123", 0), true);
    cr_assert_eq(add_indirect(asm_s, "123", 0), true);
    cr_assert_eq(add_indirect(asm_s, ":123", 0), true);
    free(asm_s->buffer);
    free(asm_s);
}

Test(add_instructions, tests_add_instructions, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char *) * 1);
    asm_s->line_index = 0;
    asm_s->labels = NULL;
    cr_assert_eq(add_instructions(NULL), false);
    asm_s->file_lines[0] = my_strdup("USELESS", 1);
    cr_assert_eq(add_instructions(asm_s), false);
    free(asm_s->buffer);
    free(asm_s->file_lines[0]);
    free(asm_s->file_lines);
    free(asm_s);
}

Test(line_treatment, tests_line_treatment, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char *) * 1);
    asm_s->line_index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = NULL;
    asm_s->labels[1] = NULL;
    char *line1 = NULL;
    char *line2 = "USELESS";
    char line3[] = ": zjmp";
    cr_assert_eq(line_treatment(asm_s, line1), false);
    cr_assert_eq(line_treatment(NULL, line2), false);
    cr_assert_eq(line_treatment(asm_s, line2), false);
    cr_assert_eq(line_treatment(asm_s, line3), false);
    free(asm_s->buffer);
    free(asm_s->file_lines[0]);
    free(asm_s->file_lines);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_instruction, tests_add_instruction, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char *));
    asm_s->line_index = 0;
    asm_s->labels = NULL;
    char **arr1 = NULL;
    char *arr2[] = {"USELESS", NULL};
    char *arr3[] = {"aff", NULL};
    char *arr4[] = {NULL};
    cr_assert_eq(add_instruction(asm_s, arr1), false);
    cr_assert_eq(add_instruction(asm_s, arr2), false);
    asm_s->file_lines[0] = NULL;
    cr_assert_eq(add_instruction(asm_s, arr3), false);
    cr_assert_eq(add_instruction(asm_s, arr4), true);
    free(asm_s->buffer);
    free(asm_s->file_lines);
    free(asm_s);
}

Test(add_comment_to_buffer, tests_add_comment_to_buffer, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char *) * 1);
    asm_s->line_index = 0;
    asm_s->labels = NULL;
    char *line1 = NULL;
    char *line2 = "USELESS";
    char *line3 = "";
    char *line4 = ".comment \"USELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESS\"";
    char *line5 = ".comment \"USELESS\"";
    cr_assert_eq(add_comment_to_buffer(asm_s, line1), false);
    cr_assert_eq(add_comment_to_buffer(NULL, line2), false);
    cr_assert_eq(add_comment_to_buffer(asm_s, line3), false);
    cr_assert_eq(add_comment_to_buffer(asm_s, line4), false);
    asm_s->index = -14;
    cr_assert_eq(add_comment_to_buffer(asm_s, line5), false);
    asm_s->index = 0;
    free(asm_s->buffer);
    free(asm_s->file_lines[0]);
    free(asm_s->file_lines);
    free(asm_s);
}


Test(add_name_to_buffer, tests_add_name_to_buffer, .init=redirect,.timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->file_lines = malloc(sizeof(char *) * 1);
    asm_s->line_index = 0;
    asm_s->labels = NULL;
    char *line1 = NULL;
    char *line2 = "";
    char *line3 = ".name \"USELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESSUSELESS\"";
    char *line4 = ".name \"USELESS\"";
    cr_assert_eq(add_name_to_buffer(asm_s, line1), false);
    cr_assert_eq(add_name_to_buffer(asm_s, line2), false);
    cr_assert_eq(add_name_to_buffer(asm_s, line3), false);
    asm_s->index = -14;
    cr_assert_eq(add_name_to_buffer(asm_s, line4), false);
    asm_s->index = 0;
    free(asm_s->buffer);
    free(asm_s->file_lines[0]);
    free(asm_s->file_lines);
    free(asm_s);
}
