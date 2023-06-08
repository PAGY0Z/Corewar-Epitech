/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** init_corewar
*/

#include "corewar_programm_header.h"

////////////////////////////////////////////////////////////////////////////////
/// \file init_corewar.c
/// \brief Contains the init_corewar function.
/// \authors PAGY0Z, Amdjadouxx, AxsOne, DarkCat974
/// \version 0.1
/// \date 2023-23-05
////////////////////////////////////////////////////////////////////////////////

corewar_t *init_corewar(params_t *param, int mall_v1, int mall_v2, int mall_v3);

////////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the corewar structure.
/// \param param The params structure.
/// \param mall_v1 The multiplier for the corewar structure.
/// \param mall_v2 The multiplier for the arena.
/// \param mall_v3 The multiplier for the champion.
/// \return The corewar structure.
/// \note The corewar structure is initialized with the params structure.
////////////////////////////////////////////////////////////////////////////////
corewar_t *init_corewar(params_t *param, int mall_v1, int mall_v2, int mall_v3)
{
    corewar_t *glob = NULL; int champ_nb = 0;
    if (!param) return NULL;
    if (!(glob = malloc(sizeof(corewar_t) * mall_v1))) return NULL;
    if (!(glob->arena = malloc(sizeof(byte_t) * MEM_SIZE * mall_v2))) {
        my_free(glob);
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++) glob->arena[i] = 0;
    champ_nb = param->prog_nbr;
    if (!(glob->champ = malloc(sizeof(champ_t *) * (champ_nb + 1) * mall_v3))) {
        my_free(glob->arena);
        my_free(glob);
        return NULL;
    }
    for (int i = 0; i <= champ_nb; i++) glob->champ[i] = NULL;
    glob->dump_nbr_cycles = param->dump_nbr_cycles; glob->nbr_champ = champ_nb;
    glob->current_cycle = 0; glob->last_alive = -1; glob->nbr_live = 0;
    glob->cycle_to_die = CYCLE_TO_DIE;
    return glob;
}
