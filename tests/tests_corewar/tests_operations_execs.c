/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_operations_execs
*/

#include "tests_include_header.h"

Test(exec_02_ld, tests_exec_02_ld, .init=redirect, .timeout=1) {
    corewar_t *corewar = malloc(sizeof(corewar_t));
    corewar->arena = malloc(sizeof(byte_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        corewar->arena[i] = 0;
    champ_t *champ = malloc(sizeof(champ_t));
    champ->regs = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        champ->regs[i] = 0;
    champ->params = malloc(sizeof(byte_t) * 14);
    for (int i = 0; i < 14; i++)
        champ->params[i] = 0;

    champ->pc = -1;
    exec_03_st(corewar, champ);

    champ->pc = 0;
    champ->params[0] = 0x02;
    champ->params[1] = 0b10010000;

    





    champ->params[1] = 0b11010000;
}

Test(exec_03_st, tests_exec_03_st, .init=redirect, .timeout=1) {
    corewar_t *corewar = malloc(sizeof(corewar_t));
    corewar->arena = malloc(sizeof(byte_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        corewar->arena[i] = 0;
    champ_t *champ = malloc(sizeof(champ_t));
    champ->pc = 0;
    champ->regs = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        champ->regs[i] = 0;
    champ->regs[0] = 1000;
    champ->params = malloc(sizeof(byte_t) * 14);
    champ->params[0] = 0x03;
    champ->params[1] = 0b01010000;
    champ->params[2] = 0x01;
    champ->params[3] = 0x02;
    exec_03_st(corewar, champ);
    cr_assert_eq(champ->pc, 4);
    cr_assert_eq(champ->regs[0], 1000);
    cr_assert_eq(champ->regs[1], 1000);

    champ->pc = 0;
    champ->params[1] = 0b01110000;
    champ->params[2] = 0x01;
    champ->params[3] = 0x01;
    champ->params[4] = 0x02;
    exec_03_st(corewar, champ);
    cr_assert_eq(champ->pc, 5);
    cr_assert_eq(champ->regs[0], 1000);
    cr_assert_eq(champ->regs[1], 1000);
    cr_assert_eq(corewar->arena[258], 0x00);
    cr_assert_eq(corewar->arena[259], 0x00);
    cr_assert_eq(corewar->arena[260] & 0xff, 0x03);
    cr_assert_eq(corewar->arena[261] & 0xff, 0xe8);
    champ->pc = -1;
    exec_03_st(corewar, champ);
}

Test(exec_04_add, tests_exec_04_add, .init=redirect, .timeout=1) {
    champ_t *champion = malloc(sizeof(champ_t));
    champion->pc = 0;
    champion->regs = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        champion->regs[i] = 0;
    champion->params = malloc(sizeof(byte_t) * 14);
    champion->params[0] = 0x04;
    champion->params[1] = 0x54;
    champion->params[2] = 0x01;
    champion->params[3] = 0x02;
    champion->params[4] = 0x03;
    champion->regs[0] = 10;
    champion->regs[1] = 20;
    champion->regs[2] = 0;
    exec_04_add(NULL, champion);
    cr_assert_eq(champion->regs[2], 30);
    cr_assert_eq(champion->pc, 5);
    champion->pc = -1;
    exec_04_add(NULL, champion);
    cr_assert_eq(champion->pc, -1);
    free(champion->regs);
    free(champion->params);
    free(champion);
}

Test(exec_05_sub, tests_exec_05_sub, .init=redirect, .timeout=1) {
    champ_t *champion = malloc(sizeof(champ_t));
    champion->pc = 0;
    champion->regs = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        champion->regs[i] = 0;
    champion->params = malloc(sizeof(byte_t) * 14);
    champion->params[0] = 0x04;
    champion->params[1] = 0x54;
    champion->params[2] = 0x01;
    champion->params[3] = 0x02;
    champion->params[4] = 0x03;
    champion->regs[0] = 10;
    champion->regs[1] = 20;
    champion->regs[2] = 0;
    exec_05_sub(NULL, champion);
    cr_assert_eq(champion->regs[2], -10);
    cr_assert_eq(champion->pc, 5);
    champion->pc = -1;
    exec_05_sub(NULL, champion);
    cr_assert_eq(champion->pc, -1);
    free(champion->regs);
    free(champion->params);
    free(champion);
}

Test(exec_16_aff, tests_exec_16_aff, .init=redirect, .timeout=1) {
    champ_t *champion = malloc(sizeof(champ_t));
    champion->pc = 0;
    champion->regs = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        champion->regs[i] = 0;
    champion->regs[0] = 'a';
    champion->params = malloc(sizeof(byte_t) * 14);
    champion->params[0] = 0x04;
    champion->params[1] = 0b01000000;
    champion->params[2] = 0x01;

    exec_16_aff(NULL, champion);
    cr_assert_eq(champion->pc, 3);

    champion->pc = 0;
    champion->regs[0] = 1400;
    exec_16_aff(NULL, champion);
    cr_assert_eq(champion->pc, 3);

    cr_assert_stdout_eq_str("ax");

    champion->pc = -1;
    exec_16_aff(NULL, champion);

    free(champion->params);
    free(champion->regs);
    free(champion);
}
