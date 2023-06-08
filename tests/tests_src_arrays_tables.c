/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_arrays_tables
*/

#include "tests_include_header.h"

Test(add_intarray_to_table, tests_add_intarray_to_table, .init=redirect, .timeout=1) {
    int array[] = {0, 1, 2, 3, 4, -1};
    int *array2[] = {
        array,
        array,
        array,
        NULL,
    };
    cr_assert_null(add_intarray_to_table(NULL, array, MALL_VS));
    cr_assert_null(add_intarray_to_table(array2, NULL, MALL_VS));
    cr_assert_null(add_intarray_to_table(array2, array, MALL_VS0));
    cr_assert_null(add_intarray_to_table(array2, array, MALL_VS1));
    cr_assert_null(add_intarray_to_table(array2, array, MALL_VS2));
    int *array3[] = {
        array,
        array,
        array,
        array,
        NULL,
    };
    int **new_array = add_intarray_to_table(array3, array, MALL_VS);
    cr_assert_not_null(new_array);
    cr_assert_eq(new_array[0][0], 0);
    cr_assert_eq(new_array[0][1], 1);
    cr_assert_eq(new_array[0][2], 2);
    cr_assert_eq(new_array[0][3], 3);
    cr_assert_eq(new_array[0][4], 4);
    cr_assert_eq(new_array[0][5], -1);
    cr_assert_eq(new_array[1][0], 0);
    cr_assert_eq(new_array[1][1], 1);
    cr_assert_eq(new_array[1][2], 2);
    cr_assert_eq(new_array[1][3], 3);
    cr_assert_eq(new_array[1][4], 4);
    cr_assert_eq(new_array[1][5], -1);
    cr_assert_eq(new_array[2][0], 0);
    cr_assert_eq(new_array[2][1], 1);
    cr_assert_eq(new_array[2][2], 2);
    cr_assert_eq(new_array[2][3], 3);
    cr_assert_eq(new_array[2][4], 4);
    cr_assert_eq(new_array[2][5], -1);
    cr_assert_eq(new_array[3][0], 0);
    cr_assert_eq(new_array[3][1], 1);
    cr_assert_eq(new_array[3][2], 2);
    cr_assert_eq(new_array[3][3], 3);
    cr_assert_eq(new_array[3][4], 4);
    cr_assert_eq(new_array[3][5], -1);
    cr_assert_eq(new_array[4][0], 0);
    cr_assert_eq(new_array[4][1], 1);
    cr_assert_eq(new_array[4][2], 2);
    cr_assert_eq(new_array[4][3], 3);
    cr_assert_eq(new_array[4][4], 4);
    cr_assert_eq(new_array[4][5], -1);
    cr_assert_null(new_array[5]);
}

Test(add_str_to_array, tests_add_str_to_array, .init=redirect, .timeout=1) {
    char *array[] = {
        "Hello",
        "World",
        "!",
        NULL,
    };
    char *str = "Double hello World !";
    cr_assert_null(add_str_to_array(NULL, str, MALL_VS));
    cr_assert_null(add_str_to_array(array, NULL, MALL_VS));
    cr_assert_null(add_str_to_array(array, str, MALL_VS0));
    cr_assert_null(add_str_to_array(array, str, MALL_VS1));
    cr_assert_null(add_str_to_array(array, str, MALL_VS2));
    char **new_array = add_str_to_array(array, str, MALL_VS);
    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "World");
    cr_assert_str_eq(new_array[2], "!");
    cr_assert_str_eq(new_array[3], "Double hello World !");
    cr_assert_null(new_array[4]);
}

Test(convert_array_table, tests_convert_array_table, .init=redirect, .timeout=1) {
    char *array[] = {
        "Hello",
        "World",
        "!",
        NULL,
    };
    cr_assert_null(convert_array_table(NULL, MALL_VS));
    cr_assert_null(convert_array_table(array, MALL_VS0));
    cr_assert_null(convert_array_table(array, MALL_VS1));
    int **table = convert_array_table(array, MALL_VS);
    cr_assert_eq(table[0][0], 'H');
    cr_assert_eq(table[0][1], 'e');
    cr_assert_eq(table[0][2], 'l');
    cr_assert_eq(table[0][3], 'l');
    cr_assert_eq(table[0][4], 'o');
    cr_assert_eq(table[0][5], -1);
    cr_assert_eq(table[1][0], 'W');
    cr_assert_eq(table[1][1], 'o');
    cr_assert_eq(table[1][2], 'r');
    cr_assert_eq(table[1][3], 'l');
    cr_assert_eq(table[1][4], 'd');
    cr_assert_eq(table[1][5], -1);
    cr_assert_eq(table[2][0], '!');
    cr_assert_eq(table[2][1], -1);
    cr_assert_null(table[3]);
}

Test(convert_table_array, tests_convert_table_array, .init=redirect, .timeout=1) {
    int array[] = {'H', 'e', 'l', 'l', 'o', -1};
    int *array2[] = {
        array,
        array,
        array,
        NULL,
    };
    cr_assert_null(convert_table_array(NULL, MALL_VS));
    cr_assert_null(convert_table_array(array2, MALL_VS0));
    cr_assert_null(convert_table_array(array2, MALL_VS1));
    char **new_array = convert_table_array(array2, MALL_VS);
    cr_assert_str_eq(new_array[0], "Hello");
    cr_assert_str_eq(new_array[1], "Hello");
    cr_assert_str_eq(new_array[2], "Hello");
    cr_assert_null(new_array[3]);
}

Test(create_array, tests_create_array, .init=redirect, .timeout=1) {
    cr_assert_null(create_array(-1, 10, MALL_VS));
    cr_assert_null(create_array(10, -1, MALL_VS));
    cr_assert_null(create_array(10, 10, MALL_VS0));
    cr_assert_null(create_array(10, 10, MALL_VS1));
    char **array = create_array(3, 3, MALL_VS);
    cr_assert_str_eq(array[0], "   ");
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
}

Test(create_table, tests_create_table, .init=redirect, .timeout=1) {
    cr_assert_null(create_table(-1, 10,MALL_VS));
    cr_assert_null(create_table(10, -1,MALL_VS));
    cr_assert_null(create_table(10, 10, MALL_VS0));
    cr_assert_null(create_table(10, 10, MALL_VS1));
    int **table = create_table(3, 3,MALL_VS);
    cr_assert_eq(table[0][0], 0);
    cr_assert_eq(table[0][1], 0);
    cr_assert_eq(table[0][2], 0);
    cr_assert_eq(table[0][3], -1);
    cr_assert_eq(table[1][0], 0);
    cr_assert_eq(table[1][1], 0);
    cr_assert_eq(table[1][2], 0);
    cr_assert_eq(table[1][3], -1);
    cr_assert_eq(table[2][0], 0);
    cr_assert_eq(table[2][1], 0);
    cr_assert_eq(table[2][2], 0);
    cr_assert_eq(table[2][3], -1);
    cr_assert_null(table[3]);
}

Test(fill_array, tests_fill_array, .init=redirect, .timeout=1) {
    char **array = create_array(3, 3, MALL_VS);
    fill_array(NULL, 'c');
    fill_array(array, 'c');
    cr_assert_str_eq(array[0], "ccc");
    cr_assert_str_eq(array[1], "ccc");
    cr_assert_str_eq(array[2], "ccc");
    cr_assert_null(array[3]);
}

Test(fill_table, tests_fill_table, .init=redirect, .timeout=1) {
    int **table = create_table(3, 3, MALL_VS);
    fill_table(NULL, 'c');
    fill_table(table, 'c');
    cr_assert_eq(table[0][0], 'c');
    cr_assert_eq(table[0][1], 'c');
    cr_assert_eq(table[0][2], 'c');
    cr_assert_eq(table[0][3], -1);
    cr_assert_eq(table[1][0], 'c');
    cr_assert_eq(table[1][1], 'c');
    cr_assert_eq(table[1][2], 'c');
    cr_assert_eq(table[1][3], -1);
    cr_assert_eq(table[2][0], 'c');
    cr_assert_eq(table[2][1], 'c');
    cr_assert_eq(table[2][2], 'c');
    cr_assert_eq(table[2][3], -1);
    cr_assert_null(table[3]);
}

Test(replace_str_in_array, tests_replace_str_in_array, .init=redirect, .timeout=1) {
    char **array = create_array(3, 3,MALL_VS);
    char *str = "Hello World !";
    replace_str_in_array(NULL, str, 0, MALL_VS);
    cr_assert_str_eq(array[0], "   ");
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, NULL, 0, MALL_VS);
    cr_assert_str_eq(array[0], "   ");
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, str, -15, MALL_VS);
    cr_assert_str_eq(array[0], "   ");
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, str, 100, MALL_VS);
    cr_assert_str_eq(array[0], "   ");
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, str, 0, MALL_VS);
    cr_assert_str_eq(array[0], str);
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, str, 0, MALL_VS0);
    cr_assert_str_eq(array[0], str);
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
    replace_str_in_array(array, str, 0, MALL_VS1);
    cr_assert_str_eq(array[0], str);
    cr_assert_str_eq(array[1], "   ");
    cr_assert_str_eq(array[2], "   ");
    cr_assert_null(array[3]);
}
