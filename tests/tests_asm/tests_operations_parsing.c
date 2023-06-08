/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_operations_parsing
*/

#include "tests_include_header.h"

Test(parsing_01_live, tests_parsing_01_live, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not live", "live", NULL};
    char *arr3[] = {"live", "not_line", NULL};
    char *arr4[] = {"live", "%123", NULL};
    cr_assert_eq(parsing_01_live(asm_s, NULL), false);
    cr_assert_eq(parsing_01_live(asm_s, arr1), false);
    cr_assert_eq(parsing_01_live(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_01_live(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_01_live(asm_s, arr3), false);
    cr_assert_eq(parsing_01_live(asm_s, arr4), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_02_ld, tests_parsing_02_ld, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", "USELESS", NULL};
    char *arr3[] = {"ld", "USELESS", "USELESS", NULL};
    char *arr4[] = {"ld", "USELESS", "USELESS", NULL};
    cr_assert_eq(parsing_02_ld(asm_s, arr1), false);
    cr_assert_eq(parsing_02_ld(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_02_ld(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_02_ld(asm_s, arr4), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_03_st, tests_parsing_03_st, .init=redirect, .timeout=1) {
        asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", "USELESS", NULL};
    char *arr3[] = {"st", "USELESS", "USELESS", NULL};
    char *arr4[] = {"st", "USELESS", "USELESS", NULL};
    cr_assert_eq(parsing_03_st(asm_s, arr1), false);
    cr_assert_eq(parsing_03_st(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_03_st(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_03_st(asm_s, arr4), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_04_add, tests_parsing_04_add, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not add", "add", "123", "123", NULL};
    char *arr3[] = {"add", "241", "123", "123", NULL};
    char *arr4[] = {"add", "r1", "123", "123", NULL};
    char *arr5[] = {"add", "r1", "r3", "123", NULL};
    char *arr6[] = {"add", "r1", "r2", "r4", NULL};
    cr_assert_eq(parsing_04_add(asm_s, NULL), false);
    cr_assert_eq(parsing_04_add(asm_s, arr1), false);
    cr_assert_eq(parsing_04_add(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_04_add(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_04_add(asm_s, arr3), false);
    cr_assert_eq(parsing_04_add(asm_s, arr4), false);
    cr_assert_eq(parsing_04_add(asm_s, arr5), false);
    cr_assert_eq(parsing_04_add(asm_s, arr6), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_05_sub, tests_parsing_05_sub, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not sub", "sub", "123", "123", NULL};
    char *arr3[] = {"sub", "241", "123", "123", NULL};
    char *arr4[] = {"sub", "r1", "123", "123", NULL};
    char *arr5[] = {"sub", "r1", "r3", "123", NULL};
    char *arr6[] = {"sub", "r1", "r2", "r4", NULL};
    cr_assert_eq(parsing_05_sub(asm_s, NULL), false);
    cr_assert_eq(parsing_05_sub(asm_s, arr1), false);
    cr_assert_eq(parsing_05_sub(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_05_sub(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_05_sub(asm_s, arr3), false);
    cr_assert_eq(parsing_05_sub(asm_s, arr4), false);
    cr_assert_eq(parsing_05_sub(asm_s, arr5), false);
    cr_assert_eq(parsing_05_sub(asm_s, arr6), true);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_06_and, tests_parsing_06_and, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not and", "and", "123", "123", NULL};
    char *arr3[] = {"and", "241", "123", "123", NULL};
    char *arr4[] = {"and", "hello world", "123", "123", NULL};
    char *arr5[] = {"and", "r1", "hello", "123", NULL};
    char *arr6[] = {"and", "r1", "r2", "world", NULL};
    cr_assert_eq(parsing_06_and(asm_s, NULL), false);
    cr_assert_eq(parsing_06_and(asm_s, arr1), false);
    cr_assert_eq(parsing_06_and(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_06_and(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_06_and(asm_s, arr3), false);
    cr_assert_eq(parsing_06_and(asm_s, arr4), false);
    cr_assert_eq(parsing_06_and(asm_s, arr5), false);
    cr_assert_eq(parsing_06_and(asm_s, arr6), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_07_or, tests_parsing_07_or, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not or", "or", "123", "123", NULL};
    char *arr3[] = {"or", "241", "123", "123", NULL};
    char *arr4[] = {"or", "hello world", "123", "123", NULL};
    char *arr5[] = {"or", "r1", "hello", "123", NULL};
    char *arr6[] = {"or", "r1", "r2", "world", NULL};
    cr_assert_eq(parsing_07_or(asm_s, NULL), false);
    cr_assert_eq(parsing_07_or(asm_s, arr1), false);
    cr_assert_eq(parsing_07_or(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_07_or(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_07_or(asm_s, arr3), false);
    cr_assert_eq(parsing_07_or(asm_s, arr4), false);
    cr_assert_eq(parsing_07_or(asm_s, arr5), false);
    cr_assert_eq(parsing_07_or(asm_s, arr6), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_08_xor, tests_parsing_08_xor, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not xor", "xor", "123", "123", NULL};
    char *arr3[] = {"xor", "241", "123", "123", NULL};
    char *arr4[] = {"xor", "hello world", "123", "123", NULL};
    char *arr5[] = {"xor", "r1", "hello", "123", NULL};
    char *arr6[] = {"xor", "r1", "r2", "world", NULL};
    cr_assert_eq(parsing_08_xor(asm_s, NULL), false);
    cr_assert_eq(parsing_08_xor(asm_s, arr1), false);
    cr_assert_eq(parsing_08_xor(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_08_xor(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_08_xor(asm_s, arr3), false);
    cr_assert_eq(parsing_08_xor(asm_s, arr4), false);
    cr_assert_eq(parsing_08_xor(asm_s, arr5), false);
    cr_assert_eq(parsing_08_xor(asm_s, arr6), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_09_zjmp, tests_parsing_09_zjmp, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not zjmp", "zjmp", NULL};
    char *arr3[] = {"zjmp", "241", NULL};

    cr_assert_eq(parsing_09_zjmp(asm_s, NULL), false);
    cr_assert_eq(parsing_09_zjmp(asm_s, arr1), false);
    cr_assert_eq(parsing_09_zjmp(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_09_zjmp(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_09_zjmp(asm_s, arr3), false);

    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_10_ldi, tests_parsing_10_ldi, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not ldi", "ldi", "123", "123", NULL};
    char *arr3[] = {"ldi", "241", "123", "123", NULL};
    char *arr4[] = {"ldi", "hello world", "123", "123", NULL};
    char *arr5[] = {"ldi", "r1", "hello", "123", NULL};
    char *arr6[] = {"ldi", "r1", "r2", "world", NULL};
    cr_assert_eq(parsing_10_ldi(asm_s, NULL), false);
    cr_assert_eq(parsing_10_ldi(asm_s, arr1), false);
    cr_assert_eq(parsing_10_ldi(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_10_ldi(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_10_ldi(asm_s, arr3), false);
    cr_assert_eq(parsing_10_ldi(asm_s, arr4), false);
    cr_assert_eq(parsing_10_ldi(asm_s, arr5), false);
    cr_assert_eq(parsing_10_ldi(asm_s, arr6), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_11_sti, tests_parsing_11_sti, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", "USELESS", "USELESS", "USELESS", NULL};
    char *arr2[] = {"sti", "USELESS", "USELESS", "USELESS", NULL};
    char *arr3[] = {"sti", "USELESS", "USELESS", "USELESS", NULL};
    char *arr4[] = {"sti", "r1", "USELESS", "USELESS", NULL};
    cr_assert_eq(parsing_11_sti(asm_s, NULL), false);
    cr_assert_eq(parsing_11_sti(asm_s, arr1), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_11_sti(asm_s, arr2), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_11_sti(asm_s, arr3), false);
    cr_assert_eq(parsing_11_sti(asm_s, arr4), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_12_fork, tests_parsing_12_fork, .init=redirect, .timeout=1) {
        asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", NULL};
    char *arr3[] = {"fork", "USELESS", NULL};
    cr_assert_eq(parsing_12_fork(asm_s, arr1), false);
    cr_assert_eq(parsing_12_fork(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_12_fork(asm_s, arr3), false);
    asm_s->index = 0;
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}


Test(parsing_13_lld, tests_parsing_13_lld, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", "USELESS", NULL};
    char *arr3[] = {"lld", "USELESS", "USELESS", NULL};
    char *arr4[] = {"lld", "USELESS", "USELESS", NULL};
    char *arr5[] = {"lld", "123", "USELESS", NULL};
    cr_assert_eq(parsing_13_lld(asm_s, arr1), false);
    cr_assert_eq(parsing_13_lld(asm_s, arr2), false);
    cr_assert_eq(parsing_13_lld(asm_s, arr3), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_13_lld(asm_s, arr4), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_13_lld(asm_s, arr5), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_14_lldi, tests_parsing_14_lldi, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"not live", NULL};
    char *arr2[] = {"not lldi", "lldi", "123", "123", NULL};
    char *arr3[] = {"lldi", "241", "123", "123", NULL};
    char *arr4[] = {"lldi", "hello world", "123", "123", NULL};
    char *arr5[] = {"lldi", "r1", "hello", "123", NULL};
    char *arr6[] = {"lldi", "r1", "r2", "world", NULL};
    cr_assert_eq(parsing_14_lldi(asm_s, NULL), false);
    cr_assert_eq(parsing_14_lldi(asm_s, arr1), false);
    cr_assert_eq(parsing_14_lldi(asm_s, arr2), false);
    asm_s->index = -15;
    cr_assert_eq(parsing_14_lldi(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_14_lldi(asm_s, arr3), false);
    cr_assert_eq(parsing_14_lldi(asm_s, arr4), false);
    cr_assert_eq(parsing_14_lldi(asm_s, arr5), false);
    cr_assert_eq(parsing_14_lldi(asm_s, arr6), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_15_lfork, tests_parsing_15_lfork, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", NULL};
    char *arr3[] = {"lfork", "USELESS", NULL};
    cr_assert_eq(parsing_15_lfork(asm_s, arr1), false);
    cr_assert_eq(parsing_15_lfork(asm_s, arr2), false);
    asm_s->index = -14;
    cr_assert_eq(parsing_15_lfork(asm_s, arr3), false);
    asm_s->index = 0;
    cr_assert_eq(parsing_15_lfork(asm_s, arr3), false);
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}

Test(parsing_16_aff, tests_parsing_16_aff, .init=redirect, .timeout=1) {
    asm_t *asm_s = malloc(sizeof(asm_t));
    asm_s->buffer = malloc(sizeof(byte_t));
    asm_s->buffer[0] = '\0';
    asm_s->index = 0;
    asm_s->labels = malloc(sizeof(labels_t *) * 2);
    asm_s->labels[0] = malloc(sizeof(labels_t));
    asm_s->labels[0]->name = my_strdup("123", 1);
    asm_s->labels[1] = NULL;
    char *arr1[] = {"USELESS", NULL};
    char *arr2[] = {"USELESS", "USELESS", NULL};
    char *arr3[] = {"aff", "USELESS", NULL};
    cr_assert_eq(parsing_16_aff(asm_s, arr1), false);
    cr_assert_eq(parsing_16_aff(asm_s, arr2), false);
    asm_s->index = -14;
    cr_assert_eq(parsing_16_aff(asm_s, arr3), false);
    asm_s->index = 0;
    free(asm_s->buffer);
    free(asm_s->labels[0]);
    free(asm_s->labels);
    free(asm_s);
}
