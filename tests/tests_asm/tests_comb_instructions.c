/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_comb_instructions
*/

#include "tests_include_header.h"

Test(add_reg_ind, tests_add_reg_ind, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_reg_ind(asm_s, "", 0, 0), false);
    cr_assert_eq(add_reg_ind(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_reg_ind(asm_s, ":123", 0, 1), true);
    cr_assert_eq(add_reg_ind(asm_s, "r3", 0, 1), true);
    cr_assert_eq(add_reg_ind(asm_s, ":123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_reg_dirindex_ind, tests_add_reg_dirindex_ind, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_reg_dirindex_ind(asm_s, "", 0, 0), false);
    cr_assert_eq(add_reg_dirindex_ind(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_reg_dirindex_ind(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_reg_dirindex_ind(asm_s, "r3", 0, 1), true);
    cr_assert_eq(add_reg_dirindex_ind(asm_s, "%123", 0, 0), true);
    cr_assert_eq(add_reg_dirindex_ind(asm_s, "123", 0, 1), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_reg_dirindex, tests_add_reg_dirindex, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_reg_dirindex(asm_s, "", 0, 0), false);
    cr_assert_eq(add_reg_dirindex(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_reg_dirindex(asm_s, "123", 0, 1), false);
    cr_assert_eq(add_reg_dirindex(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_reg_dirindex(asm_s, "r3", 0, 1), true);
    cr_assert_eq(add_reg_dirindex(asm_s, "%123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_reg_dir_ind, tests_add_reg_dir_ind, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_reg_dir_ind(asm_s, "", 0, 0), false);
    cr_assert_eq(add_reg_dir_ind(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_reg_dir_ind(asm_s, "123", 0, 1), true);
    cr_assert_eq(add_reg_dir_ind(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_reg_dir_ind(asm_s, "r3", 0, 1), true);
    cr_assert_eq(add_reg_dir_ind(asm_s, "%123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_reg_dir, tests_add_reg_dir, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_reg_dir(asm_s, "", 0, 0), false);
    cr_assert_eq(add_reg_dir(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_reg_dir(asm_s, "123", 0, 1), false);
    cr_assert_eq(add_reg_dir(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_reg_dir(asm_s, "r3", 0, 1), true);
    cr_assert_eq(add_reg_dir(asm_s, "%123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_dirindex_ind, tests_add_dirindex_ind, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_dirindex_ind(asm_s, "", 0, 0), false);
    cr_assert_eq(add_dirindex_ind(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_dirindex_ind(asm_s, "r3", 0, 1), false);
    cr_assert_eq(add_dirindex_ind(asm_s, "123", 0, 1), true);
    cr_assert_eq(add_dirindex_ind(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_dirindex_ind(asm_s, "%123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(add_dir_ind, tests_add_dir_ind, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    cr_assert_eq(add_dir_ind(asm_s, "", 0, 0), false);
    cr_assert_eq(add_dir_ind(asm_s, ":", 0, 0), false);
    cr_assert_eq(add_dir_ind(asm_s, "r3", 0, 1), false);
    cr_assert_eq(add_dir_ind(asm_s, "123", 0, 1), true);
    cr_assert_eq(add_dir_ind(asm_s, "%123", 0, 1), true);
    cr_assert_eq(add_dir_ind(asm_s, "%123", 0, 0), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}
