/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_lens
*/

#include "tests_include_header.h"

Test(my_array_len, tests_my_array_len, .init=redirect, .timeout=1) {
    char *array[] = {"Hello", "World", "!", NULL};
    cr_assert_eq(my_array_len(NULL), -1);
    cr_assert_eq(my_array_len(array), 3);
}

Test(my_array_strlen, tests_my_array_strlen, .init=redirect, .timeout=1) {
    char *array[] = {"Hello", "World", "!", NULL};
    cr_assert_eq(my_array_strlen(NULL), -1);
    cr_assert_eq(my_array_strlen(array), 11);
}

Test(my_intarray_len, tests_my_intarray_len, .init=redirect, .timeout=1) {
    int array[] = {0, 1, 2, 3, 4, -1};
    cr_assert_eq(my_intarray_len(NULL), -1);
    cr_assert_eq(my_intarray_len(array), 5);
}

Test(my_len_nbr, tests_my_len_nbr, .init=redirect, .timeout=1) {
    cr_assert_eq(my_len_nbr(15), 2);
    cr_assert_eq(my_len_nbr(-15), 3);
    cr_assert_eq(my_len_nbr(0), 1);
}

Test(my_strlen_sepa, tests_my_strlen_sepa, .init=redirect, .timeout=1) {
    cr_assert_eq(my_strlen_sepa(NULL, "abcd"), -1);
    cr_assert_eq(my_strlen_sepa("Hello World !", NULL), -1);
    cr_assert_eq(my_strlen_sepa("Hello World !", " "), 5);
    cr_assert_eq(my_strlen_sepa("Hello World !", "#"), 13);
}

Test(my_strlen, tests_my_strlen, .init=redirect, .timeout=1) {
    cr_assert_eq(my_strlen(NULL), -1);
    cr_assert_eq(my_strlen("Hello World !"), 13);
}

Test(my_table_len, tests_my_table_len, .init=redirect, .timeout=1) {
    int **table = malloc(sizeof(int *) * 3);
    table[0] = malloc(sizeof(int) * 3);
    table[1] = malloc(sizeof(int) * 3);
    table[2] = NULL;
    cr_assert_eq(my_table_len(NULL), -1);
    cr_assert_eq(my_table_len(table), 2);
    free(table[0]);
    free(table[1]);
    free(table);
}