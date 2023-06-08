/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_14_lldi
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_14_lldi.c
/// \brief Contains the exec_14_lldi function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void exec_14_lldi(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the lldi instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_14_lldi(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    byte_t by_p = champion->params[1];
    int pos = 2; int val1 = 0; int val2 = 0;
    int idx_reg = 0; int val3 = 0;
    int args[] = {get_type_p1(by_p), get_type_p2(by_p), REG};
    val1 = get_value_mod(args[0], pos, champion, global);
    pos += get_len_mod(args[0]);
    val2 = get_value_mod(args[1], pos, champion, global);
    pos += get_len_mod(args[1]);
    val3 = get_2b_mem(global, champion->pc + val1) + val2;
    val3 = get_4b_mem(global, champion->pc + val3);
    idx_reg = (champion->params[pos] & 0xff) - 1;
    champion->regs[idx_reg] = val3;
    if (val3 == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc = (get_arena_adress(champion->pc + 2 + get_len_mod(args[0]) + \
        get_len_mod(args[1]) + 1));
}
