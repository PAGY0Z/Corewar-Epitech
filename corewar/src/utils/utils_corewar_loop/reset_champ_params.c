/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** reset_champ_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file reset_champ_params.c
/// \brief Contains the reset_champ_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-26-05
////////////////////////////////////////////////////////////////////////////////

void reset_champ_params(champ_t *champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Resets the params of the champion.
/// \param champ A pointer to the champion structure.
////////////////////////////////////////////////////////////////////////////////
void reset_champ_params(champ_t *champ)
{
    for (int i = 0; i < 14; i++)
        champ->params[i] = 0;
}
