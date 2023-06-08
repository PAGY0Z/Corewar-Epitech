/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_corewar_programm
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_corewar_programm.c
/// \brief Contains the init_corewar_programm functions.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-22-05
////////////////////////////////////////////////////////////////////////////////

int init_corewar_programm(params_t *params);

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the corewar structure.
/// \param params The program's parameters.
/// \return The corewar structure.
/// \note Initializes the corewar structure :
/// \note   - Allocates the corewar structure.
/// \note   - Initializes the global.
/// \note   - Initializes the champions.
////////////////////////////////////////////////////////////////////////////////
int init_corewar_programm(params_t *params)
{
    corewar_t *glob = NULL;
    if (!params) return ERR_OUT;
    if (!(glob = init_corewar(params, 1, 1, 1))) return e_init_struct(params);
    if (!(init_champs(glob, params))) return e_init_champs(glob, params);
    free_params(params);
    return corewar_loop(glob);
}
