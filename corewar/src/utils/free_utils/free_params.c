/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** free_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file free_params.c
/// \brief Contains the free_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-19-05
////////////////////////////////////////////////////////////////////////////////

void free_params(params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Frees the params_t structure.
/// \param params The params_t structure to free.
/// \note Returns if params_progs is NULL.
////////////////////////////////////////////////////////////////////////////////
void free_params(params_t *params)
{
    if (!params) return;
    free_params_progs(params->progs);
    my_free(params);
}
