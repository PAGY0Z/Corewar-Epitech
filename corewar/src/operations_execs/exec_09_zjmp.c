/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exec_09_zjmp
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exec_09_zjmp.c
/// \brief Contains the exec_09_zjmp functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void exec_09_zjmp(corewar_t *global, champ_t *champion);

////////////////////////////////////////////////////////////////////////////////
/// \brief Executes the zjmp instruction.
/// \param global A pointer to the global structure.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void exec_09_zjmp(UNUSED corewar_t *global, champ_t *champion)
{
    if (champion->pc == -1) return;
    short value_arg = get_short(champion->params, 1);

    if (champion->carry == 1)
        champion->pc = get_arena_adress(champion->pc + value_arg % IDX_MOD);
    else
        champion->pc = (champion->pc + 3);
}
