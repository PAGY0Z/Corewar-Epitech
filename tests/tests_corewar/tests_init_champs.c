/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_init_champs
*/

#include "tests_include_header.h"

Test(init_default_values, tests_init_default_values, .init=redirect, .timeout=1) {
    params_progs_t *params = malloc(sizeof(params_progs_t));
    champ_t *champ = malloc(sizeof(champ_t));
    champ->params = malloc(sizeof(byte_t) * 14);
    champ->regs = malloc(sizeof(int) * REG_NUMBER);
    params->load_address = 120;
    params->prog_nbr = 15;
    init_default_values(params, champ);
    cr_assert_eq(champ->params[0], 0);
    cr_assert_eq(champ->params[1], 0);
    cr_assert_eq(champ->params[2], 0);
    cr_assert_eq(champ->params[3], 0);
    cr_assert_eq(champ->params[4], 0);
    cr_assert_eq(champ->params[5], 0);
    cr_assert_eq(champ->params[6], 0);
    cr_assert_eq(champ->params[7], 0);
    cr_assert_eq(champ->params[8], 0);
    cr_assert_eq(champ->params[9], 0);
    cr_assert_eq(champ->params[10], 0);
    cr_assert_eq(champ->params[11], 0);
    cr_assert_eq(champ->params[12], 0);
    cr_assert_eq(champ->params[13], 0);
    cr_assert_eq(champ->regs[0], 15);
    cr_assert_eq(champ->regs[1], 0);
    cr_assert_eq(champ->regs[2], 0);
    cr_assert_eq(champ->regs[3], 0);
    cr_assert_eq(champ->regs[4], 0);
    cr_assert_eq(champ->regs[5], 0);
    cr_assert_eq(champ->regs[6], 0);
    cr_assert_eq(champ->regs[7], 0);
    cr_assert_eq(champ->regs[8], 0);
    cr_assert_eq(champ->regs[9], 0);
    cr_assert_eq(champ->regs[10], 0);
    cr_assert_eq(champ->regs[11], 0);
    cr_assert_eq(champ->regs[12], 0);
    cr_assert_eq(champ->regs[13], 0);
    cr_assert_eq(champ->regs[14], 0);
    cr_assert_eq(champ->regs[15], 0);
    cr_assert_eq(champ->pc, 120);
}

Test(init_champion, tests_init_champion, .init=redirect, .timeout=1) {
    params_progs_t *params = malloc(sizeof(params_progs_t));
    params->load_address = 120;
    params->prog_nbr = 15;
    params->prog_name = my_strdup("tests/asm_reference_binaries/champions/abel.cor", 1);
    champ_t *champ = init_champion(params, MALL_VS);
    cr_assert_eq(champ->params[0], 0);
    cr_assert_eq(champ->params[1], 0);
    cr_assert_eq(champ->params[2], 0);
    cr_assert_eq(champ->params[3], 0);
    cr_assert_eq(champ->params[4], 0);
    cr_assert_eq(champ->params[5], 0);
    cr_assert_eq(champ->params[6], 0);
    cr_assert_eq(champ->params[7], 0);
    cr_assert_eq(champ->params[8], 0);
    cr_assert_eq(champ->params[9], 0);
    cr_assert_eq(champ->params[10], 0);
    cr_assert_eq(champ->params[11], 0);
    cr_assert_eq(champ->params[12], 0);
    cr_assert_eq(champ->params[13], 0);
    cr_assert_eq(champ->regs[0], 15);
    cr_assert_eq(champ->regs[1], 0);
    cr_assert_eq(champ->regs[2], 0);
    cr_assert_eq(champ->regs[3], 0);
    cr_assert_eq(champ->regs[4], 0);
    cr_assert_eq(champ->regs[5], 0);
    cr_assert_eq(champ->regs[6], 0);
    cr_assert_eq(champ->regs[7], 0);
    cr_assert_eq(champ->regs[8], 0);
    cr_assert_eq(champ->regs[9], 0);
    cr_assert_eq(champ->regs[10], 0);
    cr_assert_eq(champ->regs[11], 0);
    cr_assert_eq(champ->regs[12], 0);
    cr_assert_eq(champ->regs[13], 0);
    cr_assert_eq(champ->regs[14], 0);
    cr_assert_eq(champ->regs[15], 0);
    cr_assert_eq(champ->pc, 120);
    cr_assert_str_eq(champ->comment, "L'amer noir.");
    cr_assert_str_eq(champ->name, "Abel");
    cr_assert_null(init_champion(params, MALL_VS0));
    cr_assert_null(init_champion(params, MALL_VS1));
    cr_assert_null(init_champion(params, MALL_VS2));
    cr_assert_null(init_champion(params, MALL_VS3));
    cr_assert_null(init_champion(params, MALL_VS4));
    cr_assert_null(init_champion(NULL, MALL_VS0));
    free(params->prog_name);
    params->prog_name = my_strdup("tests/tests_files/filled_readable", 1);
    cr_assert_null(init_champion(params, MALL_VS4));
}