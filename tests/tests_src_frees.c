/*
** EPITECH PROJECT, 2023
** PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
** File description:
** tests_src_frees
*/

#include "tests_include_header.h"

Test(my_free, tests_my_free, .init=redirect, .timeout=1) {
    char *str = NULL;
    my_free(NULL);
    my_free(str);
    str = malloc(sizeof(char) * 10);
    my_free(str);
}

Test(free_array, tests_free_array, .init=redirect, .timeout=1) {
    char **array = NULL;
    free_array(NULL);
    free_array(array);
    array = malloc(sizeof(char *) * 3);
    array[0] = malloc(sizeof(char) * 10);
    array[1] = malloc(sizeof(char) * 10);
    array[2] = NULL;
    free_array(array);
}

Test(free_table, tests_free_table, .init=redirect, .timeout=1) {
    int **table = NULL;
    free_table(NULL);
    free_table(table);
    table = malloc(sizeof(int *) * 3);
    table[0] = malloc(sizeof(int) * 3);
    table[1] = malloc(sizeof(int) * 3);
    table[2] = NULL;
    free_table(table);
}

Test(freen_array, tests_freen_array, .init=redirect, .timeout=1) {
    char **array = NULL;
    array = malloc(sizeof(char *) * 3);
    array[0] = malloc(sizeof(char) * 10);
    array[1] = malloc(sizeof(char) * 10);
    array[2] = NULL;
    freen_array(NULL, 0);
    freen_array(array, -1);
    freen_array(array, 1);
    array = malloc(sizeof(char *) * 3);
    array[0] = malloc(sizeof(char) * 10);
    array[1] = malloc(sizeof(char) * 10);
    array[2] = NULL;
    freen_array(array, 100);
}

Test(freen_table, tests_freen_table, .init=redirect, .timeout=1) {
    int **table = NULL;
    table = malloc(sizeof(int *) * 3);
    table[0] = malloc(sizeof(int) * 10);
    table[1] = malloc(sizeof(int) * 10);
    table[2] = NULL;
    freen_table(NULL, 0);
    freen_table(table, -1);
    freen_table(table, 1);
    table = malloc(sizeof(int *) * 3);
    table[0] = malloc(sizeof(int) * 10);
    table[1] = malloc(sizeof(int) * 10);
    table[2] = NULL;
    freen_table(table, 100);
}
