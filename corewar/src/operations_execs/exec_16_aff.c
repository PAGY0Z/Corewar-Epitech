/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_16_aff
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_16_aff.c
/// \brief Contains the exec_16_aff functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void exec_16_aff(UNUSED corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the aff instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_16_aff(UNUSED corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    int reg_index = (champion->params[2] & 0xff) - 1;
    my_printf("%c", (champion->regs[reg_index] % 256));
    champion->pc = get_arena_adress(champion->pc + 3);
}
