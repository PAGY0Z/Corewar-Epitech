/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_params_progs
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file freen_params_progs.c
/// \brief Contains the freen_params_progs function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-18-05
////////////////////////////////////////////////////////////////////////////////

void free_params_progs(params_progs_t **params_progs);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the params_progs_t structures.
/// \param params_progs The params_progs_t structures to free.
/// \note Returns if params_progs is NULL.
////////////////////////////////////////////////////////////////////////////////
void free_params_progs(params_progs_t **params_progs)
{
    if (!params_progs) return;
    for (int i = 0; params_progs[i]; i++) {
        my_free(params_progs[i]->prog_name);
        my_free(params_progs[i]);
        params_progs[i] = NULL;
    }
    my_free(params_progs);
}
