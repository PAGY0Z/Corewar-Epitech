/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_champs
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_champs.c
/// \brief Contains the free functions of the champions functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

void free_champs(champ_t **champ);

////////////////////////////////////////////////////////////////////////////////
/// \brief Free all the elements of the champions structure.
/// \param champ The champions structure.
////////////////////////////////////////////////////////////////////////////////
void free_champs(champ_t **champ)
{
    if (!champ) return;
    for (int i = 0; champ[i]; i++) {
        my_free(champ[i]->comment);
        my_free(champ[i]->name);
        my_free(champ[i]->regs);
        my_free(champ[i]->params);
        my_free(champ[i]);
    }
    my_free(champ);
}
