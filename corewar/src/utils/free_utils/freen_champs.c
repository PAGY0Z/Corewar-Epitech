/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** freen_champs
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file freen_champs.c
/// \brief Contains the freen functions of the champions functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

void freen_champs(champ_t **champ, int i);

////////////////////////////////////////////////////////////////////////////////
/// \brief Free n elements of the champions structure.
/// \param champ The champions structure.
/// \param i The number of champions.
////////////////////////////////////////////////////////////////////////////////
void freen_champs(champ_t **champ, int i)
{
    if (!champ) return;
    for (int j = 0; j < i; j++) {
        my_free(champ[j]->comment);
        my_free(champ[j]->name);
        my_free(champ[j]->regs);
        my_free(champ[j]->params);
        my_free(champ[j]);
    }
    my_free(champ);
}
