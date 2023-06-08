/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_06_and
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_06_and.c
/// \brief Contains the exec_06_and functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void exec_06_and(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the and instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_06_and(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    byte_t by_p = champion->params[1];
    int pos = 2; int val1 = 0; int val2 = 0;
    int index_reg = 0; int res = 0;
    int args[] = {get_type_p1(by_p), get_type_p2(by_p), REG};
    val1 = get_value(args[0], pos, champion, global);
    pos += get_len(args[0]);
    val2 = get_value(args[1], pos, champion, global);
    pos += get_len(args[1]);
    index_reg = (champion->params[pos] & 0xff) - 1;
    res = val1 & val2;
    champion->regs[index_reg] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc = (get_arena_adress(champion->pc + 2 + get_len(args[0]) + \
        get_len(args[1]) + 1));
}
