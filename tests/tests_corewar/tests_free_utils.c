/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_free_utils
*/

#include "tests_include_header.h"

Test(free_champs, tests_free_champs, .init=redirect, .timeout=1) {
    free_champs(NULL);
    champ_t **champs = malloc(sizeof(champ_t *) * 2);
    champs = malloc(sizeof(champ_t *) * 2);
    champs[0] = malloc(sizeof(champ_t));
    champs[0]->name = malloc(sizeof(char) * 2);
    champs[0]->name[0] = 'a';
    champs[0]->name[1] = '\0';
    champs[0]->comment = malloc(sizeof(char) * 2);
    champs[0]->comment[0] = 'a';
    champs[0]->comment[1] = '\0';
    champs[0]->regs = malloc(sizeof(int) * 2);
    champs[0]->regs[0] = 1;
    champs[0]->regs[1] = 0;
    champs[0]->params = malloc(sizeof(char) * 2);
    champs[0]->params[0] = 'a';
    champs[0]->params[1] = '\0';
    champs[1] = NULL;
    free_champs(champs);
}

Test(freen_champs, tests_freen_champs, .init=redirect, .timeout=1) {
    freen_champs(NULL, 0);
    champ_t **champs = malloc(sizeof(champ_t *) * 2);
    freen_champs(champs, 0);
    champs = malloc(sizeof(champ_t *) * 3);
    champs[0] = malloc(sizeof(champ_t));
    champs[0]->name = malloc(sizeof(char) * 2);
    champs[0]->name[0] = 'a';
    champs[0]->name[1] = '\0';
    champs[0]->comment = malloc(sizeof(char) * 2);
    champs[0]->comment[0] = 'a';
    champs[0]->comment[1] = '\0';
    champs[0]->regs = malloc(sizeof(int) * 2);
    champs[0]->regs[0] = 1;
    champs[0]->regs[1] = 0;
    champs[0]->params = malloc(sizeof(char) * 2);
    champs[0]->params[0] = 'a';
    champs[0]->params[1] = '\0';
    champs[1] = NULL;
    freen_champs(champs, 1);
}

Test(free_params_progs, tests_free_params_progs, .init=redirect, .timeout=1) {
    free_params_progs(NULL);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 2);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->prog_name = malloc(sizeof(char) * 2);
    params_progs[0]->prog_name[0] = 'a';
    params_progs[0]->prog_name[1] = '\0';
    params_progs[1] = NULL;
    free_params_progs(params_progs);
}

Test(free_params, tests_free_params, .init=redirect, .timeout=1) {
    free_params(NULL);
    params_t *params = malloc(sizeof(params_t));
    params->progs = malloc(sizeof(params_progs_t *) * 2);
    params->progs[0] = malloc(sizeof(params_progs_t));
    params->progs[0]->prog_name = malloc(sizeof(char) * 2);
    params->progs[0]->prog_name[0] = 'a';
    params->progs[0]->prog_name[1] = '\0';
    params->progs[1] = NULL;
    free_params(params);
}

Test(freen_params_progs, tests_freen_params_progs, .init=redirect, .timeout=1) {
    freen_params_progs(NULL, 0);
    params_progs_t **params_progs = malloc(sizeof(params_progs_t *) * 3);
    params_progs[0] = malloc(sizeof(params_progs_t));
    params_progs[0]->prog_name = malloc(sizeof(char) * 2);
    params_progs[0]->prog_name[0] = 'a';
    params_progs[0]->prog_name[1] = '\0';
    params_progs[1] = malloc(sizeof(params_progs_t));
    params_progs[1]->prog_name = malloc(sizeof(char) * 2);
    params_progs[1]->prog_name[0] = 'a';
    params_progs[1]->prog_name[1] = '\0';
    params_progs[2] = NULL;
    freen_params_progs(params_progs, 1000);
    params_progs_t **params_progs2 = malloc(sizeof(params_progs_t *) * 3);
    freen_params_progs(params_progs2, 0);
}

Test(free_corewar, tests_free_corewar, .init=redirect, .timeout=1) {
    corewar_t *corewar = malloc(sizeof(corewar_t));
    corewar->arena = malloc(sizeof(char) * 2);
    corewar->arena[0] = 'a';
    corewar->arena[1] = '\0';
    corewar->champ = malloc(sizeof(champ_t *) * 2);
    corewar->champ[0] = malloc(sizeof(champ_t));
    corewar->champ[0]->name = malloc(sizeof(char) * 2);
    corewar->champ[0]->name[0] = 'a';
    corewar->champ[0]->name[1] = '\0';
    corewar->champ[0]->comment = malloc(sizeof(char) * 2);
    corewar->champ[0]->comment[0] = 'a';
    corewar->champ[0]->comment[1] = '\0';
    corewar->champ[0]->regs = malloc(sizeof(int) * 2);
    corewar->champ[0]->regs[0] = 1;
    corewar->champ[0]->regs[1] = 0;
    corewar->champ[0]->params = malloc(sizeof(char) * 2);
    corewar->champ[0]->params[0] = 'a';
    corewar->champ[0]->params[1] = '\0';
    corewar->champ[1] = NULL;
    free_corewar(corewar);
    free_corewar(NULL);
}