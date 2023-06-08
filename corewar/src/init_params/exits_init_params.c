/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exits_init_params
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exits_init_params.c
/// \brief Contains the exits_init_params function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-18-05
////////////////////////////////////////////////////////////////////////////////

void *e_init_params(params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the program and free the params structure.
/// \param params The params structure.
/// \return NULL.
////////////////////////////////////////////////////////////////////////////////
void *e_init_params(params_t *params)
{
    my_free(params);
    return NULL;
}
