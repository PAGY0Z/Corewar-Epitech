/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_05_sub
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_05_sub.c
/// \brief Contains the exec_05_sub functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void exec_05_sub(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the sub instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_05_sub(UNUSED corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    int reg_index_one = (champion->params[2] & 0xff) - 1;
    int reg_index_two = (champion->params[3] & 0xff) - 1;
    int reg_index_three = (champion->params[4] & 0xff) - 1;
    int result = champion->regs[reg_index_one] - champion->regs[reg_index_two];
    champion->regs[reg_index_three] = result;
    champion->pc = get_arena_adress(champion->pc + 5);
}
