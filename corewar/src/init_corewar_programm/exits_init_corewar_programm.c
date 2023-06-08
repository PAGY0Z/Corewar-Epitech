/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** exits_init_corewar_programm
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file exits_init_corewar_programm.c
/// \brief Contains the exits functions of the init_corewar_programm functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

int e_init_struct(params_t *params);
int e_init_champs(corewar_t *glob, params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_corewar_programm function. From the struct Init.
/// \param params The params structure.
/// \return ERR_OUT.
/// \note Free the structure as it is the first element to be allocated.
////////////////////////////////////////////////////////////////////////////////
int e_init_struct(params_t *params)
{
    my_free(params);
    return ERR_OUT;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Exit the init_corewar_programm function. From the champs Init.
/// \param glob The corewar structure.
/// \param params The params structure.
/// \return ERR_OUT.
/// \note Free the structure as it is the second element to be allocated.
////////////////////////////////////////////////////////////////////////////////
int e_init_champs(corewar_t *glob, params_t *params)
{
    my_free(glob->arena);
    my_free(glob);
    free_params(params);
    return ERR_OUT;
}
