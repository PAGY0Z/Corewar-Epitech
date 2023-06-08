/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_03_st
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_03_st.c
/// \brief Contains the exec_03_st functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void exec_03_st(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the st instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_03_st(corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    byte_t by_p = champion->params[1];
    int pos = 2; int val_or_idx = 0; int reg_content = 0;
    int args[] = {REG, get_type_p2(by_p)};
    reg_content = champion->regs[(champion->params[pos] & 0xff) - 1];
    pos += 1;
    val_or_idx = get_value(args[1], pos, champion, global);
    if (IS_REG(args[1])) {
        val_or_idx = (champion->params[pos] & 0xff) - 1;
        champion->regs[val_or_idx] = reg_content;
    } else {
        write_4b_mem(global, reg_content, get_arena_adress(champion->pc + \
            val_or_idx % IDX_MOD));
    }
    champion->pc = (get_arena_adress(champion->pc + 2 + 1 + get_len(args[1])));
}
