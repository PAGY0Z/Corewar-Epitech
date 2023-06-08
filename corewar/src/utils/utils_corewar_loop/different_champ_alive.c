/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** different_champ_alive
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file different_champ_alive.c
/// \brief Contains the different_champ_alive function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

bool different_champ_alive(corewar_t *global);

////////////////////////////////////////////////////////////////////////////////
/// \brief Checks if there is more than one champion alive.
/// \param global A pointer to the global structure.
/// \return true if there is more than one champion alive, false otherwise.
////////////////////////////////////////////////////////////////////////////////
bool different_champ_alive(corewar_t *global)
{
    int champ_alive = -1;
    if (!global) return false;
    for (int i = 0; global->champ[i]; i++) {
        if (global->champ[i]->pc == -1) continue;
        if (champ_alive == -1) champ_alive = global->champ[i]->prog_nbr;
        if (champ_alive != global->champ[i]->prog_nbr) return true;
    }
    return false;
}
