/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_11_sti
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_11_sti.c
/// \brief Contains the exec_11_sti functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void exec_11_sti(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the sti instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_11_sti(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    byte_t by_p = champion->params[1];
    int pos = 2; int val1 = 0; int val2 = 0;
    int reg_value = 0;
    int args[] = {REG, get_type_p2(by_p), get_type_p3(by_p)};
    reg_value = champion->regs[(champion->params[pos] & 0xff) - 1];
    pos += 1;
    val1 = get_value_mod(args[1], pos, champion, global);
    pos += get_len_mod(args[1]);
    val2 = get_value_mod(args[2], pos, champion, global);
    write_4b_mem(global, reg_value, champion->pc + (val1 + val2) % IDX_MOD);
    champion->pc = (get_arena_adress(champion->pc + 2 + 1 + \
        get_len_mod(args[1]) + get_len_mod(args[2])));
}
