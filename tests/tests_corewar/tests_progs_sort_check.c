/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_progs_sort_check
*/

#include "tests_include_header.h"

Test(swapprogs, tests_swapprogs, .init=redirect, .timeout=1) {
    swapprogs(NULL, 0, 0);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 3);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->prog_name = malloc(sizeof(char) * 2);
    params_progs[0]->prog_name[0] = 'a';
    params_progs[0]->prog_name[1] = '\0';
    params_progs[0]->prog_nbr = 1;
    params_progs[1] = malloc(sizeof(params_progs_t));
    params_progs[1]->prog_name = malloc(sizeof(char) * 2);
    params_progs[1]->prog_name[0] = 'b';
    params_progs[1]->prog_name[1] = '\0';
    params_progs[1]->prog_nbr = 0;
    params_progs[2] = NULL;
    swapprogs(params_progs, -1, 0);
    cr_assert_str_eq(params_progs[0]->prog_name, "a");
    cr_assert_str_eq(params_progs[1]->prog_name, "b");
    swapprogs(params_progs, 0, -1);
    cr_assert_str_eq(params_progs[0]->prog_name, "a");
    cr_assert_str_eq(params_progs[1]->prog_name, "b");
    swapprogs(params_progs, 2, 1);
    cr_assert_str_eq(params_progs[0]->prog_name, "a");
    cr_assert_str_eq(params_progs[1]->prog_name, "b");
    swapprogs(params_progs, 1, 2);
    cr_assert_str_eq(params_progs[0]->prog_name, "a");
    cr_assert_str_eq(params_progs[1]->prog_name, "b");
}

Test(sort_progs, tests_sort_progs, .init=redirect, .timeout=1) {
    sort_progs(NULL);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 10);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->prog_name = malloc(sizeof(char) * 2);
    params_progs[0]->prog_nbr = 7;
    params_progs[0]->prog_name[0] = 'a' + params_progs[0]->prog_nbr;
    params_progs[0]->prog_name[1] = '\0';
    params_progs[1] = malloc(sizeof(params_progs_t));
    params_progs[1]->prog_name = malloc(sizeof(char) * 2);
    params_progs[1]->prog_nbr = 6;
    params_progs[1]->prog_name[0] = 'a' + params_progs[1]->prog_nbr;
    params_progs[1]->prog_name[1] = '\0';
    params_progs[2] = malloc(sizeof(params_progs_t));
    params_progs[2]->prog_name = malloc(sizeof(char) * 2);
    params_progs[2]->prog_nbr = 4;
    params_progs[2]->prog_name[0] = 'a' + params_progs[2]->prog_nbr;
    params_progs[2]->prog_name[1] = '\0';
    params_progs[3] = malloc(sizeof(params_progs_t));
    params_progs[3]->prog_name = malloc(sizeof(char) * 2);
    params_progs[3]->prog_nbr = 0;
    params_progs[3]->prog_name[0] = 'a' + params_progs[3]->prog_nbr;
    params_progs[3]->prog_name[1] = '\0';
    params_progs[4] = malloc(sizeof(params_progs_t));
    params_progs[4]->prog_name = malloc(sizeof(char) * 2);
    params_progs[4]->prog_nbr = 5;
    params_progs[4]->prog_name[0] = 'a' + params_progs[4]->prog_nbr;
    params_progs[4]->prog_name[1] = '\0';
    params_progs[5] = malloc(sizeof(params_progs_t));
    params_progs[5]->prog_name = malloc(sizeof(char) * 2);
    params_progs[5]->prog_nbr = 8;
    params_progs[5]->prog_name[0] = 'a' + params_progs[5]->prog_nbr;
    params_progs[5]->prog_name[1] = '\0';
    params_progs[6] = malloc(sizeof(params_progs_t));
    params_progs[6]->prog_name = malloc(sizeof(char) * 2);
    params_progs[6]->prog_nbr = 1;
    params_progs[6]->prog_name[0] = 'a' + params_progs[6]->prog_nbr;
    params_progs[6]->prog_name[1] = '\0';
    params_progs[7] = malloc(sizeof(params_progs_t));
    params_progs[7]->prog_name = malloc(sizeof(char) * 2);
    params_progs[7]->prog_nbr = 3;
    params_progs[7]->prog_name[0] = 'a' + params_progs[7]->prog_nbr;
    params_progs[7]->prog_name[1] = '\0';
    params_progs[8] = malloc(sizeof(params_progs_t));
    params_progs[8]->prog_name = malloc(sizeof(char) * 2);
    params_progs[8]->prog_nbr = 2;
    params_progs[8]->prog_name[0] = 'a' + params_progs[8]->prog_nbr;
    params_progs[8]->prog_name[1] = '\0';
    params_progs[9] = NULL;
    sort_progs(params_progs);
    cr_assert_str_eq(params_progs[0]->prog_name, "a");
    cr_assert_eq(params_progs[0]->prog_nbr, 0);
    cr_assert_str_eq(params_progs[1]->prog_name, "b");
    cr_assert_eq(params_progs[1]->prog_nbr, 1);
    cr_assert_str_eq(params_progs[2]->prog_name, "c");
    cr_assert_eq(params_progs[2]->prog_nbr, 2);
    cr_assert_str_eq(params_progs[3]->prog_name, "d");
    cr_assert_eq(params_progs[3]->prog_nbr, 3);
    cr_assert_str_eq(params_progs[4]->prog_name, "e");
    cr_assert_eq(params_progs[4]->prog_nbr, 4);
    cr_assert_str_eq(params_progs[5]->prog_name, "f");
    cr_assert_eq(params_progs[5]->prog_nbr, 5);
    cr_assert_str_eq(params_progs[6]->prog_name, "g");
    cr_assert_eq(params_progs[6]->prog_nbr, 6);
    cr_assert_str_eq(params_progs[7]->prog_name, "h");
    cr_assert_eq(params_progs[7]->prog_nbr, 7);
    cr_assert_str_eq(params_progs[8]->prog_name, "i");
    cr_assert_eq(params_progs[8]->prog_nbr, 8);
    cr_assert_eq(params_progs[9], NULL);
    free_params_progs(params_progs);
}
