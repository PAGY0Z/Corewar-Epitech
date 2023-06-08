/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** update_champ_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file update_champ_params.c
/// \brief Contains the update_champ_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void update_champ_params(byte_t *arena, champ_t *champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Updates the params of the champion.
/// \param arena A pointer to the arena.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void update_champ_params(byte_t *arena, champ_t *champ)
{
    for (int j = 0; j < 14; j++)
        champ->params[j] = arena[get_arena_adress(champ->pc + j)];
}
