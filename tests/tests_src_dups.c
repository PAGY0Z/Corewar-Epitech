/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_dups
*/

#include "tests_include_header.h"

Test(my_arraydup, tests_my_arraydup, .init=redirect, .timeout=1) {
    char *array[] = {
        "Hello",
        "World",
        "!",
        NULL
    };
    cr_assert_null(my_arraydup(NULL, MALL_VS));
    cr_assert_null(my_arraydup(array, MALL_VS0));
    cr_assert_null(my_arraydup(array, MALL_VS1));
    char **new_array = my_arraydup(array, MALL_VS);
    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "World");
    cr_assert_str_eq(new_array[2], "!");
    cr_assert_null(new_array[3]);
}

Test(my_intarraydup, tests_my_intarraydup, .init=redirect, .timeout=1) {
    int array[] = {
        1,
        2,
        3,
        -1
    };
    cr_assert_null(my_intarraydup(NULL, 1));
    cr_assert_null(my_intarraydup(array, -1));
    int *new_array = my_intarraydup(array, 1);
    cr_assert_eq(new_array[0], 1);
    cr_assert_eq(new_array[1], 2);
    cr_assert_eq(new_array[2], 3);
    cr_assert_eq(new_array[3], -1);
}

Test(my_intarrayndup, tests_my_intarrayndup, .init=redirect, .timeout=1) {
    int array[] = {
        1,
        2,
        3,
        -1
    };
    cr_assert_null(my_intarrayndup(NULL, 1, 1));
    cr_assert_null(my_intarrayndup(array, -1, 1));
    cr_assert_null(my_intarrayndup(array, 1, -1));
    int *new_array = my_intarrayndup(array, 2, 1);
    cr_assert_eq(new_array[0], 1);
    cr_assert_eq(new_array[1], 2);
    cr_assert_eq(new_array[2], -1);
    int *new_array2 = my_intarrayndup(array, 15, 1);
    cr_assert_eq(new_array2[0], 1);
    cr_assert_eq(new_array2[1], 2);
    cr_assert_eq(new_array2[2], 3);
    cr_assert_eq(new_array2[3], -1);
}

Test(my_strdup, tests_my_strdup, .init=redirect, .timeout=1) {
    cr_assert_null(my_strdup(NULL, 1));
    cr_assert_null(my_strdup("Hello", -1));
    cr_assert_str_empty(my_strdup("", 1));
    char *str1 = my_strdup("Hello World!", 1);
    cr_assert_str_eq(str1, "Hello World!");
}

Test(my_strndup, tests_my_strndup, .init=redirect, .timeout=1) {
    cr_assert_null(my_strndup(NULL, 1, 1));
    cr_assert_null(my_strndup("Hello", -1, 1));
    char *str1 = my_strndup("Hello", 3, 1);
    cr_assert_str_eq(str1, "Hel");
    char *str2 = my_strndup("Hello", 15, 1);
    cr_assert_str_eq(str2, "Hello");
    cr_assert_null(my_strndup("Hello", 15, -1));
}

Test(my_tabledup, tests_my_tabledup, .init=redirect, .timeout=1) {
    int *array[] = {
        (int []){1, 2, 3, -1},
        (int []){4, 5, 6, -1},
        (int []){7, 8, 9, -1},
        NULL
    };
    cr_assert_null(my_tabledup(NULL,MALL_VS));
    cr_assert_null(my_tabledup(array, MALL_VS0));
    cr_assert_null(my_tabledup(array, MALL_VS1));
    int **new_array = my_tabledup(array,MALL_VS);
    cr_assert_eq(new_array[0][0], 1);
    cr_assert_eq(new_array[0][1], 2);
    cr_assert_eq(new_array[0][2], 3);
    cr_assert_eq(new_array[0][3], -1);
    cr_assert_eq(new_array[1][0], 4);
    cr_assert_eq(new_array[1][1], 5);
    cr_assert_eq(new_array[1][2], 6);
    cr_assert_eq(new_array[1][3], -1);
    cr_assert_eq(new_array[2][0], 7);
    cr_assert_eq(new_array[2][1], 8);
    cr_assert_eq(new_array[2][2], 9);
    cr_assert_eq(new_array[2][3], -1);
    cr_assert_null(new_array[3]);
}
