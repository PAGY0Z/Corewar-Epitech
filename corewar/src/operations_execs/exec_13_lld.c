/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_13_lld
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_13_lld.c
/// \brief Contains the exec_13_lld function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void exec_13_lld(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the lld instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_13_lld(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    byte_t by_p = champion->params[1];
    int pos = 2; int val1 = 0; int idx_reg = 0;
    int args[] = {get_type_p1(by_p), REG};
    val1 = get_value(args[0], pos, champion, global);
    pos += get_len(args[0]);
    idx_reg = (champion->params[pos] & 0xff) - 1;
    val1 = get_4b_mem(global, champion->pc + val1);
    champion->regs[idx_reg] = val1;
    if (val1 == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc = (get_arena_adress(champion->pc + 2 + get_len(args[0]) + 1));
}
