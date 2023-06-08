/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_corewar
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_corewar.c
/// \brief Contains the free_corewar functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-25-05
////////////////////////////////////////////////////////////////////////////////

void free_corewar(corewar_t *glob);

////////////////////////////////////////////////////////////////////////////////
/// \brief Free the corewar structure.
/// \param glob The corewar structure to free.
/// \return void
////////////////////////////////////////////////////////////////////////////////
void free_corewar(corewar_t *glob)
{
    if (!glob) return;
    my_free(glob->arena);
    free_champs(glob->champ);
    my_free(glob);
}
