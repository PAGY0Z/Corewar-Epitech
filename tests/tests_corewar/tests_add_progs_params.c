/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_add_progs_params
*/

#include "tests_include_header.h"

Test(add_progname, tests_add_progname, .init=redirect, .timeout=1) {
    cr_assert_eq(add_progname(NULL, NULL, -1, 1), false);
    char *argv[] = {NULL};
    params_t *params = malloc(sizeof(params_t));
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = NULL;
    params->progs[1] = NULL;
    cr_assert_eq(add_progname(argv, params, -1, 1), false);
    cr_assert_eq(add_progname(argv, NULL, 15, 1), false);
    cr_assert_eq(add_progname(NULL, params, 15, 1), false);
    cr_assert_eq(add_progname(argv, params, 15, 1), false);
    params->prog_nbr = 0;
    char *argv1[] = {"hello", NULL};
    cr_assert_eq(add_progname(argv1, params, 15, 1), false);
    char *argv2[] = {"hello.cor", NULL};
    params->prog_nbr = 1;
    cr_assert_eq(add_progname(argv2, params, 15, 1), false);
    cr_assert_eq(add_progname(argv2, params, 0, -1), false);
    cr_assert_eq(add_progname(argv2, params, 0, 1), true);
    cr_assert_str_eq(params->progs[0]->prog_name, "hello.cor");
    free(params->progs[0]->prog_name);
    free(params->progs[0]);
    free(params->progs);
    free(params);
}

Test(add_pnbr_name, tests_add_pnbr_name, .init=redirect, .timeout=1) {
    char *argv[] = {"hello.cor", NULL};
    params_t *params = malloc(sizeof(params_t));
    cr_assert_eq(add_pnbr_name(NULL, params, 0, 1), false);
    cr_assert_eq(add_pnbr_name(argv, NULL, 0, 1), false);
    cr_assert_eq(add_pnbr_name(argv, params, -15, 1), false);
    cr_assert_eq(add_pnbr_name(argv, params, -15, 1), false);
    cr_assert_eq(add_pnbr_name(argv, params, 1, 1), false);
    cr_assert_eq(add_pnbr_name(argv, params, 1, 1), false);
    char *argv1[] = {"hi", "shit", "hello.cor", NULL};
    cr_assert_eq(add_pnbr_name(argv1, params, 1, 1), false);
    char *argv2[] = {"-n", "shit", "hello.cor", NULL};
    cr_assert_eq(add_pnbr_name(argv2, params, 1, 1), false);
    char *argv3[] = {"-n", "0123456789", "shit", NULL};
    cr_assert_eq(add_pnbr_name(argv3, params, 1, 1), false);
    char *argv4[] = {"-n", "127", "shit.cor", NULL};
    params->prog_nbr = 0;
    cr_assert_eq(add_pnbr_name(argv4, params, 0, 1), false);
    params->prog_nbr = 1;
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = NULL;
    params->progs[0]->load_address = -1;
    params->progs[0]->prog_nbr = -1;
    params->progs[1] = NULL;
    cr_assert_eq(add_pnbr_name(argv4, params, 0, -1), false);
    cr_assert_eq(add_pnbr_name(argv4, params, 0, 1), true);
    cr_assert_eq(params->progs[0]->prog_nbr, 127);
    cr_assert_str_eq(params->progs[0]->prog_name, "shit.cor");
    free(params->progs[0]->prog_name);
    char *argv5[] = {"-n", "4294967295", "shit.cor", NULL};
    cr_assert_eq(add_pnbr_name(argv5, params, 0, 1), true);
    cr_assert_eq(params->progs[0]->prog_nbr, 1);
    cr_assert_str_eq(params->progs[0]->prog_name, "shit.cor");
}

Test(add_adress_name, tests_add_adress_name, .init=redirect, .timeout=1) {
    char *argv[] = {"hello.cor", NULL};
    params_t *params = malloc(sizeof(params_t));
    cr_assert_eq(add_adress_name(NULL, params, 0, 1), false);
    cr_assert_eq(add_adress_name(argv, NULL, 0, 1), false);
    cr_assert_eq(add_adress_name(argv, params, -15, 1), false);
    cr_assert_eq(add_adress_name(argv, params, -15, 1), false);
    cr_assert_eq(add_adress_name(argv, params, 1, 1), false);
    cr_assert_eq(add_adress_name(argv, params, 1, 1), false);
    char *argv1[] = {"hi", "shit", "hello.cor", NULL};
    cr_assert_eq(add_adress_name(argv1, params, 1, 1), false);
    char *argv2[] = {"-a", "shit", "hello.cor", NULL};
    cr_assert_eq(add_adress_name(argv2, params, 1, 1), false);
    char *argv3[] = {"-a", "0123456789", "shit", NULL};
    cr_assert_eq(add_adress_name(argv3, params, 1, 1), false);
    char *argv4[] = {"-a", "127", "shit.cor", NULL};
    params->prog_nbr = 0;
    cr_assert_eq(add_adress_name(argv4, params, 0, 1), false);
    params->prog_nbr = 1;
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = NULL;
    params->progs[0]->load_address = -1;
    params->progs[0]->prog_nbr = -1;
    params->progs[1] = NULL;
    cr_assert_eq(add_adress_name(argv4, params, 0, -1), false);
    cr_assert_eq(add_adress_name(argv4, params, 0, 1), true);
    cr_assert_eq(params->progs[0]->load_address, 0x127);
    cr_assert_str_eq(params->progs[0]->prog_name, "shit.cor");
    free(params->progs[0]->prog_name);
    char *argv5[] = {"-a", "FFFFFFFF", "shit.cor", NULL};
    cr_assert_eq(add_adress_name(argv5, params, 0, 1), true);
    cr_assert_eq(params->progs[0]->load_address, 1);
    cr_assert_str_eq(params->progs[0]->prog_name, "shit.cor");
}

Test(add_pnbr_adress_name, tests_add_pnbr_adress_name, .init=redirect, .timeout=1) {
    cr_assert_eq(add_pnbr_adress_name(NULL, NULL, -1, 1), false);
    char *argv[] = {NULL};
    params_t *params = malloc(sizeof(params_t));
    cr_assert_eq(add_pnbr_adress_name(NULL, params, 0, 1), false);
    cr_assert_eq(add_pnbr_adress_name(argv, NULL, 0, 1), false);
    cr_assert_eq(add_pnbr_adress_name(argv, params, -1, 1), false);
    cr_assert_eq(add_pnbr_adress_name(argv, params, 0, 1), false);
    char *argv1[] = {"hello","hello","hello","hello","hello", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv1, params, 0, 1), false);
    char *argv2[] = {"-n","hello","hello","hello","hello", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv2, params, 0, 1), false);
    char *argv3[] = {"-n","0123456789","hello","hello","hello", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv3, params, 0, 1), false);
    char *argv4[] = {"-n","0123456789","-a","hello","hello", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv4, params, 0, 1), false);
    char *argv5[] = {"-n","0123456789","-a","127","hello", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv5, params, 0, 1), false);
    char *argv6[] = {"-n","0123456789","-a","127","hello.cor", NULL};
    params->prog_nbr = 0;
    cr_assert_eq(add_pnbr_adress_name(argv6, params, 0, 1), false);
    params->prog_nbr = 1;
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = NULL;
    params->progs[0]->load_address = -1;
    params->progs[0]->prog_nbr = -1;
    params->progs[1] = NULL;
    char *argv7[] = {"-n","4294967295","-a","FFFFFFFF","hello.cor", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv7, params, 0, -1), false);
    cr_assert_eq(add_pnbr_adress_name(argv7, params, 0, 1), true);
    free(params->progs[0]->prog_name);
    char *argv8[] = {"-n","127","-a","A","hello.cor", NULL};
    cr_assert_eq(add_pnbr_adress_name(argv8, params, 0, 1), true);
}

Test(add_adress_pnbr_name, tests_add_adress_pnbr_name, .init=redirect, .timeout=1) {
    cr_assert_eq(add_adress_pnbr_name(NULL, NULL, -1, 1), false);
    char *argv[] = {NULL};
    params_t *params = malloc(sizeof(params_t));
    cr_assert_eq(add_adress_pnbr_name(NULL, params, 0, 1), false);
    cr_assert_eq(add_adress_pnbr_name(argv, NULL, 0, 1), false);
    cr_assert_eq(add_adress_pnbr_name(argv, params, -1, 1), false);
    cr_assert_eq(add_adress_pnbr_name(argv, params, 0, 1), false);
    char *argv1[] = {"hello","hello","hello","hello","hello", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv1, params, 0, 1), false);
    char *argv2[] = {"-a","hello","hello","hello","hello", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv2, params, 0, 1), false);
    char *argv3[] = {"-a","127","hello","hello","hello", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv3, params, 0, 1), false);
    char *argv4[] = {"-a","127","-n","hello","hello", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv4, params, 0, 1), false);
    char *argv5[] = {"-a","127","-n","0123456789","hello", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv5, params, 0, 1), false);
    char *argv6[] = {"-a","127","-n","0123456789","hello.cor", NULL};
    params->prog_nbr = 0;
    cr_assert_eq(add_adress_pnbr_name(argv6, params, 0, 1), false);
    params->prog_nbr = 1;
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = NULL;
    params->progs[0]->load_address = -1;
    params->progs[0]->prog_nbr = -1;
    params->progs[1] = NULL;
    char *argv7[] = {"-a","FFFFFFFF","-n","4294967295","hello.cor", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv7, params, 0, -1), false);
    char *argv8[] = {"-a","FF","-n","17","hello.cor", NULL};
    cr_assert_eq(add_adress_pnbr_name(argv8, params, 0, 1), true);
}
